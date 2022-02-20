/* 
 * File:   can.h
 * Author: Noah
 *
 * Created on January 29, 2022, 5:55 PM
 */

#ifndef CAN_MESSAGES_H
#define	CAN_MESSAGES_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcan_driver.h"
    
typedef struct
{
    uint32_t ID;
    union
    {
        struct
        {
            uint8_t : 1;
            uint8_t ign_stable : 2;
            uint8_t : 1;
            uint8_t ign_status : 4;
            
            uint8_t : 3;
            uint8_t key_status : 2;
            uint8_t : 3;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BodyInfo3;

enum
{
    IGN_UNKNOWN = 0,
    IGN_OFF = 1,
    IGN_RUN = 4
}ignition_status_E;

enum
{
    KEY_OUT = 0,
    KEY_IN = 1,
    KEY_UNKNOWN = 3
}key_status_E;


#ifdef	__cplusplus
}
#endif

#endif	/* CAN_MESSAGES_H */

