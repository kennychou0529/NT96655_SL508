/*
    System Power Callback

    System Callback for Power Module.

    @file       SysPower_Exe.c
    @ingroup    mIPRJSYS

    @note

    Copyright   Novatek Microelectronics Corp. 2010.  All rights reserved.
*/

////////////////////////////////////////////////////////////////////////////////
#include "SysCommon.h"
#include "AppCommon.h"
////////////////////////////////////////////////////////////////////////////////
#include "UIFrameworkExt.h"
#include "UICommon.h"
#include "AppLib.h"
#include "GxInput.h"
#include "DxPower.h"
#include "DxLens.h"
#include "GxFlash.h"
#include "GxPower.h"
#include "DbgUtApi.h"

#if (UI_STYLE==UI_STYLE_DRIVER)
#include "UsbDevDef.h"
#endif

//global debug level: PRJ_DBG_LVL
#include "PrjCfg.h"
//local debug level: THIS_DBGLVL
#define THIS_DBGLVL         1 //0=OFF, 1=ERROR, 2=TRACE
///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          SysPwrExe
#define __DBGLVL__          ((THIS_DBGLVL>=PRJ_DBG_LVL)?THIS_DBGLVL:PRJ_DBG_LVL)
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"
#include "UIFlowMovieFuncs.h"
#include "Rtc.h"
#include "Gsensor.h"

BOOL gbOpenWifiFunc=FALSE;
BOOL gbACCDetEn=TRUE;

int SX_TIMER_DET_SLEEP_ID = -1;
int SX_TIMER_DET_AUTOPOWEROFF_ID = -1;
int SX_TIMER_DET_BATT_ID = -1;
int SX_TIMER_DET_CHARGE_ID = -1;
int SX_TIMER_DET_SHOWADC = -1;
int SX_TIMER_DET_BATTINS_ID = -1;
int SX_TIMER_DET_ACC_ID = -1;
int SX_TIMER_DET_LED_STATUS_ID = -1;
int SX_TIMER_DET_GSENSOR_ID = -1;
int SX_TIMER_WATCHDOG_ID = -1;

void UI_DetAutoSleep(void);
void UI_DetAutoPoweroff(void);
void UI_DetBattery(void);
void UI_DetBatteryInsert(void);
void System_DetShowADC(void);
void System_DetACC(void);
void UI_DetLEDStatus(void);
void UI_DetGsensor(void);
void System_DetWatchDog(void);


#if (AUTOSLEEP_FUNCTION == ENABLE)
SX_TIMER_ITEM(GxPower_DetSleep, UI_DetAutoSleep, 50, TRUE)
#endif
#if (AUTOPWROFF_FUNCTION == ENABLE)
SX_TIMER_ITEM(GxPower_DetAutoPoweroff, UI_DetAutoPoweroff, 50, TRUE)
#endif
#if (PWRLEVEL_FUNCTION == ENABLE)
SX_TIMER_ITEM(GxPower_DetBattery, UI_DetBattery, 25, FALSE)
#endif
#if (USB_CHARGE_FUNCTION == ENABLE)
SX_TIMER_ITEM(GxPower_DetCharge, GxPower_DetCharge, 50, TRUE)
#endif
#if (SHOW_ADC_ON_SCREEN == ENABLE)
SX_TIMER_ITEM(System_DetShowADC, System_DetShowADC, 15, FALSE)
#endif
#if (USB_CHARGE_FUNCTION == ENABLE)
SX_TIMER_ITEM(GxPower_DetBatteryIns, UI_DetBatteryInsert, 25, TRUE)
#endif

SX_TIMER_ITEM(System_DetACC, System_DetACC, 1, FALSE)

SX_TIMER_ITEM(UI_DetLEDStatus, UI_DetLEDStatus, 50, TRUE)

SX_TIMER_ITEM(UI_DetGsensor, UI_DetGsensor, 1, FALSE)

SX_TIMER_ITEM(System_DetWatchDog, System_DetWatchDog, 4, TRUE)


#if (POWERON_TESTFLOW == ENABLE)
BOOL System_Is_USBPC_DeadBattery(void);
#endif

