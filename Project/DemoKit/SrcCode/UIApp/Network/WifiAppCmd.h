#ifndef _WIFIAPPCMD_H_
#define _WIFIAPPCMD_H_




#ifdef __ECOS


#include "Type.h"
#include "WifiCmdParser.h"
/**
    @name EXT_CMD_ITEM command from APP.
*/
//@{
//photo mode command
#define WIFIAPP_CMD_CAPTURE              1001
#define WIFIAPP_CMD_CAPTURESIZE          1002
#define WIFIAPP_CMD_FREE_PIC_NUM         1003

//movie mode command
#define WIFIAPP_CMD_RECORD                    2001
#define WIFIAPP_CMD_MOVIE_REC_SIZE            2002
#define WIFIAPP_CMD_CYCLIC_REC                2003
#define WIFIAPP_CMD_MOVIE_HDR                 2004
#define WIFIAPP_CMD_MOVIE_EV                  2005
#define WIFIAPP_CMD_MOTION_DET                2006
#define WIFIAPP_CMD_MOVIE_AUDIO               2007
#define WIFIAPP_CMD_DATEIMPRINT               2008
#define WIFIAPP_CMD_MAX_RECORD_TIME           2009
#define WIFIAPP_CMD_MOVIE_LIVEVIEW_SIZE       2010
#define WIFIAPP_CMD_MOVIE_GSENSOR_SENS        2011
#define WIFIAPP_CMD_SET_AUTO_RECORDING        2012
#define WIFIAPP_CMD_MOVIE_REC_BITRATE         2013
#define WIFIAPP_CMD_MOVIE_LIVEVIEW_BITRATE    2014
#define WIFIAPP_CMD_MOVIE_LIVEVIEW_START      2015
#define WIFIAPP_CMD_MOVIE_RECORDING_TIME      2016
#define WIFIAPP_CMD_MOVIE_REC_TRIGGER_RAWENC  2017
#define WIFIAPP_CMD_MOVIE_GET_RAWENC_JPG      2018

//setup command
#define WIFIAPP_CMD_MODECHANGE           3001
#define WIFIAPP_CMD_QUERY                3002
#define WIFIAPP_CMD_SET_SSID             3003
#define WIFIAPP_CMD_SET_PASSPHRASE       3004
#define WIFIAPP_CMD_SET_DATE             3005
#define WIFIAPP_CMD_SET_TIME             3006
#define WIFIAPP_CMD_POWEROFF             3007
#define WIFIAPP_CMD_LANGUAGE             3008
#define WIFIAPP_CMD_TVFORMAT             3009
#define WIFIAPP_CMD_FORMAT               3010
#define WIFIAPP_CMD_SYSRESET             3011
#define WIFIAPP_CMD_VERSION              3012
#define WIFIAPP_CMD_FWUPDATE             3013
#define WIFIAPP_CMD_QUERY_CUR_STATUS     3014
#define WIFIAPP_CMD_FILELIST             3015
#define WIFIAPP_CMD_HEARTBEAT            3016
#define WIFIAPP_CMD_DISK_FREE_SPACE      3017
#define WIFIAPP_CMD_RECONNECT_WIFI       3018
#define WIFIAPP_CMD_GET_BATTERY          3019
#define WIFIAPP_CMD_NOTIFY_STATUS        3020
#define WIFIAPP_CMD_SAVE_MENUINFO        3021
#define WIFIAPP_CMD_GET_HW_CAP           3022
#define WIFIAPP_CMD_REMOVE_USER          3023
#define WIFIAPP_CMD_GET_CARD_STATUS      3024
#define WIFIAPP_CMD_GET_DOWNLOAD_URL     3025
#define WIFIAPP_CMD_GET_UPDATEFW_PATH    3026
#define WIFIAPP_CMD_UPLOAD_FILE          3027
#define WIFIAPP_CMD_SET_PIP_STYLE        3028
#define WIFIAPP_CMD_ROTATE        3029

//playback command
#define WIFIAPP_CMD_THUMB                4001
#define WIFIAPP_CMD_SCREEN               4002
#define WIFIAPP_CMD_DELETE_ONE           4003
#define WIFIAPP_CMD_DELETE_ALL           4004
#define WIFIAPP_CMD_MOVIE_FILE_INFO      4005
//@}

