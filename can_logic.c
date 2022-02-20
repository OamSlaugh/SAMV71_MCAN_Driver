
#include "f350_hscan_messages.h"
#include "can_logic.h"
#include "can_scheduler.h"

msg_BodyInfo2_S BodyInfo2;
msg_BodyInfo3_S BodyInfo3;
msg_AllTerrainData_S AllTerrainData;
msg_PowertrainData1_S PowertrainData1;
msg_EngineData1_S EngineData1;
msg_EngineData6_S EngineData6;
msg_TransGearData_S TransGearData;
msg_BrakeSysFeatures_S BrakeSysFeatures;
msg_TrailerBrakeInfo_S TrailerBrakeInfo;
msg_TirePressureStatus_S TirePressureStatus;
msg_TirePressureData_S TirePressureData;
msg_RCMStatusMessage_S RCMStatusMessage;
msg_BCMToHSBody_S BCMToHSBody;
msg_Information4x4_S Information4x4;
msg_BatteryMgmt2_S BatteryMgmt2;
msg_DieselData_S DieselData;

msg_EngineData3_S EngineData3;
msg_EngineData7_S EngineData7;
msg_EngVehSpThrottle_S EngVehSpThrottle;


void init_messages(void)
{
    BodyInfo2.ID = CAN_ID_BODY_INFO_2;
    BodyInfo2.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        BodyInfo2.data[i] = 0;
    BodyInfo2.signals.drv_dr_stat = DOOR_CLOSED;
    BodyInfo2.signals.hood_stat = DOOR_CLOSED;
    BodyInfo2.signals.psngr_dr_stat = DOOR_CLOSED;
    BodyInfo2.signals.rl_dr_stat = DOOR_CLOSED;
    BodyInfo2.signals.rr_dr_stat = DOOR_CLOSED;
    BodyInfo2.signals.tgate_innr_stat = DOOR_CLOSED;
    BodyInfo2.signals.tgate_stat = DOOR_CLOSED;
    
    BodyInfo3.ID = CAN_ID_BODY_INFO_3;
    BodyInfo3.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        BodyInfo3.data[i] = 0;
    BodyInfo3.signals.ign_stable = 1;
    BodyInfo3.signals.ign_status = IGN_RUN;
    BodyInfo3.signals.key_status = KEY_IN;
    BodyInfo3.signals.prk_brk_status = 1;
    BodyInfo3.signals.prk_lamp_status = 1;
    BodyInfo3.signals.day_night_status = 1;
    BodyInfo3.signals.dimming_lvl = 12;
    
    
    AllTerrainData.ID = CAN_ID_ALL_TERRAIN_DATA;
    AllTerrainData.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        AllTerrainData.data[i] = 0;
    
    PowertrainData1.ID = CAN_ID_POWERTRAIN_DATA_1;
    PowertrainData1.cycle_ms = 100;
    for(int i = 0; i < 8; i++)
        PowertrainData1.data[i] = 0;
    PowertrainData1.signals.mil_req = MIL_OFF;
    PowertrainData1.signals.oil_pressure = OIL_PRESSURE_NORMAL;
    
    EngineData1.ID = CAN_ID_ENGINE_DATA_1;
    EngineData1.cycle_ms = 20;
    for(int i = 0; i < 8; i++)
        EngineData1.data[i] = 0;
    //EngineData1.signals.turbo_boost = 0;
    EngineData1.data[6] = 0x00;
    EngineData1.data[7] = 0x80;
    
    EngineData6.ID = CAN_ID_ENGINE_DATA_6;
    EngineData6.cycle_ms = 100;
    for(int i = 0; i < 8; i++)
        EngineData6.data[i] = 0;
    EngineData6.signals.coolant_temp = 160;
    EngineData6.signals.coolant_temp_qf = 3;
    //EngineData6.signals.oil_temp = 160;
    
    TransGearData.ID = CAN_ID_TRANS_GEAR_DATA;
    TransGearData.cycle_ms = 100;
    for(int i = 0; i < 8; i++)
        TransGearData.data[i] = 0;
    TransGearData.signals.oil_temp = 160;
    
    BrakeSysFeatures.ID = CAN_ID_BRAKE_SYS_FEATURES;
    BrakeSysFeatures.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        BrakeSysFeatures.data[i] = 0;
    
    TrailerBrakeInfo.ID = CAN_ID_TRAILER_BRAKE_INFO;
    TrailerBrakeInfo.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        TrailerBrakeInfo.data[i] = 0;
    
    TirePressureStatus.ID = CAN_ID_TIRE_PRESSURE_STATUS;
    TirePressureStatus.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        TirePressureStatus.data[i] = 0;
    
    TirePressureData.ID = CAN_ID_TIRE_PRESSURE_DATA;
    TirePressureData.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        TirePressureData.data[i] = 0;
    
    RCMStatusMessage.ID = CAN_ID_RCM_STATUS_MESSAGE;
    RCMStatusMessage.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        RCMStatusMessage.data[i] = 0;
    RCMStatusMessage.signals.seat_belt_light = 0;
    
    BCMToHSBody.ID = CAN_ID_BCM_TO_HS_BODY;
    BCMToHSBody.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        BCMToHSBody.data[i] = 0;
    
    Information4x4.ID = CAN_ID_INFORMATION_4X4;
    Information4x4.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        Information4x4.data[i] = 0;
    
    BatteryMgmt2.ID = CAN_ID_BATTERY_MGMT_2;
    BatteryMgmt2.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        BatteryMgmt2.data[i] = 0;
    
    DieselData.ID = CAN_ID_DIESEL_DATA;
    DieselData.cycle_ms = 500;
    for(int i = 0; i < 8; i++)
        DieselData.data[i] = 0;
    //DieselData.data[0] = 0x01;
    //DieselData.data[1] = 0xFF;
    set_turbo_pressure(500);
    
    EngineData3.ID = CAN_ID_ENGINE_DATA_3;
    EngineData3.cycle_ms = 20;
    for(int i = 0; i < 8; i++)
        EngineData3.data[i] = 0;
    
    EngineData7.ID = CAN_ID_ENGINE_DATA_7;
    EngineData7.cycle_ms = 100;
    for(int i = 0; i < 8; i++)
        EngineData7.data[i] = 0;
    EngineData7.data[4] = 90;
    
    EngVehSpThrottle.ID = CAN_ID_ENG_VEH_SP_THROTTLE;
    EngVehSpThrottle.cycle_ms = 100;
    for(int i = 0; i < 8; i++)
        EngVehSpThrottle.data[i] = 0;
    //EngVehSpThrottle.data[0] = 10;
    //EngVehSpThrottle.data[1] = 3;
    set_eng_rpm(500);
    //EngVehSpThrottle.data[1] |= 0x03;
    //EngVehSpThrottle.data[2] = 0x27;
    //EngVehSpThrottle.data[3] = 0x10;
    set_veh_speed(0);
    
    
    can_scheduler_addMsg((msg_hscan_generic_S*)&BodyInfo2);
    can_scheduler_addMsg((msg_hscan_generic_S*)&BodyInfo3);
    can_scheduler_addMsg((msg_hscan_generic_S*)&AllTerrainData);
    can_scheduler_addMsg((msg_hscan_generic_S*)&PowertrainData1);
    can_scheduler_addMsg((msg_hscan_generic_S*)&EngineData1);
    can_scheduler_addMsg((msg_hscan_generic_S*)&EngineData6);
    can_scheduler_addMsg((msg_hscan_generic_S*)&TransGearData);
    can_scheduler_addMsg((msg_hscan_generic_S*)&BrakeSysFeatures);
    can_scheduler_addMsg((msg_hscan_generic_S*)&TrailerBrakeInfo);
    can_scheduler_addMsg((msg_hscan_generic_S*)&TirePressureStatus);
    can_scheduler_addMsg((msg_hscan_generic_S*)&TirePressureData);
    can_scheduler_addMsg((msg_hscan_generic_S*)&RCMStatusMessage);
    can_scheduler_addMsg((msg_hscan_generic_S*)&BCMToHSBody);
    can_scheduler_addMsg((msg_hscan_generic_S*)&Information4x4);
    can_scheduler_addMsg((msg_hscan_generic_S*)&BatteryMgmt2);
    can_scheduler_addMsg((msg_hscan_generic_S*)&DieselData);
    can_scheduler_addMsg((msg_hscan_generic_S*)&EngineData3);
    can_scheduler_addMsg((msg_hscan_generic_S*)&EngineData7);
    can_scheduler_addMsg((msg_hscan_generic_S*)&EngVehSpThrottle);
}

void can_logic_init(int channel)
{
    can_scheduler_init(channel);
    
    init_messages();
}

void can_logic_periodic(void)
{
    can_scheduler_periodic();
}

void set_turbo_pressure(uint32_t pressure)
{
    DieselData.signals.turbo_psi_H2 = ((pressure >> 8) & 0x03);
    DieselData.signals.turbo_psi_L8 = (pressure & 0x00FF);
}

void set_veh_speed(uint32_t speed)
{
    EngVehSpThrottle.signals.veh_speed_qf = 0x03;
    EngVehSpThrottle.signals.veh_speed_H8 = ((speed >> 8) & 0x00FF);
    EngVehSpThrottle.signals.veh_speed_L8 = (speed & 0x00FF);
}

void set_eng_rpm(uint32_t rpm)
{
    EngVehSpThrottle.signals.eng_rpm_H8 = ((rpm >> 5) & 0x00FF);
    EngVehSpThrottle.signals.eng_rpm_L5 = (rpm & 0x001F);
}
