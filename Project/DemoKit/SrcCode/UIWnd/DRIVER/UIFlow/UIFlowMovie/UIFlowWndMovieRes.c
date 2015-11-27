//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDMOVIERES_H
#define UIFLOWWNDMOVIERES_H

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

SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,29,29)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon4, 1, 1, 11,15, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Icon4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,12,5,41,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_camera)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_camera)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_camera,ICON_MODE_VIDEO)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_camera,0,12,5,41,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin7Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin7)
SHOW_MAP_BODY(Skin7Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin7,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon8, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal6)
SHOW_MAP_BODY(Skin7)
SHOW_MAP_BODY(Icon8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal6,12,38,39,65)

CREATE_STATE_ITEM_DATA(ICONID_NULL9,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_1MIN10,STRID_NULL,ICON_CYCLIC_REC_1MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_3MIN11,STRID_NULL,ICON_CYCLIC_REC_3MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_5MIN12,STRID_NULL,ICON_CYCLIC_REC_5MIN,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_CyclicRec)
SHOW_MAP_BODY(Normal6)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_ITEM(ICONID_NULL9)
STATE_LIST_ITEM(ICON_CYCLIC_REC_1MIN10)
STATE_LIST_ITEM(ICON_CYCLIC_REC_3MIN11)
STATE_LIST_ITEM(ICON_CYCLIC_REC_5MIN12)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_CyclicRec,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_CyclicRec,0,12,38,39,65)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin14Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin14)
SHOW_MAP_BODY(Skin14Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin14,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon15, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal13)
SHOW_MAP_BODY(Skin14)
SHOW_MAP_BODY(Icon15)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal13,12,71,39,98)

CREATE_STATE_ITEM_DATA(ICONID_NULL16,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_FLASH_REC17,STRID_NULL,ICON_FLASH_REC,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MotionDet)
SHOW_MAP_BODY(Normal13)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_ITEM(ICONID_NULL16)
STATE_LIST_ITEM(ICON_FLASH_REC17)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MotionDet,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MotionDet,0,12,71,39,98)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin19Rect,0,0,33,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin19)
SHOW_MAP_BODY(Skin19Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin19,0,0,33,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon20, 0, -1, 31,26, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal18)
SHOW_MAP_BODY(Skin19)
SHOW_MAP_BODY(Icon20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal18,276,208,309,235)

CREATE_STATE_ITEM_DATA(ICON_BATTERY_FULL21,STRID_NULL,ICON_BATTERY_FULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_MED22,STRID_NULL,ICON_BATTERY_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_LOW23,STRID_NULL,ICON_BATTERY_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_EMPTY24,STRID_NULL,ICON_BATTERY_EMPTY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_ZERO25,STRID_NULL,ICON_BATTERY_ZERO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_CHARGE26,STRID_NULL,ICON_BATTERY_CHARGE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_battery)
SHOW_MAP_BODY(Normal18)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_battery)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_battery)
STATE_LIST_ITEM(ICON_BATTERY_FULL21)
STATE_LIST_ITEM(ICON_BATTERY_MED22)
STATE_LIST_ITEM(ICON_BATTERY_LOW23)
STATE_LIST_ITEM(ICON_BATTERY_EMPTY24)
STATE_LIST_ITEM(ICON_BATTERY_ZERO25)
STATE_LIST_ITEM(ICON_BATTERY_CHARGE26)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_battery,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_battery,0,276,208,309,235)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin28Rect,0,0,120,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_BODY(Skin28Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,120,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text30,2,-1,119,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Text30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal27,56,214,176,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_YMD_Static)
SHOW_MAP_BODY(Normal27)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_YMD_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_YMD_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_YMD_Static,0,56,214,176,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin33Rect,0,0,86,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin33)
SHOW_MAP_BODY(Skin33Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin33,0,0,86,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text35,1,2,84,18,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal32)
SHOW_MAP_BODY(Skin33)
SHOW_MAP_BODY(Text35)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal32,182,214,268,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_HMS_Static)
SHOW_MAP_BODY(Normal32)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_HMS_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_HMS_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_HMS_Static,0,182,214,268,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_ELLIPSE(CMD_Ellipse,Ellipse39,0,1,17,16,16,0,0,3,0,0,0)
SHOW_MAP_BEGIN(Skin37)
SHOW_MAP_BODY(Ellipse39)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin37,0,0,17,17)

