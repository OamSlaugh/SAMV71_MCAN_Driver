
#include "samv71q21b.h"
#include "mcan_driver.h"
#include <stdlib.h>

uint32_t* p_mcan1_ram;

typedef struct
{
    uint32_t active; 
    uint32_t* p_msg_ram;
    
    mcan_registers_t* mcan_regs;
    
    uint32_t std_filt_count;
    uint32_t std_filt_occupancy;
    mcan_std_filt_S* p_std_filt;
    
    uint32_t tx_buff_count;
    uint32_t tx_queue_count;
    uint32_t tx_buff_occupancy;
    mcan_tx_buff_8_S* p_tx_buff;
}mcan_channel_data_S;


#define CLUSTER_OUTPUT_ID 0x430

#define MCAN_CHANNEL_COUNT 2

mcan_channel_data_S p_ch_data[2];

/*void mcan_driverReset(void)
{
    if(p_ch_data != 0)
        free(p_ch_data);
    
    p_ch_data = calloc(MCAN_CHANNEL_COUNT, sizeof(mcan_channel_data_S));
}*/

int mcan_init(int channel)
{
    uint32_t ram_size = 0;
    
    if(channel != 0 && channel != 1)
        return MCAN_ERR_CH_IDX;
    
    //Set core clock to use 480MHz PLL / 12 = 40MHz
    PMC_REGS->PMC_PCK[5] = (PMC_PCK_PRES(11) | PMC_PCK_CSS_UPLL_CLK);
    PMC_REGS->PMC_SCER |= PMC_SCER_PCK5(1);
    PMC_REGS->PMC_PCER1 |= PMC_PCER1_PID37(1);
    
    p_ch_data[channel].std_filt_count = 4;
    p_ch_data[channel].tx_buff_count = 28;
    p_ch_data[channel].tx_queue_count = 4;
    
    ram_size = p_ch_data[channel].std_filt_count * sizeof(mcan_std_filt_S);
    ram_size += p_ch_data[channel].tx_buff_count * sizeof(mcan_tx_buff_8_S);
    
    p_ch_data[channel].p_msg_ram = malloc(ram_size);
    
    p_ch_data[channel].p_std_filt = (mcan_std_filt_S*)p_ch_data[channel].p_msg_ram;
    p_ch_data[channel].p_tx_buff = (mcan_tx_buff_8_S*)(p_ch_data[channel].p_std_filt + p_ch_data[channel].std_filt_count*sizeof(mcan_std_filt_S));
    
    if(channel == 1)
    {
        p_ch_data[channel].mcan_regs = MCAN1_REGS;
        
        //MATRIX_REGS->CCFG_SYSIO &= ~CCFG_SYSIO_CAN1DMABA_Msk;
        MATRIX_REGS->CCFG_SYSIO = ((uint32_t)p_ch_data[channel].p_msg_ram & 0xFFFF0000);
        
        PIOC_REGS->PIO_PDR |= (PIO_PER_P12(1) | PIO_PER_P14(1));
        PIOC_REGS->PIO_ABCDSR[0] &= !(PIO_ABCDSR_P12(1) | PIO_ABCDSR_P14(1));
        PIOC_REGS->PIO_ABCDSR[1] |= (PIO_ABCDSR_P12(1) | PIO_ABCDSR_P14(1));
    }
   

    p_ch_data[channel].mcan_regs->MCAN_CCCR = MCAN_CCCR_INIT(1);

    while(!(p_ch_data[channel].mcan_regs->MCAN_CCCR & MCAN_CCCR_INIT_Msk))
    {}

    p_ch_data[channel].mcan_regs->MCAN_CCCR |= MCAN_CCCR_CCE(1);

    p_ch_data[channel].mcan_regs->MCAN_SIDFC = MCAN_SIDFC_LSS(p_ch_data[channel].std_filt_count) | (((uint32_t)p_ch_data[channel].p_std_filt) & 0x0000FFFC);
    p_ch_data[channel].mcan_regs->MCAN_XIDFC = 0;
    
    p_ch_data[channel].mcan_regs->MCAN_TXBC = MCAN_TXBC_NDTB(p_ch_data[channel].tx_buff_count) | (((uint32_t)p_ch_data[channel].p_tx_buff) & 0x0000FFFC);
    p_ch_data[channel].mcan_regs->MCAN_TXBC |= MCAN_TXBC_TFQM(1) | MCAN_TXBC_TFQS(p_ch_data[channel].tx_queue_count); //Enable TX QUEUE
    p_ch_data[channel].mcan_regs->MCAN_TXESC = MCAN_TXESC_TBDS_8_BYTE;

    p_ch_data[channel].mcan_regs->MCAN_DBTP = MCAN_DBTP_DSJW(3) | MCAN_DBTP_DBRP(4) | MCAN_DBTP_DTSEG1(10) | MCAN_DBTP_DTSEG2(3);
    p_ch_data[channel].mcan_regs->MCAN_NBTP = MCAN_NBTP_NSJW(3) | MCAN_NBTP_NBRP(4) | MCAN_NBTP_NTSEG1(10) | MCAN_NBTP_NTSEG2(3);

    //p_ch_data[channel].mcan_regs->MCAN_CCCR &= ~MCAN_CCCR_INIT(1);
    p_ch_data[channel].mcan_regs->MCAN_CCCR = 0;
    
    while(p_ch_data[channel].mcan_regs->MCAN_CCCR & MCAN_CCCR_INIT_Msk)
    {
        
    }
    
    p_ch_data[channel].active = 1;
    
    return 0;
}