/**
    @name WIFIAPP_RET return value for app command.
*/
//@{
#define WIFIAPP_RET_OK                   0
#define WIFIAPP_RET_RECORD_STARTED       1
#define WIFIAPP_RET_RECORD_STOPPED       2
#define WIFIAPP_RET_DISCONNECT           3
#define WIFIAPP_RET_MIC_ON               4
#define WIFIAPP_RET_MIC_OFF              5
#define WIFIAPP_RET_POWER_OFF            6
#define WIFIAPP_RET_REMOVE_BY_USER       7
#define WIFIAPP_RET_NOFILE              (-1)
#define WIFIAPP_RET_EXIF_ERR            (-2)
#define WIFIAPP_RET_NOBUF               (-3)
#define WIFIAPP_RET_FILE_LOCKED         (-4)
#define WIFIAPP_RET_FILE_ERROR          (-5)
#define WIFIAPP_RET_DELETE_FAILED       (-6)
#define WIFIAPP_RET_MOVIE_FULL          (-7)
#define WIFIAPP_RET_MOVIE_WR_ERROR      (-8)
#define WIFIAPP_RET_MOVIE_SLOW          (-9)
#define WIFIAPP_RET_BATTERY_LOW         (-10)
#define WIFIAPP_RET_STORAGE_FULL        (-11)
#define WIFIAPP_RET_FOLDER_FULL         (-12)
#define WIFIAPP_RET_FAIL                (-13)
#define WIFIAPP_RET_FW_WRITE_CHK_ERR    (-14)   // (UPDNAND_STS_FW_WRITE_CHK_ERR+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_READ2_ERR        (-15)   // (UPDNAND_STS_FW_READ2_ERR+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_WRITE_ERR        (-16)   // (UPDNAND_STS_FW_WRITE_ERR+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_READ_CHK_ERR     (-17)   // (UPDNAND_STS_FW_READ_CHK_ERR+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_READ_ERR         (-18)   // (UPDNAND_STS_FW_READ_ERR+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_INVALID_STG      (-19)   // (UPDNAND_STS_FW_INVALID_STG+WIFIAPP_RET_FW_OFFSET)
#define WIFIAPP_RET_FW_OFFSET           (-20)   // FW update offset
#define WIFIAPP_RET_PAR_ERR             (-21)
#define WIFIAPP_RET_STATE_ERR           (-22)
#define WIFIAPP_RET_CMD_NOTFOUND        WIFI_CMD_NOT_FOUND //(-256)

//@}

/* WIFIAPP_RET_FW_xxx refere to
#define UPDNAND_STS_FW_OK               0   // Update FW to NAND OK
#define UPDNAND_STS_FW_INVALID_STG      1   // Invalid source storage
#define UPDNAND_STS_FW_READ_ERR         2   // FW doesn't exist or read error
#define UPDNAND_STS_FW_READ_CHK_ERR     3   // Read FW checksum failed, might be error
#define UPDNAND_STS_FW_WRITE_ERR        4   // Write FW to NAND error
#define UPDNAND_STS_FW_READ2_ERR        5   // Read FW from NAND failed (for write checking)
#define UPDNAND_STS_FW_WRITE_CHK_ERR    6   // Write FW checksum failed
*/



#define WIFIFLAG_MODE_DONE                   FLGPTN_BIT(0) //0x00000001
#define WIFIFLAG_CAPTURE_DONE                FLGPTN_BIT(1) //0x00000002
#define WIFIFLAG_RECORD_DONE                 FLGPTN_BIT(2) //0x00000004
#define WIFIFLAG_PREVIEW_DONE                FLGPTN_BIT(3) //0x00000008
#define WIFIFLAG_FORMAT_DONE                 FLGPTN_BIT(4) //0x00000010
#define WIFIFLAG_UPDATE_DONE                 FLGPTN_BIT(5) //0x00000020
#define WIFIFLAG_MOVIE_REC_RAWENC_DONE       FLGPTN_BIT(6) //0x00000040


/**
     app mode change command
     command WIFIAPP_CMD_MODECHANGE
*/
typedef enum
{
    WIFI_APP_MODE_PHOTO = 0,
    WIFI_APP_MODE_MOVIE,
    WIFI_APP_MODE_PLAYBACK,
    ENUM_DUMMY4WORD(WIFI_APP_MODE_CMD)
} WIFI_APP_MODE_CMD;

#define SysCmdWifi_CmdSend(a,b)  //temp define


#define DEF_XML_HEAD    "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n"
#define DEF_XML_RET     "<Function>\n<Cmd>%d</Cmd>\n<Status>%d</Status>\n</Function>"
#define DEF_XML_STR     "<Function>\n<Cmd>%d</Cmd>\n<Status>%d</Status>\n<String>%s</String>\n</Function>"
#define DEF_XML_VALUE   "<Function>\n<Cmd>%d</Cmd>\n<Status>%d</Status>\n<Value>%lld</Value>\n</Function>"
#define DEF_XML_CMD_CUR_STS    "<Cmd>%d</Cmd>\n<Status>%d</Status>\n"

UINT32 WifiApp_SendCmd(UINT32 cmd,UINT32 status);
void WifiAppCmd_init(void);

int UserSocket_Send(char* addr, int* size);
int UserSocket_Recv(char* addr, int size);
void UserSocket_Open(void);
void UserSocket_Close(void);

#endif
#endif //_WIFIAPPCMD_H_