UINT32 DxPower_CB(UINT32 event, UINT32 param1, UINT32 param2)
{
    #if LENS_FUNCTION
    switch (event)
    {
        case DRVPWR_CB_IS_LENS_MOVING:
            return GxFlash_GetData(FLASH_SUSPEND_CALLER_CNT);
        case DRVPWR_CB_DUMMY_LOAD_START:
            {
                PMOTOR_TAB pMotorObj = motor_getObject();
                PLENS_DEVICE_OBJ pLensDevice =DrvLens_GetDevice();


                //first time,need to init motor dirver gpio
                pMotorObj->init(pLensDevice);
                pMotorObj->setSignal(MD_SIGNAL_STANDBY,ON);
                //Open shutter
                pMotorObj->shutter_setState(MOTOR_SHUTTER_DUMMYLOAD,SHUTTER_DUMMYLOAD_START);
            }
            return 0;
        case DRVPWR_CB_DUMMY_LOAD_END:
            {
                PMOTOR_TAB pMotorObj = motor_getObject();
                pMotorObj->shutter_setState(MOTOR_SHUTTER_DUMMYLOAD,SHUTTER_DUMMYLOAD_END);
                pMotorObj->setSignal(MD_SIGNAL_STANDBY,OFF);
            }
            return 0;
        default:
            DBG_ERR("event(%d)\r\n",event);
            return 0;

    }
    #else
    return 0;
    #endif
}

void System_OnPowerPreInit(void)
{
    // register DxPower Callback function
    DrvPower_RegCB(DxPower_CB);

#if (POWERON_TESTFLOW == ENABLE)
    gIsUSBChargePreCheck = System_Is_USBPC_DeadBattery();
#endif

    if(GxKey_GetData(GXKEY_NORMAL_KEY) & FLGKEY_UP)
        GxPower_SetControl(GXPWR_CTRL_IGNORE_BATT_CHECK, TRUE);
    else
        GxPower_SetControl(GXPWR_CTRL_IGNORE_BATT_CHECK, FALSE);
#if (POWERON_TESTFLOW == ENABLE)
    if(gIsUSBChargePreCheck)
        GxPower_SetControl(GXPWR_CTRL_IGNORE_BATT_CHECK, TRUE);
#else
    //GxPower_OnSystem(SYSTEM_CMD_POWERON); //Do Dummy Load
    GxPower_PowerON();
#endif

    #if _MIPS_TODO
    HwClock_EnablePowerAlarm(FALSE);
    #endif

    //If press up key, enter "Battery Calibration" mode.
    #if 0
    if(GxKey_GetData(GXKEY_NORMAL_KEY) & FLGKEY_UP)
    #else
    if(GxPower_GetControl(GXPWR_CTRL_IGNORE_BATT_CHECK))
    #endif
    {
        //"battery calibration" path
        DBG_IND("USER force to ignore low-battery check.\r\n");

        GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, FALSE);
    }
    else
    {
        //normal path
        DBG_IND("Start low-battery check (dummyload).\r\n");

        //if under low-battery condition
        if(!GxPower_DummyLoad())
        {
            System_SetState(SYS_STATE_POWERON, SYS_POWERON_LOWPOWER);
            System_SetState(SYS_STATE_POWEROFF, SYS_POWEROFF_LOWPOWER);
        }
        GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, TRUE);
    }
}

extern void Power_CB(UINT32 event, UINT32 param1, UINT32 param2);

void System_OnPowerInit(void)
{
    //PHASE-1 : Init & Open Drv or DrvExt
    {
    GxPower_RegCB(Power_CB);     //Register CB function of GxPower
    }
    //PHASE-2 : Init & Open Lib or LibExt
    {
    //1.設定init值
    //2.設定CB值,

    //3.註冊SxJob服務 ---------> System Job
    //4.註冊SxTimer服務 ---------> Detect Job
    #if (AUTOSLEEP_FUNCTION == ENABLE)
    SX_TIMER_DET_SLEEP_ID = SxTimer_AddItem(&Timer_GxPower_DetSleep);
    #endif
    #if (AUTOPWROFF_FUNCTION == ENABLE)
    SX_TIMER_DET_AUTOPOWEROFF_ID = SxTimer_AddItem(&Timer_GxPower_DetAutoPoweroff);
    #endif
    #if (PWRLEVEL_FUNCTION == ENABLE)
    SX_TIMER_DET_BATT_ID = SxTimer_AddItem(&Timer_GxPower_DetBattery);
    #endif
    #if (USB_CHARGE_FUNCTION == ENABLE)
    SX_TIMER_DET_CHARGE_ID = SxTimer_AddItem(&Timer_GxPower_DetCharge);
    #endif
    #if (SHOW_ADC_ON_SCREEN == ENABLE)
    SX_TIMER_DET_SHOWADC = SxTimer_AddItem(&Timer_System_DetShowADC);
    #endif
    #if (USB_CHARGE_FUNCTION == ENABLE)
    SX_TIMER_DET_BATTINS_ID = SxTimer_AddItem(&Timer_GxPower_DetBatteryIns);
    #endif
    SX_TIMER_DET_ACC_ID = SxTimer_AddItem(&Timer_System_DetACC);
    SX_TIMER_DET_LED_STATUS_ID = SxTimer_AddItem(&Timer_UI_DetLEDStatus);
    SX_TIMER_DET_GSENSOR_ID = SxTimer_AddItem(&Timer_UI_DetGsensor);

    SX_TIMER_WATCHDOG_ID = SxTimer_AddItem(&Timer_System_DetWatchDog);
	
    //5.註冊SxCmd服務 ---------> Cmd Function
    //GxPower_InstallCmd();
    //DbgUt_InstallCmd();
    }
}