SHOW_MAP_BEGIN(UIFlowWndMovie_Panel)
SHOW_MAP_BODY(Skin37)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Panel)
DECLARE_CTRL_LIST(UIFlowWndMovie_Panel)
CREATE_CTRL(UIFlowWndMovie_Panel,UIFlowWndMovie_Panel,CTRL_WND,NULL,0 ,52,11,69,28)
SHOW_ITEM_RECT(CMD_Rectangle,Skin41Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin41)
SHOW_MAP_BODY(Skin41Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin41,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon42, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal40)
SHOW_MAP_BODY(Skin41)
SHOW_MAP_BODY(Icon42)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal40,280,170,307,197)

CREATE_STATE_ITEM_DATA(ICON_INTERNAL_FLASH43,STRID_NULL,ICON_INTERNAL_FLASH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_CARD44,STRID_NULL,ICON_SD_CARD,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_LOCK45,STRID_NULL,ICON_SD_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_Storage)
SHOW_MAP_BODY(Normal40)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_Storage)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_Storage)
STATE_LIST_ITEM(ICON_INTERNAL_FLASH43)
STATE_LIST_ITEM(ICON_SD_CARD44)
STATE_LIST_ITEM(ICON_SD_LOCK45)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_Storage,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_Storage,0,280,170,307,197)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin47Rect,0,0,81,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin47)
SHOW_MAP_BODY(Skin47Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin47,0,0,81,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text49,1,0,80,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal46)
SHOW_MAP_BODY(Skin47)
SHOW_MAP_BODY(Text49)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal46,227,5,308,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_time)
SHOW_MAP_BODY(Normal46)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_time)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_time,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_time,0,227,5,308,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin52Rect,0,0,89,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin52)
SHOW_MAP_BODY(Skin52Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin52,0,0,89,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text54,1,0,90,29,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal51)
SHOW_MAP_BODY(Skin52)
SHOW_MAP_BODY(Text54)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal51,227,5,316,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_maxtime)
SHOW_MAP_BODY(Normal51)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_maxtime)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_maxtime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_maxtime,0,227,5,316,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin57Rect,0,0,107,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin57)
SHOW_MAP_BODY(Skin57Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin57,0,0,107,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text59,1,0,106,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal56)
SHOW_MAP_BODY(Skin57)
SHOW_MAP_BODY(Text59)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal56,201,40,308,69)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_resolution)
SHOW_MAP_BODY(Normal56)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_resolution)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_resolution,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_resolution,0,201,40,308,69)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin62Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin62)
SHOW_MAP_BODY(Skin62Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin62,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text64,0,0,59,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal61)
SHOW_MAP_BODY(Skin62)
SHOW_MAP_BODY(Text64)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal61,76,168,135,195)

SHOW_MAP_BEGIN(UIFlowWndMovie_Zoom_Static)
SHOW_MAP_BODY(Normal61)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Zoom_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_Zoom_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Zoom_Static,0,76,168,135,195)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin67Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin67)
SHOW_MAP_BODY(Skin67Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin67,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon68, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal66)
SHOW_MAP_BODY(Skin67)
SHOW_MAP_BODY(Icon68)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal66,12,104,39,131)

