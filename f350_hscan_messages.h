/* 
 * File:   f350_hscan_messages.h
 * Author: Noah
 *
 * Created on February 4, 2022, 6:55 PM
 */

#ifndef F350_HSCAN_MESSAGES_H
#define	F350_HSCAN_MESSAGES_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdint.h>

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 1;
            uint8_t tgate_stat : 1;
            uint8_t rr_dr_stat : 1;
            uint8_t rl_dr_stat : 1;
            uint8_t psngr_dr_stat : 1;
            uint8_t tgate_innr_stat : 1;
            uint8_t hood_stat : 1;
            uint8_t drv_dr_stat : 1;
            
            uint8_t : 8;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BodyInfo2_S;
#define CAN_ID_BODY_INFO_2 0x3AE

typedef enum
{
    DOOR_CLOSED = 0,
    DOOR_OPEN = 1
}door_state_E;

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t ign_stable : 2;
            uint8_t prk_lamp_status : 2;
            uint8_t ign_status : 4;
            
            uint8_t : 2;
            uint8_t key_status : 2;
            uint8_t : 2;
            uint8_t day_night_status : 2;
            
            uint8_t : 8;
            
            uint8_t dimming_lvl : 8;
            
            uint8_t : 8;
            uint8_t : 8;
            
            uint8_t : 7;
            uint8_t prk_brk_status : 1;
            
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BodyInfo3_S;
#define CAN_ID_BODY_INFO_3 0x3B3

typedef enum
{
    IGN_UNKNOWN = 0,
    IGN_OFF = 1,
    IGN_RUN = 4
}ignition_status_E;

typedef enum
{
    KEY_OUT = 0,
    KEY_IN = 1,
    KEY_UNKNOWN = 3
}key_status_E;


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t hdc_sw_pos : 1;
            uint8_t terr_mode_req : 3;        
            uint8_t terr_stat_display: 4;
            
            uint8_t : 8;            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_AllTerrainData_S;
#define CAN_ID_ALL_TERRAIN_DATA 0x480


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 8;
            
            uint8_t : 1;
            uint8_t mil_req : 2;
            uint8_t : 5;
            
            uint8_t : 2;
            uint8_t oil_pressure : 1;
            uint8_t : 5;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_PowertrainData1_S;
#define CAN_ID_POWERTRAIN_DATA_1 0x420

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 8;
            
            uint8_t : 8;
            
            uint8_t : 8;
            
            uint8_t : 8;
            
            uint8_t : 7;
            uint8_t coolant_temp : 8;
            
            uint8_t : 1;
            
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_PowertrainData2_S;
#define CAN_ID_POWERTRAIN_DATA_2 0x422

typedef enum
{
    MIL_OFF = 0,
    MIL_ON = 1,
    MIL_FLASH = 2
}mil_light_E;

typedef enum
{
    OIL_PRESSURE_NORMAL = 0,
    OIL_PRESSURE_LOW = 1
}oil_light_E;

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t coolant_temp : 8;
            uint32_t oil_temp : 8;            
            uint32_t : 8;
            
            uint32_t : 8;
            
            uint32_t coolant_temp_qf : 2;
            uint32_t : 6;
            
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_EngineData6_S;
#define CAN_ID_ENGINE_DATA_6 0x156

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;     
            uint8_t : 8;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_TirePressureStatus_S;
#define CAN_ID_TIRE_PRESSURE_STATUS 0x3B4

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;     
            uint8_t : 8;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_TirePressureData_S;
#define CAN_ID_TIRE_PRESSURE_DATA 0x3B5


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;     
            uint8_t : 8;
            
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
            uint8_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_TractionCtrlStatus_S;
#define CAN_ID_TRACTION_CTRL_STATUS 0x417


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;     
            uint32_t oil_temp : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_TransGearData_S;
#define CAN_ID_TRANS_GEAR_DATA 0x230

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t turbo_boost : 16;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_EngineData1_S;
#define CAN_ID_ENGINE_DATA_1 0x151

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BrakeSysFeatures_S;
#define CAN_ID_BRAKE_SYS_FEATURES 0x415

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_TrailerBrakeInfo_S;
#define CAN_ID_TRAILER_BRAKE_INFO 0x445

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            
            uint32_t : 1;
            uint32_t seat_belt_light : 1;
            uint32_t : 6;
            
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            
            uint32_t : 4;
            uint32_t buckle_psngr : 2;
            uint32_t buckle_drvr : 2;
            
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_RCMStatusMessage_S;
#define CAN_ID_RCM_STATUS_MESSAGE 0x340

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BCMToHSBody_S;
#define CAN_ID_BCM_TO_HS_BODY 0x3C3

typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_Information4x4_S;
#define CAN_ID_INFORMATION_4X4 0x260


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_BatteryMgmt2_S;
#define CAN_ID_BATTERY_MGMT_2 0x42C


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t turbo_psi_H2 : 2;
            uint32_t : 6;
            
            uint32_t turbo_psi_L8 : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_DieselData_S;
#define CAN_ID_DIESEL_DATA 0x407


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_EngineData3_S;
#define CAN_ID_ENGINE_DATA_3 0x154


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;                 
            uint32_t : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_EngineData7_S;
#define CAN_ID_ENGINE_DATA_7 0x159


typedef struct
{
    uint32_t ID;
    uint32_t cycle_ms;
    int buff_idx;
    
    union
    {
        struct
        {
            uint32_t eng_rpm_H8 : 8;
            
            uint32_t veh_speed_qf : 2;
            uint32_t : 1;
            uint32_t eng_rpm_L5 : 5;
            
            uint32_t veh_speed_H8 : 8;                 
            uint32_t veh_speed_L8 : 8;
            
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
            uint32_t : 8;
        }signals;
        uint8_t data[8];
    };
}msg_EngVehSpThrottle_S;
#define CAN_ID_ENG_VEH_SP_THROTTLE 0x201


#ifdef	__cplusplus
}
#endif

#endif	/* F350_HSCAN_MESSAGES_H */