void System_OnPowerExit(void)
{
    //PHASE-2 : Close Lib or LibExt
    {
    }
    //PHASE-1 : Close Drv or DrvExt
    {
    }
}

///////////////////////////////////////////////////////////////////////////////

#if (AUTOSLEEP_FUNCTION == ENABLE)
void UI_DetAutoSleep(void)
{
    if((!UI_IsForceLock()) && (!UI_IsForceLockAutoSleep()))
    {
        //debug_msg("DetAutoSleep\r\n");
        GxPower_DetSleep();
    }
}
#endif
#if (AUTOPWROFF_FUNCTION == ENABLE)
void UI_DetAutoPoweroff(void)
{
    if((!UI_IsForceLock()) && (!UI_IsForceLockAutoPWROff()))
    {
        GxPower_DetAutoPoweroff();
    }
}
#endif
#if (PWRLEVEL_FUNCTION == ENABLE)
void UI_DetBattery(void)
{
    if(!UI_IsForceLock())
    {
        //#NT#2012/10/23#Philex Lin - begin
        // send NVTEVT_BATTERY event to flash power charging icon in power charging mode
        #if (UI_STYLE==UI_STYLE_DRIVER)
         // power charging case
         if (GxUSB_GetConnectType() == USB_CONNECT_CHARGER)
         {
            Ux_PostEvent(NVTEVT_BATTERY, 0);
         } else {
            // normal battery detect case
            GxPower_DetBattery();
         }
        #else
        GxPower_DetBattery();
        #endif
        //#NT#2012/10/23#Philex Lin - end
    }
}
#endif
#if (USB_CHARGE_FUNCTION == ENABLE)
BOOL gIsBattInsert = TRUE;
BOOL gIsBattDead = FALSE;
void UI_DetBatteryInsert(void)
{
    if(!UI_IsForceLock())
    {
        BOOL bInsert;
        #if (USB_CHARGE_FUNCTION == ENABLE)
        bInsert = GxPower_GetControl(GXPWR_CTRL_IS_BATT_INSERT);
        #else
        bInsert = TRUE;
        #endif
        if(bInsert != gIsBattInsert)
        {
            gIsBattInsert = bInsert;
            debug_msg("  Battery Insert = %s\r\n", gIsBattInsert?"YES":"NO");
        }
    }
}
#endif
#if (SHOW_ADC_ON_SCREEN == ENABLE)
void System_DetShowADC(void)
{
    IRECT  StringRect = { 200, 162, 340, 40 };
    IRECT*  pRect = &StringRect;
    static char ADCStr[20];

    //UIDebug_Sys("aa  = %d\r\n",UI_GetData(UI_ShowADC));
    if (UI_GetData(UI_ShowADC) == TRUE)
    {
        DC**     pDCList;
        UI_SetDisplayDirty(TRUE); //set TRUE to force dirty current begin/end

        pDCList = (DC**)UI_BeginScreen();
        sprintf(ADCStr, "AD0-%ld,AD1-%ld,AD2-%ld", adc_readData(0), adc_readData(1),adc_readData(2));
        GxGfx_SetTextStroke((const FONT*)gDemo_Font, FONTSTYLE_NORMAL, SCALE_1X);
        GxGfx_SetTextColor(_OSD_INDEX_TRANSPART, _OSD_INDEX_TRANSPART, 0);
        GxGfx_FillRect(((DC**)pDCList)[GxGfx_OSD],pRect->uiLeft,pRect->uiTop,pRect->uiLeft+pRect->uiWidth,pRect->uiTop+pRect->uiHeight);
        GxGfx_SetShapeColor(_OSD_INDEX_TRANSPART, _OSD_INDEX_TRANSPART, 0);
        GxGfx_SetTextColor(_OSD_INDEX_RED, _OSD_INDEX_GRAY, 0);
        GxGfx_Text(((DC**)pDCList)[GxGfx_OSD], pRect->uiLeft, pRect->uiTop, ADCStr);
        UI_EndScreen((UINT32)pDCList);
    }

}
#endif


