//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDPLAYRES_H
#define UIFLOWWNDPLAYRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,319,239,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_ITEM_RECT(CMD_Rectangle,Skin3Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Skin3Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon4, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Icon4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,12,5,39,32)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticICN_DSCMode)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticICN_DSCMode)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticICN_DSCMode,ICON_MODE_PLAYBACK)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticICN_DSCMode,0,12,5,39,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin7Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin7)
SHOW_MAP_BODY(Skin7Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin7,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon8, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal6)
SHOW_MAP_BODY(Skin7)
SHOW_MAP_BODY(Icon8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal6,50,5,77,32)

CREATE_STATE_ITEM_DATA(ICON_FLASH_AUTO9,STRID_NULL,ICON_FLASH_AUTO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_ON10,STRID_NULL,ICON_FLASH_ON,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_RED_EYE11,STRID_NULL,ICON_FLASH_RED_EYE,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_OFF12,STRID_NULL,ICON_FLASH_OFF,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Flash)
SHOW_MAP_BODY(Normal6)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Flash)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Flash)
STATE_LIST_ITEM(ICON_FLASH_AUTO9)
STATE_LIST_ITEM(ICON_FLASH_ON10)
STATE_LIST_ITEM(ICON_FLASH_RED_EYE11)
STATE_LIST_ITEM(ICON_FLASH_OFF12)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Flash,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Flash,0,50,5,77,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin14Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin14)
SHOW_MAP_BODY(Skin14Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin14,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon15, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal13)
SHOW_MAP_BODY(Skin14)
SHOW_MAP_BODY(Icon15)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal13,12,38,39,65)

CREATE_STATE_ITEM_DATA(ICON_EV_M2P016,STRID_NULL,ICON_EV_M2P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P617,STRID_NULL,ICON_EV_M1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P318,STRID_NULL,ICON_EV_M1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P019,STRID_NULL,ICON_EV_M1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P620,STRID_NULL,ICON_EV_M0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P321,STRID_NULL,ICON_EV_M0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P022,STRID_NULL,ICON_EV_P0P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P323,STRID_NULL,ICON_EV_P0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P624,STRID_NULL,ICON_EV_P0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P025,STRID_NULL,ICON_EV_P1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P326,STRID_NULL,ICON_EV_P1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P627,STRID_NULL,ICON_EV_P1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P2P028,STRID_NULL,ICON_EV_P2P0,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_EV)
SHOW_MAP_BODY(Normal13)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_EV)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_EV)
STATE_LIST_ITEM(ICON_EV_M2P016)
STATE_LIST_ITEM(ICON_EV_M1P617)
STATE_LIST_ITEM(ICON_EV_M1P318)
STATE_LIST_ITEM(ICON_EV_M1P019)
STATE_LIST_ITEM(ICON_EV_M0P620)
STATE_LIST_ITEM(ICON_EV_M0P321)
STATE_LIST_ITEM(ICON_EV_P0P022)
STATE_LIST_ITEM(ICON_EV_P0P323)
STATE_LIST_ITEM(ICON_EV_P0P624)
STATE_LIST_ITEM(ICON_EV_P1P025)
STATE_LIST_ITEM(ICON_EV_P1P326)
STATE_LIST_ITEM(ICON_EV_P1P627)
STATE_LIST_ITEM(ICON_EV_P2P028)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_EV,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_EV,0,12,38,39,65)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin30Rect,0,0,107,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin30)
SHOW_MAP_BODY(Skin30Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin30,0,0,107,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text32,1,0,106,27,STRID_NULL,0,1280,0,0,2,1,0,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal29)
SHOW_MAP_BODY(Skin30)
SHOW_MAP_BODY(Text32)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal29,201,32,308,59)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Size)
SHOW_MAP_BODY(Normal29)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Size)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Size,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Size,0,201,32,308,59)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin35Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin35)
SHOW_MAP_BODY(Skin35Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin35,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon36, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal34)
SHOW_MAP_BODY(Skin35)
SHOW_MAP_BODY(Icon36)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal34,12,71,39,98)

