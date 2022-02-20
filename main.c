/* 
 * File:   main.c
 * Author: Noah
 *
 * Created on January 24, 2022, 8:41 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "samv71q21b.h"
#include "mcan_driver.h"
#include "f350_hscan_messages.h"
#include "can_scheduler.h"
#include "can_logic.h"

int main(void);
void start_clock(void);


void start_clock(void)
{
    PMC_REGS->CKGR_MOR = CKGR_MOR_KEY(0x37) | CKGR_MOR_MOSCXTEN(1) | CKGR_MOR_MOSCXTST(2);
    
    while(!(PMC_REGS->PMC_SR & PMC_SR_MOSCXTS_Msk))
    {}
    
    PMC_REGS->CKGR_MOR |= CKGR_MOR_KEY(0x37) | CKGR_MOR_MOSCSEL(1);
    
    while(!(PMC_REGS->PMC_SR & PMC_SR_MOSCSELS_Msk))
    {}
    
    PMC_REGS->CKGR_UCKR |= CKGR_UCKR_UPLLEN(1);
    while(!(PMC_REGS->PMC_SR & PMC_SR_LOCKU(1)))
    {
        
    }
    while(!(PMC_REGS->PMC_SR & PMC_SR_MCKRDY(1)))
    {
        
    }
    PMC_REGS->PMC_MCKR = PMC_MCKR_PRES_CLK_16 | PMC_MCKR_CSS_MAIN_CLK;
    while(!(PMC_REGS->PMC_SR & PMC_SR_MCKRDY(1)))
    {
        
    }
    PMC_REGS->PMC_MCKR = PMC_MCKR_CSS_UPLL_CLK | PMC_MCKR_PRES_CLK_16;
}


int main(void)
{
    //Disable the watchdog
    WDT_REGS->WDT_MR |= WDT_MR_WDDIS(1);
    
    start_clock();
    
    //mcan_driverReset();
    mcan_init(1);
    
    can_logic_init(1);
    
    while(1)
    {
        can_logic_periodic();
    }
    
    return (EXIT_SUCCESS);
}