///////////////////////////////////////////////////////////////////////////////

INT32 System_OnBattChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_PostEvent(NVTEVT_BATTERY, 0);
    debug_msg("battery changed %d**********\r\n",GxPower_GetControl(GXPWR_CTRL_BATTERY_LEVEL));

    return NVTEVT_CONSUME;
}

INT32 System_OnBattEmpty(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    #if (EMPTYPWROFF_FUNCTION == ENABLE)
    {
        #if (UI_STYLE==UI_STYLE_DRIVER)
        // set battery low event to ui window
        Ux_PostEvent(NVTEVT_BATTERY_LOW, 0);
        #else
        System_PowerOff(SYS_POWEROFF_BATTEMPTY);
        #endif
    }
    #endif
    return NVTEVT_CONSUME;
}

INT32 System_OnPwrChargeOK(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);
    //GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,FALSE);
    //GxLED_SetCtrl(KEYSCAN_LED_GREEN,SET_TOGGLE_LED,FALSE);
   // GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);
    return NVTEVT_CONSUME;
}

INT32 System_OnPwrChargeSuspend(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
  //  GxLED_SetCtrl(KEYSCAN_LED_GREEN,SET_TOGGLE_LED,FALSE);
   // GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);
    //GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);
    //GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,FALSE);
    return NVTEVT_CONSUME;
}

INT32 System_OnPwrChargeResume(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);
    //GxLED_SetCtrl(KEYSCAN_LED_GREEN,SETLED_SPEED,GXLED_1SEC_LED_TOGGLE_CNT);
   // GxLED_SetCtrl(KEYSCAN_LED_GREEN,SET_TOGGLE_LED,TRUE);
    return NVTEVT_CONSUME;
}

void System_ResetPowerSaveCount(void)
{
    //reset auto power off and sleep counter
    #if (AUTOPWROFF_FUNCTION == ENABLE)
    GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_RESET,0);
    #endif
    #if (AUTOSLEEP_FUNCTION == ENABLE)
    GxPower_SetControl(GXPWR_CTRL_SLEEP_RESET,0);
    #endif
}

#if (USB_CHARGE_FUNCTION == ENABLE)
void Power_StartUSBCharge(void)
{
    if (!gIsBattInsert)
    {
        DBG_DUMP("  NO Battery, Ignore START\r\n");
        return;
    }

    if (GxPower_GetControl(GXPWR_CTRL_BATTERY_CHARGE_EN))
    {
        DBG_DUMP("  Already UNDER Charge, Ignore START\r\n");
        return;
    }

    if((USB_GetSource() == USB_SRC_USB_ADAPTER))
    {
        GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_CURRENT,BATT_CHARGE_CURRENT_HIGH);
        DBG_MSG("  Charge Current = %d\r\n", BATT_CHARGE_CURRENT_HIGH);
    }
#if _MIPS_TODO
    //#NT#2010/12/10#Jeah Yen -begin
    if((USB_GetSource() == USB_SRC_USB_ADAPTER) && (Power_GetSource() != POWER_SRC_USB_ADAPTER))
    {
        //Do not charge, just stop check low-battery
        DBG_DUMP("GxPower: Stop low-battery check.\r\n");
        GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, FALSE);
        return;
    }
    //#NT#2010/12/10#Jeah Yen -end
#endif
    //#NT#2010/12/10#Jeah Yen -begin
    if((USB_GetSource() == USB_SRC_USB_PC))
    {
        GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_CURRENT,BATT_CHARGE_CURRENT_MEDIUM);
        DBG_MSG("  Charge Current = %d\r\n", BATT_CHARGE_CURRENT_MEDIUM);
    }
    //#NT#2010/12/10#Jeah Yen -end

    //#NT#2010/12/10#Jeah Yen -begin
    DBG_DUMP("GxPower: Stop low-battery check.\r\n");
    GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, FALSE);
    DBG_DUMP("GxPower: Start to Charge Battery\r\n");