CREATE_STATE_ITEM_DATA(ICON_WB_AUTO37,STRID_NULL,ICON_WB_AUTO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_WB_DAYLIGHT38,STRID_NULL,ICON_WB_DAYLIGHT,NULL) 
CREATE_STATE_ITEM_DATA(ICON_WB_CLOUDY39,STRID_NULL,ICON_WB_CLOUDY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_WB_TUNGSTEN40,STRID_NULL,ICON_WB_TUNGSTEN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_WB_FLUORESCENT41,STRID_NULL,ICON_WB_FLUORESCENT,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_WB)
SHOW_MAP_BODY(Normal34)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_WB)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_WB)
STATE_LIST_ITEM(ICON_WB_AUTO37)
STATE_LIST_ITEM(ICON_WB_DAYLIGHT38)
STATE_LIST_ITEM(ICON_WB_CLOUDY39)
STATE_LIST_ITEM(ICON_WB_TUNGSTEN40)
STATE_LIST_ITEM(ICON_WB_FLUORESCENT41)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_WB,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_WB,0,12,71,39,98)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin43Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin43)
SHOW_MAP_BODY(Skin43Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin43,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon44, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal42)
SHOW_MAP_BODY(Skin43)
SHOW_MAP_BODY(Icon44)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal42,280,60,307,87)

CREATE_STATE_ITEM_DATA(ICON_QUALITY_FINE45,STRID_NULL,ICON_QUALITY_FINE,NULL) 
CREATE_STATE_ITEM_DATA(ICON_QUALITY_NORMAL46,STRID_NULL,ICON_QUALITY_NORMAL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_QUALITY_BASIC47,STRID_NULL,ICON_QUALITY_BASIC,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Quality)
SHOW_MAP_BODY(Normal42)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Quality)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Quality)
STATE_LIST_ITEM(ICON_QUALITY_FINE45)
STATE_LIST_ITEM(ICON_QUALITY_NORMAL46)
STATE_LIST_ITEM(ICON_QUALITY_BASIC47)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Quality,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Quality,0,280,60,307,87)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin49Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin49)
SHOW_MAP_BODY(Skin49Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin49,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon50, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal48)
SHOW_MAP_BODY(Skin49)
SHOW_MAP_BODY(Icon50)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal48,280,92,307,119)

CREATE_STATE_ITEM_DATA(ICON_SHARPNESS_HIGH51,STRID_NULL,ICON_SHARPNESS_HIGH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SHARPNESS_MED52,STRID_NULL,ICON_SHARPNESS_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SHARPNESS_LOW53,STRID_NULL,ICON_SHARPNESS_LOW,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Sharpness)
SHOW_MAP_BODY(Normal48)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Sharpness)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Sharpness)
STATE_LIST_ITEM(ICON_SHARPNESS_HIGH51)
STATE_LIST_ITEM(ICON_SHARPNESS_MED52)
STATE_LIST_ITEM(ICON_SHARPNESS_LOW53)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Sharpness,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Sharpness,0,280,92,307,119)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin55Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin55)
SHOW_MAP_BODY(Skin55Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin55,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon56, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal54)
SHOW_MAP_BODY(Skin55)
SHOW_MAP_BODY(Icon56)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal54,280,125,307,152)

CREATE_STATE_ITEM_DATA(ICON_INTERNAL_FLASH57,STRID_NULL,ICON_INTERNAL_FLASH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_CARD58,STRID_NULL,ICON_SD_CARD,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Storage)
SHOW_MAP_BODY(Normal54)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Storage)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Storage)
STATE_LIST_ITEM(ICON_INTERNAL_FLASH57)
STATE_LIST_ITEM(ICON_SD_CARD58)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Storage,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Storage,0,280,125,307,152)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin60Rect,0,0,31,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin60)
SHOW_MAP_BODY(Skin60Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin60,0,0,31,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon61, 0, 0, 31,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal59)
SHOW_MAP_BODY(Skin60)
SHOW_MAP_BODY(Icon61)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal59,276,207,307,234)

CREATE_STATE_ITEM_DATA(ICON_BATTERY_FULL62,STRID_NULL,ICON_BATTERY_FULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_MED63,STRID_NULL,ICON_BATTERY_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_LOW64,STRID_NULL,ICON_BATTERY_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_EMPTY65,STRID_NULL,ICON_BATTERY_EMPTY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_ZERO66,STRID_NULL,ICON_BATTERY_ZERO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_CHARGE67,STRID_NULL,ICON_BATTERY_CHARGE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Battery)
SHOW_MAP_BODY(Normal59)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Battery)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Battery)
STATE_LIST_ITEM(ICON_BATTERY_FULL62)
STATE_LIST_ITEM(ICON_BATTERY_MED63)
STATE_LIST_ITEM(ICON_BATTERY_LOW64)
STATE_LIST_ITEM(ICON_BATTERY_EMPTY65)
STATE_LIST_ITEM(ICON_BATTERY_ZERO66)
STATE_LIST_ITEM(ICON_BATTERY_CHARGE67)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Battery,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Battery,0,276,207,307,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin68Rect,0,0,127,49,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin68)
SHOW_MAP_BODY(Skin68Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin68,0,0,127,49)

