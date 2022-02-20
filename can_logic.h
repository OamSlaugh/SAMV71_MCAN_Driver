/* 
 * File:   can_logic.h
 * Author: Noah
 *
 * Created on February 4, 2022, 8:26 PM
 */

#ifndef CAN_LOGIC_H
#define	CAN_LOGIC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcan_driver.h"
    
void can_logic_init(int channel);
void can_logic_periodic(void);

void set_turbo_pressure(uint32_t pressure);
void set_veh_speed(uint32_t speed);
void set_eng_rpm(uint32_t rpm);

#ifdef	__cplusplus
}
#endif

#endif	/* CAN_LOGIC_H */