#if (USB_CHARGE_VERIFY == ENABLE)
   // GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);
#endif
    GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_EN,TRUE);
    //#NT#2010/12/10#Jeah Yen -end
#if (USB_CHARGE_VERIFY == ENABLE)
#else
    //GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);
#endif
    //GxLED_SetCtrl(KEYSCAN_LED_RED,SETLED_SPEED,GXLED_1SEC_LED_TOGGLE_CNT);
    //GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,TRUE);
  //  GxLED_SetCtrl(KEYSCAN_LED_GREEN,SETLED_SPEED,GXLED_1SEC_LED_TOGGLE_CNT);
  //  GxLED_SetCtrl(KEYSCAN_LED_GREEN,SET_TOGGLE_LED,TRUE);

    // disable flash re-charge
    SxTimer_SetFuncActive(SX_TIMER_DET_RECHARGE_ID,FALSE);
}
void Power_StopUSBCharge(void)
{
    //DBG_MSG("  gIsUSBInsert=%d,gIsBattInsert=%d,gIsBattDead=%d,gIsUSBAdapter=%d\r\n",gIsUSBInsert,gIsBattInsert,gIsBattDead,gIsUSBAdapter);
    if (!gIsBattInsert)
    {
        DBG_DUMP("  NO Battery, Ignore STOP\r\n");
        return;
    }
#if _MIPS_TODO
    //#NT#2010/12/10#Jeah Yen -begin
    if((USB_GetSource() == USB_SRC_USB_ADAPTER) && (Power_GetSource() != POWER_SRC_USB_ADAPTER))
    {
        //Not charge yet, just start check low-battery
        DBG_DUMP("GxPower: Start low-battery check.\r\n");
        GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, TRUE);
    }
    //#NT#2010/12/10#Jeah Yen -end

    //#NT#2011/3/30#Jeah Yen -begin
    if((USB_GetSource() == USB_SRC_NONE) && (Power_GetSource() != POWER_SRC_USB_ADAPTER))
    {
        //Cannot charge, start check low-battery
        DBG_DUMP("GxPower: Start low-battery check.\r\n");
        GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, TRUE);
    }
    //#NT#2011/3/30#Jeah Yen -end

    if((USB_GetSource() == USB_SRC_USB_ADAPTER))
    {
        //DBG_MSG("  USB Src = Adaptor\r\n");
        GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_CURRENT,BATT_CHARGE_CURRENT_LOW);
        DBG_MSG("  Charge Current = %d\r\n", BATT_CHARGE_CURRENT_LOW);
    }
#endif
    if((USB_GetSource() == USB_SRC_USB_PC))
    {
        //DBG_MSG("  USB Src = PC\r\n");
        GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_CURRENT,BATT_CHARGE_CURRENT_LOW);
        DBG_MSG("  Charge Current = %d\r\n", BATT_CHARGE_CURRENT_LOW);
    }

    if (!GxPower_GetControl(GXPWR_CTRL_BATTERY_CHARGE_EN))
    {
        DBG_DUMP("  Already NOT Charge, Ignore STOP\r\n");
        return;
    }

    //#NT#2010/12/10#Jeah Yen -begin
    DBG_DUMP("GxPower: Stop to Charge Battery\r\n");
    GxPower_SetControl(GXPWR_CTRL_BATTERY_CHARGE_EN,FALSE);
#if _MIPS_TODO
    if(!gIsUSBChargePreCheck
        && (GxSystem_GetState(SYSTEM_STATE_POWERON) != SYSTEM_POWERON_CHARGE)
        )
    {
#if (USB_CHARGE_VERIFY == ENABLE)
#else
       // GxLED_SetCtrl(KEYSCAN_LED_GREEN,SET_TOGGLE_LED,FALSE);
       // GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);
#endif
        //GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);
        //GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,FALSE);
    }
#endif
    DBG_DUMP("GxPower: Start low-battery check.\r\n");
    GxPower_SetControl(GXPWR_CTRL_BATTERY_DETECT_EN, TRUE);
    // enable flash re-charge
    SxTimer_SetFuncActive(SX_TIMER_DET_RECHARGE_ID,TRUE);
    //#NT#2010/12/10#Jeah Yen -end

}
#endif