SHOW_MAP_BEGIN(UIFlowWndPlay_TabHistogram)
SHOW_MAP_BODY(Skin68)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_TabHistogram)
CTRL_LIST_BEGIN(UIFlowWndPlay_TabHistogram)
CTRL_LIST_END

CREATE_TAB_DATA(UIFlowWndPlay_TabHistogram,0)

CREATE_TAB_CTRL(UIFlowWndPlay_TabHistogram,UIFlowWndPlay_TabHistogram,0,128,185,255,234)
SHOW_ITEM_RECT(CMD_Rectangle,Skin70Rect,0,0,107,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin70)
SHOW_MAP_BODY(Skin70Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin70,0,0,107,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text72,0,0,107,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal69)
SHOW_MAP_BODY(Skin70)
SHOW_MAP_BODY(Text72)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal69,201,5,308,32)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Filename)
SHOW_MAP_BODY(Normal69)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Filename)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Filename,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Filename,0,201,5,308,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin75Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin75)
SHOW_MAP_BODY(Skin75Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin75,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon76, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal74)
SHOW_MAP_BODY(Skin75)
SHOW_MAP_BODY(Icon76)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal74,88,5,115,32)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticICN_Protect)
SHOW_MAP_BODY(Normal74)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticICN_Protect)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticICN_Protect,ICON_LOCK)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticICN_Protect,0,88,5,115,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin79Rect,0,0,107,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin79)
SHOW_MAP_BODY(Skin79Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin79,0,0,107,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text81,0,0,107,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal78)
SHOW_MAP_BODY(Skin79)
SHOW_MAP_BODY(Text81)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal78,200,154,307,181)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Date)
SHOW_MAP_BODY(Normal78)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Date)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Date,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Date,0,200,154,307,181)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin84Rect,0,0,107,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin84)
SHOW_MAP_BODY(Skin84Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin84,0,0,107,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text86,0,0,107,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal83)
SHOW_MAP_BODY(Skin84)
SHOW_MAP_BODY(Text86)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal83,200,181,307,208)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Time)
SHOW_MAP_BODY(Normal83)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Time)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Time,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Time,0,200,181,307,208)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin88Rect,0,0,127,49,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin88)
SHOW_MAP_BODY(Skin88Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin88,0,0,127,49)

SHOW_MAP_BEGIN(UIFlowWndPlay_Histo)
SHOW_MAP_BODY(Skin88)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Histo)
CTRL_LIST_BEGIN(UIFlowWndPlay_Histo)
CTRL_LIST_END

CREATE_TAB_DATA(UIFlowWndPlay_Histo,0)

CREATE_TAB_CTRL(UIFlowWndPlay_Histo,UIFlowWndPlay_Histo,0,127,185,254,234)
SHOW_MAP_BEGIN(Skin90)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin90,0,0,53,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon91, 0, 0, 53,25, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal89)
SHOW_MAP_BODY(Skin90)
SHOW_MAP_BODY(Icon91)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal89,12,207,65,234)

CREATE_STATE_ITEM_DATA(ICON_OK_PLAY92,STRID_NULL,ICON_OK_PLAY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_OK_PAUSE93,STRID_NULL,ICON_OK_PAUSE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_MovPlay)
SHOW_MAP_BODY(Normal89)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_MovPlay)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_MovPlay)
STATE_LIST_ITEM(ICON_OK_PLAY92)
STATE_LIST_ITEM(ICON_OK_PAUSE93)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_MovPlay,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_MovPlay,0,12,207,65,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin95)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin95,0,0,53,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon96, 0, 0, 53,25, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal94)
SHOW_MAP_BODY(Skin95)
SHOW_MAP_BODY(Icon96)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal94,71,207,124,234)

CREATE_STATE_ITEM_DATA(ICON_U_STOP_ORI97,STRID_NULL,ICON_U_STOP_ORI,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_MovStop)
SHOW_MAP_BODY(Normal94)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_MovStop)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_MovStop)
STATE_LIST_ITEM(ICON_U_STOP_ORI97)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_MovStop,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_MovStop,0,71,207,124,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin99)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin99,0,0,53,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon100, 0, 0, 53,25, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal98)
SHOW_MAP_BODY(Skin99)
SHOW_MAP_BODY(Icon100)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal98,130,207,183,234)

