//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndMovieRes.c"
#include "UIFlowWndMovie.h"
#include "PrjCfg.h"

//---------------------UIFlowWndMovieCtrl Debug Definition -----------------------------
#define _UIFLOWWNDMOVIE_ERROR_MSG        1
#define _UIFLOWWNDMOVIE_TRACE_MSG        0

#if (_UIFLOWWNDMOVIE_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIFlowWndMovieErrMsg(...)            debug_msg ("^R UIFlowWndMovie: "__VA_ARGS__)
#else
#define UIFlowWndMovieErrMsg(...)
#endif

#if (_UIFLOWWNDMOVIE_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIFlowWndMovieTraceMsg(...)          debug_msg ("^B UIFlowWndMovie: "__VA_ARGS__)
#else
#define UIFlowWndMovieTraceMsg(...)
#endif

//---------------------UIFlowWndMovieCtrl Global Variables -----------------------------

//---------------------UIFlowWndMovieCtrl Prototype Declaration  -----------------------

//---------------------UIFlowWndMovieCtrl Public API  ----------------------------------

//---------------------UIFlowWndMovieCtrl Private API  ---------------------------------
//---------------------UIFlowWndMovieCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndMovie)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_camera)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_CyclicRec)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_MotionDet)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_battery)
CTRL_LIST_ITEM(UIFlowWndMovie_YMD_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_HMS_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_Panel)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_Storage)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_time)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_maxtime)
CTRL_LIST_ITEM(UIFlowWndMovie_Static_resolution)
CTRL_LIST_ITEM(UIFlowWndMovie_Zoom_Static)
CTRL_LIST_ITEM(UIFlowWndMovie_StatusICN_EV)
CTRL_LIST_ITEM(UIFlowWndMovie_Status_HDR)
CTRL_LIST_ITEM(UIFlowWndMovie_StaticIcon_PIMC)
CTRL_LIST_END

//----------------------UIFlowWndMovieCtrl Event---------------------------
INT32 UIFlowWndMovie_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyShutter2(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyZoomin(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyZoomout(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnBattery(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnMovieFinish(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnMovieOneSec(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnMovieFull(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnOZoomStepChange(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnDZoomStepChange(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnStorageChange(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndMovie_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndMovie)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndMovie_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndMovie_OnClose)
EVENT_ITEM(NVTEVT_KEY_MENU,UIFlowWndMovie_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIFlowWndMovie_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIFlowWndMovie_OnKeyDown)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIFlowWndMovie_OnChildClose)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIFlowWndMovie_OnKeyShutter2)
EVENT_ITEM(NVTEVT_KEY_ZOOMIN,UIFlowWndMovie_OnKeyZoomin)
EVENT_ITEM(NVTEVT_KEY_ZOOMOUT,UIFlowWndMovie_OnKeyZoomout)
EVENT_ITEM(NVTEVT_KEY_UP,UIFlowWndMovie_OnKeyUp)
EVENT_ITEM(NVTEVT_BATTERY,UIFlowWndMovie_OnBattery)
EVENT_ITEM(NVTEVT_KEY_MODE,UIFlowWndMovie_OnKeyMode)
EVENT_ITEM(NVTEVT_CB_MOVIE_FINISH,UIFlowWndMovie_OnMovieFinish)
EVENT_ITEM(NVTEVT_CB_MOVIE_ONE_SEC,UIFlowWndMovie_OnMovieOneSec)
EVENT_ITEM(NVTEVT_CB_MOVIE_FULL,UIFlowWndMovie_OnMovieFull)
EVENT_ITEM(NVTEVT_CB_OZOOMSTEPCHG,UIFlowWndMovie_OnOZoomStepChange)
EVENT_ITEM(NVTEVT_CB_DZOOMSTEPCHG,UIFlowWndMovie_OnDZoomStepChange)
EVENT_ITEM(NVTEVT_STORAGE_CHANGE,UIFlowWndMovie_OnStorageChange)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndMovie_OnTimer)
EVENT_END

INT32 UIFlowWndMovie_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_MENU,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_ENTER,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_DOWN,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_SHUTTER2,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyZoomin(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_ZOOMIN,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyZoomout(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_ZOOMOUT,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_KEY_UP,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnBattery(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnMovieFinish(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnMovieOneSec(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnMovieFull(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnOZoomStepChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnDZoomStepChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnStorageChange(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndMovie_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_TIMER,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndMovie_Static_cameraCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_camera)
EVENT_END

//----------------------UIFlowWndMovie_Status_CyclicRecCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_CyclicRec)
EVENT_END

//----------------------UIFlowWndMovie_Status_MotionDetCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_MotionDet)
EVENT_END

//----------------------UIFlowWndMovie_Status_batteryCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_battery)
EVENT_END

//----------------------UIFlowWndMovie_YMD_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_YMD_Static)
EVENT_END

//----------------------UIFlowWndMovie_HMS_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_HMS_Static)
EVENT_END

//---------------------UIFlowWndMovie_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndMovie_Panel)
CTRL_LIST_END

//----------------------UIFlowWndMovie_PanelCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Panel)
EVENT_END

//----------------------UIFlowWndMovie_Status_StorageCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_Storage)
EVENT_END

//----------------------UIFlowWndMovie_Static_timeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_time)
EVENT_END

//----------------------UIFlowWndMovie_Static_maxtimeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_maxtime)
EVENT_END

//----------------------UIFlowWndMovie_Static_resolutionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Static_resolution)
EVENT_END

//----------------------UIFlowWndMovie_Zoom_StaticCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Zoom_Static)
EVENT_END

//----------------------UIFlowWndMovie_StatusICN_EVCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_StatusICN_EV)
EVENT_END

//----------------------UIFlowWndMovie_Status_HDRCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_Status_HDR)
EVENT_END

//----------------------UIFlowWndMovie_StaticIcon_PIMCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMovie_StaticIcon_PIMC)
EVENT_END