#define HALF_AN_day  (50*60*3)//43200//(60*60*12)
#define ACC_TIME_RANG   (80)

void System_DetACC()
{
   static BOOL uiAccStatus = FALSE;
   static BOOL bAccCountFlag=FALSE;   
   static UINT32 uiKeyScanAccOffCnt;
   static UINT32 uiKeyScanAccOnCnt;
   
   static UINT32 uiAccStatusLast=0xFF;
   static BOOL bFirstPowerOn=TRUE;
   static BOOL bNeedToChangModeFlag=TRUE;

   //uiAccStatus = GPIOMap_AccDet();
   //GPIOMap_AccDet();
   uiAccStatus = TRUE;
   
   if(gbACCDetEn = FALSE)
   {
   		return;
   }

	/* acc status change */
   if(uiAccStatusLast != uiAccStatus)
   {
      //debug_msg("ACC Det %s...uiKeyScanAccOnCnt:%d..uiKeyScanAccOffCnt:%d...%d...\r\n",(uiAccStatus==TRUE)?"ON":"OFF",uiKeyScanAccOnCnt,uiKeyScanAccOffCnt,rtc_getPWROnSource());				   	   

	   /* ACC Plug In */
	   if(uiAccStatus == TRUE)
	   {
	   		bAccCountFlag=FALSE;
			uiKeyScanAccOnCnt++;
			uiKeyScanAccOffCnt=0;
		
			if(uiKeyScanAccOnCnt > ACC_TIME_RANG)
			{
				debug_msg("ACC Plug In....\r\n");
				uiKeyScanAccOnCnt=0;
				uiAccStatusLast = uiAccStatus;  			
	              //debug_msg("ACC Plug In..%d..%d..%d\r\n",System_GetState(SYS_STATE_CURRMODE),System_GetState(SYS_STATE_NEXTSUBMODE),System_GetState(SYS_STATE_CURRSUBMODE)); 	
			    UI_SetData(FL_MOVIE_MOTION_DET, FALSE);					  			
                #if 1 				  
				if(UI_GetData(FL_WIFI_LINK) == WIFI_LINK_NG)
				{
			    	if(GPIOMap_GetWifiPower() == FALSE)
			        {
						GPIOMap_SetWifiPower(TRUE);
						debug_msg("System_DetACC---GPIOMap_SetWifiPower---TRUE\r\n");
			        }
					
					if (System_GetState(SYS_STATE_CURRMODE) == PRIMARY_MODE_MOVIE)
					{
						switch(gMovData.State)	
						{
							case MOV_ST_REC:
							case MOV_ST_REC|MOV_ST_ZOOM:
								FlowMovie_StopRec();	
								break;

							default:
								break;
						}
					}	
					
					//if (System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
					//{
	                		//Ux_OpenWindow(&UIMenuWndWiFiWaitCtrl, 0);
                			//BKG_PostEvent(NVTEVT_BKW_WIFI_ON);
					//}
					//else

					gbOpenWifiFunc = TRUE;
					gbACCDetEn = FALSE;
        			//Ux_SendEvent(&UISetupObjCtrl,NVTEVT_EXE_CHANGEDSCMODE,1,DSCMODE_CHGTO_NEXT);					
             		Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);        				
			}
			else
			{
				if(UIFlowWndWiFiMovie_GetStatus() != WIFI_MOV_ST_RECORD)
				{
                	Ux_PostEvent(NVTEVT_KEY_SHUTTER2, 1, NVTEVT_KEY_PRESS); 		
				}
			}
			#endif			
		}
	}
	else
	{
		uiKeyScanAccOffCnt++;
		uiKeyScanAccOnCnt=0;
		
		if(uiKeyScanAccOffCnt > ACC_TIME_RANG)
		{	
	    	debug_msg("ACC Plug Out..ready to power off..\r\n");	
			uiKeyScanAccOffCnt=0;	  
			uiAccStatusLast = uiAccStatus;  						  
			bAccCountFlag=TRUE;
			
			UI_SetData(FL_MOVIE_MOTION_DET, TRUE);
			#if 1		
			if (UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
			{
				FlowWiFiMovie_StopRec();                        
			}
			
			if (System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
			{
				switch(gMovData.State)	
				{
					case MOV_ST_REC:
					case MOV_ST_REC|MOV_ST_ZOOM:
						FlowMovie_StopRec();	
						break;
				}
			}			
			if((UI_GetData(FL_WIFI_LINK) == WIFI_LINK_OK) && (GPIOMap_GetWifiPower() == TRUE))
			{
                Ux_PostEvent(NVTEVT_KEY_WIFIONOFF, 1, NVTEVT_KEY_PRESS);	// ON OFF WIFI 
				GPIOMap_SetWifiPower(FALSE);
				debug_msg("System_DetACC--GPIOMap_SetWifiPower---FALSE\r\n");
			}		
			#endif			
		}

	}
  }
  else/* acc status no change */
  {
  	#if 1
  	if(uiKeyScanAccOffCnt != 0)
  	{
		if(uiAccStatus == TRUE)
		{
			if(uiAccStatusLast==TRUE)
			{
				uiAccStatusLast = FALSE;
				uiKeyScanAccOffCnt = 0;
			}
		}
  	}
	
	if(uiKeyScanAccOnCnt != 0)
	{
		if(uiAccStatus == FALSE)
		{
			if(uiAccStatusLast == FALSE)
			{
				uiAccStatusLast = TRUE;
				uiKeyScanAccOnCnt = 0;
			}		
		}
	}
   #endif	
  }
   if(bAccCountFlag == TRUE)
   {
       uiKeyScanAccOffCnt++;
	//debug_msg("ACC Power Off...%d\r\n",uiKeyScanAccOffCnt);			
	   
	if(uiKeyScanAccOffCnt > HALF_AN_day)
	{
	       bAccCountFlag=FALSE; 
		uiAccStatusLast=uiAccStatus;  			   
		uiKeyScanAccOffCnt=0;			
		
		if (UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
		{
			FlowWiFiMovie_StopRec();                        
		}		
		if (System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
		{
			switch(gMovData.State)	
			{
				case MOV_ST_REC:
				case MOV_ST_REC|MOV_ST_ZOOM:
				FlowMovie_StopRec();	
				Delay_DelayMs(500);
				break;
			}
		}			
		GSensor_ParkingMode();
		Ux_PostEvent(NVTEVT_SYSTEM_SHUTDOWN, 1, 0);	
	}
   }

}

void UI_DetLEDStatus(void)
{
    static UINT32 uiRedLedIsToggle=FALSE;

    //debug_msg("card:%d, wifi link:%d, record status:%d, wifi power:%d\r\n",UI_GetData(FL_CardStatus),UI_GetData(FL_WIFI_LINK),UIFlowWndWiFiMovie_GetStatus(),GPIOMap_GetWifiPower());	
#if(_MODEL_DSC_ == _MODEL_DEMO1_)   	
    if (UI_GetData(FL_CardStatus) == CARD_REMOVED)
    {
    	if(uiRedLedIsToggle==TRUE)
    	{
		GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);   	
		if(GxLED_IsLEDOn(KEYSCAN_LED_RED)==FALSE)
		{
			GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,TRUE);   	
		}		
	}
       //*********************************
 	//    turn on GREEN_LED when wifi ON
 	//    turn off GREEN_LED when wifi OFF
 	//*********************************
 	if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
 	{
		if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN)==FALSE)
		{
			GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);   	
		}
	}
	else
 	{
		if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN)==TRUE)
		{
			GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);   	
		}
	}		
    }
    else
    {
              //*********************************
	 	//    turn on GREEN_LED when wifi ON
	 	//    turn off GREEN_LED when wifi OFF
	 	//*********************************
	 	if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
	 	{
			if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN)==FALSE)
			{
				GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);   	
			}
		 	//*********************************
		 	//    Toggle On RED_LED when movie recording
		 	//    Toggle Off RED_LED when movie not recording and others
			if(UIFlowWndWiFiMovie_GetStatus()==WIFI_MOV_ST_RECORD)
			{
			    	if(uiRedLedIsToggle==FALSE)
			    	{
			    		uiRedLedIsToggle=TRUE;
					GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,TRUE);   	
				}
			}		
			else
			{
			    	if(uiRedLedIsToggle==TRUE)
			    	{
			    		uiRedLedIsToggle=FALSE;
					GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);   	
				}
				if(GxLED_IsLEDOn(KEYSCAN_LED_RED)==FALSE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,TRUE);   	
				}					
			}			
		}
		else
	 	{
			if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN)==TRUE)
			{
				GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);   	
			}
		 	//*********************************
		 	//    Toggle On RED_LED when movie recording
		 	//    Toggle Off RED_LED when movie not recording and others
			switch(gMovData.State)	
			{
				case MOV_ST_REC:
				case MOV_ST_REC|MOV_ST_ZOOM:
			    	if(uiRedLedIsToggle==FALSE)
			    	{
			    		uiRedLedIsToggle=TRUE;
					GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,TRUE);   	
				}					
				break;
				default:
			    	if(uiRedLedIsToggle==TRUE)
			    	{
			    		uiRedLedIsToggle=FALSE;
					GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,FALSE);   	
				}
				if(GxLED_IsLEDOn(KEYSCAN_LED_RED)==FALSE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,TRUE);   	
				}	
				break;
			}
		
		}			
			
    }