void mcan_periodic(void)
{
    for(int channel = 0; channel < MCAN_CHANNEL_COUNT; channel++)
    {
        if(!p_ch_data[channel].active)
            continue;
        
        uint32_t tx_complete = p_ch_data[channel].mcan_regs->MCAN_TXBTO;
        uint32_t status = p_ch_data[channel].mcan_regs->MCAN_PSR;
        if(tx_complete != 0)
        {
            PIOC_REGS->PIO_PER |= PIO_PER_P9_Msk;
            PIOC_REGS->PIO_OER |= PIO_OER_P9_Msk;
        }
        
        if(status & MCAN_PSR_BO_Msk)
        {
            PIOC_REGS->PIO_PER |= PIO_PER_P9_Msk;
            PIOC_REGS->PIO_OER |= PIO_OER_P9_Msk;
        }
    }
}

void copy_to_tx_buff(int channel, msg_hscan_generic_S* p_element, int idx)
{
    //Copy data from p_element to buffer
    p_ch_data[channel].p_tx_buff[idx].header[0] = 0;
    p_ch_data[channel].p_tx_buff[idx].header[1] = 0;
    
    p_ch_data[channel].p_tx_buff[idx].bits.ID = (p_element->ID << 18);
    p_ch_data[channel].p_tx_buff[idx].bits.DLC = 8;
    for(int i = 0; i < 8; i++)
    {
        p_ch_data[channel].p_tx_buff[idx].data[i] = p_element->data[i];
    }
}

int mcan_addToTxBuff(int channel, msg_hscan_generic_S* p_element)
{
    //if(channel >= MCAN_CHANNEL_COUNT)
    //    return MCAN_ERR_CH_IDX;
    
    int idx = 0;
    
    while(((1 << idx) & p_ch_data[channel].tx_buff_occupancy) != 0)
    {
        idx++;
        if(idx >= p_ch_data[channel].tx_buff_count)
            return MCAN_ERR_BUFF_FULL;
    }

    copy_to_tx_buff(channel, p_element, idx);

    //Mark this section of the buffer as occupied
    p_ch_data[channel].tx_buff_occupancy |= (1<<idx);

    return idx;
}

int mcan_addToTxQueue(int channel, msg_hscan_generic_S* p_element)
{
    if((p_ch_data[channel].mcan_regs->MCAN_TXFQS & MCAN_TXFQS_TFQF_Msk) != 0)
        return MCAN_ERR_BUFF_FULL;
    
    int idx;
    idx = (p_ch_data[channel].mcan_regs->MCAN_TXFQS & MCAN_TXFQS_TFQPI_Msk) >> MCAN_TXFQS_TFQPI_Pos;
    
    copy_to_tx_buff(channel, p_element, idx);
    
    return idx;
}

int mcan_updateBufferData(int channel, int idx, uint8_t* data)
{
    if(channel >= MCAN_CHANNEL_COUNT)
        return MCAN_ERR_CH_IDX;
    
    if(idx >= p_ch_data[channel].tx_buff_count)
        return MCAN_ERR_GENERAL;
    
    for(int i = 0; i < 8; i++)
    {
        p_ch_data[channel].p_tx_buff[idx].data[i] = data[i];
    }
    
    return MCAN_SUCCESS;
}

int mcan_addStdFilt(int channel, mcan_std_filt_S* p_element)
{
    if(channel >= MCAN_CHANNEL_COUNT)
        return MCAN_ERR_CH_IDX;
    
    int idx = 0;
    
    while(((1 << idx) & p_ch_data[channel].std_filt_occupancy) != 0)
    {
        idx++;
        if(idx >= p_ch_data[channel].std_filt_count)
            return MCAN_ERR_BUFF_FULL;
    }
    
    p_ch_data[channel].p_std_filt[idx].data = p_element->data;
    
    return idx;
}

int mcan_sendFromBuff(int channel, uint32_t idx)
{
    if(channel >= MCAN_CHANNEL_COUNT)
        return MCAN_ERR_CH_IDX;
    
    if(idx >= (p_ch_data[channel].tx_buff_count))
        return MCAN_ERR_GENERAL;
    
    if(!(p_ch_data[channel].tx_buff_occupancy & (1<<idx)))
        return MCAN_ERR_GENERAL;
    
    if(p_ch_data[channel].mcan_regs->MCAN_TXBRP & (1<<idx))
        return MCAN_ERR_PENDING;
    
    p_ch_data[channel].mcan_regs->MCAN_TXBAR |= (1<<idx);
    //p_ch_data[channel].tx_buff_occupancy &= ~(1<<idx);
    
    return MCAN_SUCCESS;
}

int mcan_sendFromQueue(int channel, uint32_t idx)
{
    if(channel >= MCAN_CHANNEL_COUNT)
        return MCAN_ERR_CH_IDX;
    
    if(idx >= (p_ch_data[channel].tx_buff_count + p_ch_data[channel].tx_queue_count))
        return MCAN_ERR_GENERAL;
    
    p_ch_data[channel].mcan_regs->MCAN_TXBAR |= (1<<idx);
    
    return MCAN_SUCCESS;
}


int mcan_setBaud(int channel, mcan_baud_E baud)
{
    if(channel >= MCAN_CHANNEL_COUNT)
        return MCAN_ERR_CH_IDX;
    
    switch(baud)
    {
        case BAUD_500KBPS:
        default:
            p_ch_data[channel].mcan_regs->MCAN_DBTP = MCAN_DBTP_DSJW(3) | MCAN_DBTP_DBRP(4) | MCAN_DBTP_DTSEG1(10) | MCAN_DBTP_DTSEG2(3);
            p_ch_data[channel].mcan_regs->MCAN_NBTP = MCAN_NBTP_NSJW(3) | MCAN_NBTP_NBRP(4) | MCAN_NBTP_NTSEG1(10) | MCAN_NBTP_NTSEG2(3);
            break;
    }
    
    return MCAN_SUCCESS;
}