CREATE_STATE_ITEM_DATA(ICON_EV_P2P069,STRID_NULL,ICON_EV_P2P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P670,STRID_NULL,ICON_EV_P1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P371,STRID_NULL,ICON_EV_P1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P072,STRID_NULL,ICON_EV_P1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P673,STRID_NULL,ICON_EV_P0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P374,STRID_NULL,ICON_EV_P0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P075,STRID_NULL,ICON_EV_P0P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P376,STRID_NULL,ICON_EV_M0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P677,STRID_NULL,ICON_EV_M0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P078,STRID_NULL,ICON_EV_M1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P379,STRID_NULL,ICON_EV_M1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P680,STRID_NULL,ICON_EV_M1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M2P081,STRID_NULL,ICON_EV_M2P0,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_EV)
SHOW_MAP_BODY(Normal66)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_ITEM(ICON_EV_P2P069)
STATE_LIST_ITEM(ICON_EV_P1P670)
STATE_LIST_ITEM(ICON_EV_P1P371)
STATE_LIST_ITEM(ICON_EV_P1P072)
STATE_LIST_ITEM(ICON_EV_P0P673)
STATE_LIST_ITEM(ICON_EV_P0P374)
STATE_LIST_ITEM(ICON_EV_P0P075)
STATE_LIST_ITEM(ICON_EV_M0P376)
STATE_LIST_ITEM(ICON_EV_M0P677)
STATE_LIST_ITEM(ICON_EV_M1P078)
STATE_LIST_ITEM(ICON_EV_M1P379)
STATE_LIST_ITEM(ICON_EV_M1P680)
STATE_LIST_ITEM(ICON_EV_M2P081)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_EV,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_EV,0,12,104,39,131)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin83Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin83)
SHOW_MAP_BODY(Skin83Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin83,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon84, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal82)
SHOW_MAP_BODY(Skin83)
SHOW_MAP_BODY(Icon84)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal82,80,5,107,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL85,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_HDR86,STRID_NULL,ICON_HDR,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_HDR)
SHOW_MAP_BODY(Normal82)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_HDR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_HDR)
STATE_LIST_ITEM(ICONID_NULL85)
STATE_LIST_ITEM(ICON_HDR86)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_HDR,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_HDR,0,80,5,107,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin88Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin88)
SHOW_MAP_BODY(Skin88Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin88,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon89, 1, 1, 11,15, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal87)
SHOW_MAP_BODY(Skin88)
SHOW_MAP_BODY(Icon89)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal87,112,5,139,32)

SHOW_MAP_BEGIN(UIFlowWndMovie_StaticIcon_PIMC)
SHOW_MAP_BODY(Normal87)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StaticIcon_PIMC)
CREATE_STATIC_DATA(UIFlowWndMovie_StaticIcon_PIMC,ICON_MODE_CAPTURE)
CREATE_STATIC_CTRL(UIFlowWndMovie_StaticIcon_PIMC,0,112,5,139,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin92Rect,0,0,29,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin92)
SHOW_MAP_BODY(Skin92Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin92,0,0,29,29)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon93, 1, 1, 11,15, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal91)
SHOW_MAP_BODY(Skin92)
SHOW_MAP_BODY(Icon93)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal91,144,5,173,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_Lock)
SHOW_MAP_BODY(Normal91)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_Lock)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_Lock,ICON_LOCK)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_Lock,0,144,5,173,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin95)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin95,0,0,319,239)

SHOW_MAP_BEGIN(UIFlowWndMovie_PNL_FDFrame)
SHOW_MAP_BODY(Skin95)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_PNL_FDFrame)
DECLARE_CTRL_LIST(UIFlowWndMovie_PNL_FDFrame)
CREATE_CTRL(UIFlowWndMovie_PNL_FDFrame,UIFlowWndMovie_PNL_FDFrame,CTRL_WND,NULL,0 ,0,0,319,239)
SHOW_MAP_BEGIN(UIFlowWndMovie)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie)
DECLARE_CTRL_LIST(UIFlowWndMovie)
CREATE_CTRL(UIFlowWndMovie,UIFlowWndMovie,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
