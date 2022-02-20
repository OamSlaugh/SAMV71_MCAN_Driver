
#include "samv71q21b.h"
#include "can_scheduler.h"
#include "mcan_driver.h"
#include "f350_hscan_messages.h"

#include <stdlib.h>


void can_timer_init(void);
void can_sendCyclic(uint32_t cycle_ms);

int scheduler_1ms_tick;
int scheduler_10ms_tick;

int sched_channel;

#define TX_ARRAY_LEN 28 
msg_hscan_generic_S** p_messages;
int msg_idx;

void can_timer_init(void)
{
    scheduler_1ms_tick = 0;
    scheduler_10ms_tick = 0;
    msg_idx = 0;
    
    NVIC_EnableIRQ(23);
    
    PMC_REGS->PMC_PCK[7] = PMC_PCK_PRES(1) | PMC_PCK_CSS_MCK;
    PMC_REGS->PMC_SCER |= PMC_SCER_PCK7(1);
    
    PMC_REGS->PMC_PCER0 |= PMC_PCER0_PID23(1);
    
    TC0_REGS->TC_CHANNEL[0].TC_CMR = TC_CMR_WAVEFORM_WAVSEL_UP_RC | TC_CMR_WAVE(1) | TC_CMR_TCCLKS_TIMER_CLOCK3;
    TC0_REGS->TC_CHANNEL[0].TC_RC = 937;
    TC0_REGS->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN(1);
    TC0_REGS->TC_CHANNEL[0].TC_CCR |= TC_CCR_SWTRG(1);
    
    TC0_REGS->TC_CHANNEL[0].TC_IER |= TC_IER_CPCS(1);
}

void can_scheduler_init(int channel)
{
    sched_channel = channel;
    can_timer_init();
    
    p_messages = malloc(sizeof(msg_hscan_generic_S*) * TX_ARRAY_LEN);
    for(int i = 0; i < TX_ARRAY_LEN; i++)
        p_messages[i] = 0;
}

int can_scheduler_addMsg(msg_hscan_generic_S* p_msg)
{
    int val;
    
    if(msg_idx >= TX_ARRAY_LEN)
        return -1;

    val = mcan_addToTxBuff(sched_channel, (msg_hscan_generic_S*)p_msg);
    
    if(val < 0)
    {
        p_msg->buff_idx = 0;
    }
    
    p_msg->buff_idx = val;
    
    p_messages[msg_idx] = p_msg;
    msg_idx++;
    
    return 0;
}

void can_scheduler_periodic(void)
{
    if(scheduler_1ms_tick >= 10)
    {
        scheduler_1ms_tick = 0;
        scheduler_10ms_tick++;
        
        //Run 10ms messages
        can_sendCyclic(10);

        if(scheduler_10ms_tick % 2 == 0)
        {
            //Run 20ms messages
            can_sendCyclic(20);
        }
        
        if(scheduler_10ms_tick % 5 == 0)
        {
            //Run 50ms messages
            can_sendCyclic(50);
        }
        
        if(scheduler_10ms_tick % 10 == 0)
        {
            //Run 100ms messages
            can_sendCyclic(100);
        }
            
        if(scheduler_10ms_tick >= 50)
        {
            scheduler_10ms_tick = 0;
            
            //Run 500ms messages
            can_sendCyclic(500);
        }
    }
}

void can_sendCyclic(uint32_t cycle_ms)
{
    for(int i = 0; i < TX_ARRAY_LEN; i++)
    {
        if(p_messages[i] != 0)
        {
            if(p_messages[i]->cycle_ms == cycle_ms)
            {
                //Transmit
                //int val;    
                
                //val = mcan_addToTxQueue(sched_channel, (msg_hscan_generic_S*)p_messages[i]);
                //if(val >= 0)
                //    mcan_sendFromQueue(sched_channel, val);
                mcan_sendFromBuff(sched_channel, p_messages[i]->buff_idx);
            }
        }
    }
}

void TC0_CH0_Handler(void)
{
    if(TC0_REGS->TC_CHANNEL[0].TC_SR & TC_SR_CPCS_Msk)
        scheduler_1ms_tick++;
}
