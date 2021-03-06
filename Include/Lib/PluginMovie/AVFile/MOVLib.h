/**
    Header file of mov fileformat.

    Exported header file of mov fileformat.

    @file       movLib.h
    @ingroup    mIAVMOV
    @note       Nothing

    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.
*/
#ifndef _MOVLIB_H
#define _MOVLIB_H

#include "type.h"

/**
    @addtogroup mIAVMOV
*/
//@{

//timescale
//#define MOV_TIMESCALE  600 // should be precise to fit all kinds of frame rate (such as 10, 15, 24, 30, 60, 120fps...)
#define MOV_TIMESCALE  30000 // should be precise to fit all kinds of frame rate (such as 10, 15, 24, 30, 60, 120fps...)

//#NT#2012/08/22#Hideo Lin -begin
//#NT#For thumbnail and user data
//#define ATOM_THUM   0x7468756d  // 'thum'
#define ATOM_USER   0x75736572  // 'user'
//#NT#2012/08/22#Hideo Lin -end

/*
    MOV_offset as a 32-bit pointer
*/
typedef UINT32  MOV_Offset;


/**
    @ name mov entry structure.

    Structure definition for a video/audio frame, including file offset, frame size,
    frame duration, and frame type.

    
*/
typedef struct 
{
    UINT32      pos;        ///< file offset of this frame
    UINT32      size;       ///< frame size
    //UINT32      duration;   ///< frame duration, used for av-sync
    UINT16      key_frame;  ///< frame type, whether key frame or not
    UINT8       updated;
    UINT8       rev;
} MOV_Ientry;
#define MP_MOV_SIZE_ONEENTRY 12 // one entry is 12 bytes


//#NT#2012/09/11#Meg Lin -begin
typedef struct
{
    UINT32 junkCC;      //oft: 0
    UINT32 junkSize;    //oft: 4
    UINT32 nidxCC;      //oft: 8
    UINT32 nidxSize;    //oft: c
    UINT32 audPos;      //oft: 10
    UINT32 audSize;     //oft: 14
    UINT32 lastjunkPos; //oft: 18
    UINT32 vidstartFN;  //oft: 1c
    UINT32 videoWid;    //oft: 20
    UINT32 videoHei;    //oft: 24
    UINT32 videoCodec;  //oft: 28
    UINT32 audSR;       //oft: 2c
    UINT32 audChs;      //oft: 30
    UINT32 hdrSize;     //oft: 34
    UINT32 versionCode; //oft: 38
    UINT32 vidPosLen;   //oft: 3c, thisVideoFrmDataLen
    UINT32 vidPosArray;//array of vidPos, vidSize, oft:40

} MOV_NIDXINFO;
#define MP_MOV_NIDX_FIXEDSIZE 0x38 //before vidPosArray, not including junk (8bytes)
//#NT#2012/09/11#Meg Lin -end

typedef struct
{
    UINT32 ouputAddr;
    UINT32 makerLen;
    UINT32 modelLen;
    unsigned char *pMaker;
    unsigned char *pModel;
} MOV_USER_MAKERINFO;
extern UINT32 MOVWrite_UserMakerModelData(MOV_USER_MAKERINFO *pMaker);

#endif//_MOVLIB_H

//@}