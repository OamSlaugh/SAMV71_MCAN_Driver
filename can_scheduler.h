/* 
 * File:   can_scheduler.h
 * Author: Noah
 *
 * Created on February 4, 2022, 7:08 PM
 */

#ifndef CAN_SCHEDULER_H
#define	CAN_SCHEDULER_H

#ifdef	__cplusplus
extern "C" {
#endif
  
#include "mcan_driver.h"
#include "f350_hscan_messages.h"

void can_scheduler_init(int channel);
void can_scheduler_periodic(void);
int can_scheduler_addMsg(msg_hscan_generic_S* p_msg);


#ifdef	__cplusplus
}
#endif

#endif	/* CAN_SCHEDULER_H */

