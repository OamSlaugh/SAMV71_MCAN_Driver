/* 
 * File:   mcan_driver.h
 * Author: Noah
 *
 * Created on January 26, 2022, 8:32 PM
 */

#ifndef MCAN_DRIVER_H
#define	MCAN_DRIVER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define MCAN_HSCAN_CHANNEL 1
    
typedef struct
{
    union
    {
        struct
        {
            uint32_t ID : 29;
            uint32_t RTR : 1;
            uint32_t XTD : 1;
            uint32_t ESI : 1;
            
            uint32_t : 16;
            uint32_t DLC : 4;
            uint32_t : 12;
        }bits;
        uint32_t header[2];
    };
    uint8_t data[8];
}mcan_tx_buff_8_S;

typedef struct
{
    union
    {
        struct
        {
            uint32_t SFID2 : 11;
            uint32_t : 5;
            uint32_t SFID1 : 11;
            uint32_t SFEC : 3;
            uint32_t SFT : 2;
        }bits;
        uint32_t data;
    };
}mcan_std_filt_S;

typedef struct
{
    uint32_t ID;
    uint8_t data[8];
}can_frame_S;

typedef enum
{
    MCAN_SUCCESS = 0,
    MCAN_ERR_GENERAL = -1,
    MCAN_ERR_CH_IDX = -2,
    MCAN_ERR_PTR = -3,
    MCAN_ERR_BUFF_FULL = -4,
    MCAN_ERR_PENDING = -5
}mcan_errors_E;

typedef enum
{
    BAUD_500KBPS = 0
}mcan_baud_E;

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    uint8_t data[8];
}msg_hscan_generic_S;

//void mcan_driverReset(void);
int mcan_init(int channel);
void mcan_periodic(void);
int mcan_addToTxBuff(int channel, msg_hscan_generic_S* p_element);
int mcan_addToTxQueue(int channel, msg_hscan_generic_S* p_element);
int mcan_sendFromBuff(int channel, uint32_t idx);
int mcan_sendFromQueue(int channel, uint32_t idx);
int mcan_setBaud(int channel, mcan_baud_E baud);
int mcan_addStdFilt(int channel, mcan_std_filt_S* p_element);
int mcan_updateBufferData(int channel, int idx, uint8_t* data);


#ifdef	__cplusplus
}
#endif

#endif	/* MCAN_DRIVER_H */