#elif(_MODEL_DSC_ == _MODEL_SL508_)    
    if (UI_GetData(FL_CardStatus) == CARD_REMOVED)
    {
      	/* SET_TOGGLE_LED when card removed */
    	GxLED_SetCtrl(KEYSCAN_LED_RED,SET_TOGGLE_LED,TRUE);
		
    }
    else
    {
           /*          
	 	   		turn on GREEN_LED && turn off RED_LED when recording
	 	   		turn off GREEN_LED && RED_LED when not recording
	 	   	*/
	 	
	 	if(UI_GetData(FL_WIFI_LINK) == WIFI_LINK_OK)
	 	{
			if(UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
			{
				if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN) == FALSE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);  
				}
				
				if(GxLED_IsLEDOn(KEYSCAN_LED_RED) == TRUE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,FALSE); 
				}				
			}		
			else
			{
				if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN) == TRUE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);   	
				}	
				
				if(GxLED_IsLEDOn(KEYSCAN_LED_RED) == FALSE)
				{
					GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,TRUE);   	
				}				
			}			
		}
		else
	 	{
			switch(gMovData.State)	
			{
				case MOV_ST_REC:
				case MOV_ST_REC|MOV_ST_ZOOM:
					if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN) == FALSE)
					{
						GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,TRUE);   	
					}
					
					if(GxLED_IsLEDOn(KEYSCAN_LED_RED)==TRUE)
					{
						GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,FALSE);   	
					}					
				break;
				
				default:
					if(GxLED_IsLEDOn(KEYSCAN_LED_GREEN) == TRUE)
					{
						GxLED_SetCtrl(KEYSCAN_LED_GREEN,TURNON_LED,FALSE);   	
					}					
					if(GxLED_IsLEDOn(KEYSCAN_LED_RED) == FALSE)
					{
						GxLED_SetCtrl(KEYSCAN_LED_RED,TURNON_LED,TRUE);   	
					}
				break;
			}
		
		}			
			
    }