CREATE_STATE_ITEM_DATA(ICON_FB_LEFT101,STRID_NULL,ICON_FB_LEFT,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_MovBwd)
SHOW_MAP_BODY(Normal98)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_MovBwd)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_MovBwd)
STATE_LIST_ITEM(ICON_FB_LEFT101)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_MovBwd,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_MovBwd,0,130,207,183,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin103Rect,0,0,81,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin103)
SHOW_MAP_BODY(Skin103Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin103,0,0,81,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text105,1,0,80,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal102)
SHOW_MAP_BODY(Skin103)
SHOW_MAP_BODY(Text105)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal102,227,32,308,59)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_MovPlayTime)
SHOW_MAP_BODY(Normal102)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_MovPlayTime)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_MovPlayTime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_MovPlayTime,0,227,32,308,59)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin108)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin108,0,0,53,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon109, 0, 0, 53,25, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal107)
SHOW_MAP_BODY(Skin108)
SHOW_MAP_BODY(Icon109)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal107,189,207,242,234)

CREATE_STATE_ITEM_DATA(ICON_FF_RIGHT110,STRID_NULL,ICON_FF_RIGHT,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_MovFwd)
SHOW_MAP_BODY(Normal107)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_MovFwd)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_MovFwd)
STATE_LIST_ITEM(ICON_FF_RIGHT110)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_MovFwd,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_MovFwd,0,189,207,242,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin112Rect,0,0,111,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin112)
SHOW_MAP_BODY(Skin112Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin112,0,0,111,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon113, 0, 0, 111,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal111)
SHOW_MAP_BODY(Skin112)
SHOW_MAP_BODY(Icon113)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal111,12,181,123,208)

CREATE_STATE_ITEM_DATA(ICON_VOL_0114,STRID_NULL,ICON_VOL_0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_1115,STRID_NULL,ICON_VOL_1,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_2116,STRID_NULL,ICON_VOL_2,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_3117,STRID_NULL,ICON_VOL_3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_4118,STRID_NULL,ICON_VOL_4,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_5119,STRID_NULL,ICON_VOL_5,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_6120,STRID_NULL,ICON_VOL_6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_7121,STRID_NULL,ICON_VOL_7,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOL_8122,STRID_NULL,ICON_VOL_8,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_StatusICN_Volumn)
SHOW_MAP_BODY(Normal111)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StatusICN_Volumn)
STATE_LIST_BEGIN(UIFlowWndPlay_StatusICN_Volumn)
STATE_LIST_ITEM(ICON_VOL_0114)
STATE_LIST_ITEM(ICON_VOL_1115)
STATE_LIST_ITEM(ICON_VOL_2116)
STATE_LIST_ITEM(ICON_VOL_3117)
STATE_LIST_ITEM(ICON_VOL_4118)
STATE_LIST_ITEM(ICON_VOL_5119)
STATE_LIST_ITEM(ICON_VOL_6120)
STATE_LIST_ITEM(ICON_VOL_7121)
STATE_LIST_ITEM(ICON_VOL_8122)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_StatusICN_Volumn,0)
CREATE_STATE_CTRL(UIFlowWndPlay_StatusICN_Volumn,0,12,181,123,208)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin124Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin124)
SHOW_MAP_BODY(Skin124Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin124,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon125, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal123)
SHOW_MAP_BODY(Skin124)
SHOW_MAP_BODY(Icon125)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal123,126,6,153,33)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticICN_Print)
SHOW_MAP_BODY(Normal123)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticICN_Print)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticICN_Print,ICON_PRINT)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticICN_Print,0,126,6,153,33)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin128Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin128)
SHOW_MAP_BODY(Skin128Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin128,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text130,0,0,59,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal127)
SHOW_MAP_BODY(Skin128)
SHOW_MAP_BODY(Text130)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal127,129,181,188,208)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Speed)
SHOW_MAP_BODY(Normal127)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Speed)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Speed,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Speed,0,129,181,188,208)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndPlay)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay)
DECLARE_CTRL_LIST(UIFlowWndPlay)
CREATE_CTRL(UIFlowWndPlay,UIFlowWndPlay,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