#endif
}


void UI_DetGsensor(void)
{
    Gsensor_Data GS_Data;
    INT32 gsensor_trig;
    static UINT32 X,Y,Z;
    static UINT32 counter=0;
	//debug_msg("UI_DetGsensor ---\r\n");
    if(counter < 5)
    {
		GSensor_GetData(&GS_Data);
		counter++;
    }
    else
    {
       if(UI_GetData(FL_GSENSOR) != GSENSOR_OFF)
       {
	   		if(UI_GetData(FL_WIFI_LINK) == WIFI_LINK_OK)
	   		{
				if(UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
				{
				    if(GSensor_GetData(&GS_Data)==TRUE)
		            {
		                     debug_msg("gsensor trig,post DOWN event..22..\r\n");		            
                        	 Ux_PostEvent(NVTEVT_KEY_DOWN, 1,NVTEVT_KEY_PRESS);					
		            }		
			     }
		    }	
			else
	   		{
				switch(gMovData.State)	
				{
					case MOV_ST_REC:
					case MOV_ST_REC|MOV_ST_ZOOM:
				 		if(GSensor_GetData(&GS_Data)==TRUE)
		         		{
		            		debug_msg("gsensor trig,post DOWN event..\r\n");
                        	Ux_PostEvent(NVTEVT_KEY_DOWN, 1,NVTEVT_KEY_PRESS);					
		         		}		
		          		break;
				 	default:
				 		break;
				}
	   		}
       	}
    }
}
void System_DetWatchDog(void)
{
	static BOOL Flag=TRUE;	
	Flag = ~Flag;	
	GPIOMap_SetWatchDogStatus(Flag);
}


