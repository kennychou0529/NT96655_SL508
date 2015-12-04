//#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <String.h>
#include "Debug.h"
#include "type.h"
#include "ErrorNo.h"

#include "Debug.h"
#include "Cache.h"
#include "dma.h"
#include "spi.h"
#include "SysKer.h"
#include "Delay.h"
#include "rtc.h"
#include "gpio.h"

#include "Gpio_i2c.h"

#if 1
#define DEBUG_MSG(msg)    debug_msg msg
#else
#define DEBUG_MSG(msg)
#endif

//delay time
#if 1
#define I2C_DELAY Delay_DelayUs(4)
#define I2C_DELAY_LONG Delay_DelayUs(20)
#else
#define I2C_DELAY delay(800)
#define I2C_DELAY_LONG delay(4000)
#endif
#define tmp_dev_addr 0xC0
#define tmp_sub_addr 0xA0
#define RAND_MAX_NUM 100

//static variable
static ENDE_DEVICE_OBJ ENDE_DeviceObj;

static void delay(UINT32 times)
{
    for(;times > 0; times--)
        ;
}


BOOL EnDeFunction(void)
{
    //8字节随机数
    UINT8 randata[8]={0x29,0xf5,0x25,0xf3,0xaa,0x6f,0x84,0xe9};
    //10字节加密后的数据
    UINT8 returndata[8]={0};
    UINT8 tmpdata[8]={0};
    //8字节解密后的数据
    UINT8 exdata[8]={0};

    UINT8 a;
    UINT8 b;
    UINT8 c;
    UINT8 d;
    UINT8 e;
    UINT8 f;
    UINT8 g;
    UINT8 h;

    UINT8 i=0;
    UINT8 j=0;

    RTC_TIME  curTime;

    curTime = rtc_getTime();
    //sprintf(pFileName,"%02d%02d",curTime.s.hour,curTime.s.minute);
    //srand( (UINT8)time( NULL ) );
    srand( (UINT8)(curTime.s.second) );

    #if 1
    for(i=0;i<8;i++)
    {
        randata[i]=1+(UINT8)(100.0*rand()/(RAND_MAX_NUM+1.0));
        //DEBUG_MSG(("EnDeFunction================================> %x\r\n",randata[i]));
        DEBUG_MSG(("EnDeFunction================================> %x\r\n",randata[i]));
    }
	#else
    for(i=0;i<8;i++)
    {
        //randata[i]= i;
        DEBUG_MSG(("EnDeFunction================================> %x\r\n",randata[i]));
        //DEBUG_MSG(("Send================================> %x\r\n",randata[i]));
    }		
    #endif

    if(randata[0]==0xC1)
    {
        randata[0] = 0xBB;
    }
    a = randata[0];
    b = randata[1];
    c = randata[2];
    d = randata[3];
    e = randata[4];
    f = randata[5];
    g = randata[6];
    h = randata[7];

    tmpdata[0] = a*b;//3d
    tmpdata[1] = b-h;//0c
    tmpdata[2] = c+d;//18
    tmpdata[3] = e*c;//92
    tmpdata[4] = a-c;//04
    tmpdata[5] = b+f;//64
    tmpdata[6] = f*h;//07
    tmpdata[7] = a-e;//7f

    for(i=0;i<8;i++)
    {
        //DEBUG_MSG(("tmpdata================================>Err %x\r\n",randata[i]));
        DEBUG_MSG(("tmpdata===============%d=================>tmpdata %x\r\n",i, tmpdata[i]));
    }
    _i2c_write(tmp_dev_addr, tmp_sub_addr,randata, 8);
    Delay_DelayMs(30);
    _i2c_read(tmp_dev_addr, tmp_sub_addr,returndata, 8);

    for(i=0;i<8;i++)
    {
        //returndata[i]= i;
        DEBUG_MSG(("Read=================%d===============> %x\r\n",i, returndata[i]));
    }

    //比较原始数据randata与解密出来的exdata
    for(j=0;j<8;j++)
    {
        if(tmpdata[j] !=returndata[j])
        {
            DEBUG_MSG(("EnDeFunction================================>%d\r\n",j));
            break;
        }
        else
        {
            DEBUG_MSG(("EnDeFunction================================>ok %d\r\n",j));
        }
    }
    if(j==8)
    {
        DEBUG_MSG(("EnDeFunction================================>ok\r\n"));
		return TRUE;
    }
    else
    {
        DEBUG_MSG(("EnDeFunction================================>Err\r\n"));
        return FALSE;
    }
}

void InitEnDecry(ENDE_DEVICE_OBJ *endedeviceobj)
{
    ENDE_DeviceObj = *endedeviceobj;
	
    gpio_setDir(ENDE_DeviceObj.ENDECtrl_Pin.uigpio_clk, GPIO_DIR_OUTPUT);
    gpio_setDir(ENDE_DeviceObj.ENDECtrl_Pin.uigpio_data, GPIO_DIR_OUTPUT);

	gpio_setPin(ENDE_DeviceObj.ENDECtrl_Pin.uigpio_clk);
	gpio_setPin(ENDE_DeviceObj.ENDECtrl_Pin.uigpio_data);	
}

void _i2c_start(void)
{

	DEBUG_MSG(("<<=====================_i2c_start=======================>>\r\n"));
	SDA_HIGH;
	I2C_DELAY;
	I2C_DELAY;
	SCL_HIGH;
	I2C_DELAY;
	I2C_DELAY;
	SDA_LOW;
	I2C_DELAY;
	SCL_LOW;
	I2C_DELAY;
}

void _i2c_stop(void)
{
	
	DEBUG_MSG(("<<=====================_i2c_stop=======================>>\r\n"));
	
	SDA_LOW;
	I2C_DELAY;
	SCL_HIGH;
	I2C_DELAY;
	SDA_HIGH;
	I2C_DELAY_LONG;
}

unsigned char _i2c_ack_detect(void)
{

	DEBUG_MSG(("<<=====================_i2c_ack_detect=======================>>\r\n"));

	SDA_HIGH;
	I2C_DELAY;
	SDA_IN; // SDA Input Mode
	SCL_HIGH;
	I2C_DELAY_LONG;//Jason
	I2C_DELAY_LONG;

	if (SDA_DETECT)
	{
		SDA_OUT;
		DEBUG_MSG(("<<=====================Ack Error!=======================>>\r\n"));
		return ERROR_CODE_FALSE; // false
	}

	I2C_DELAY;
	SCL_LOW;
	I2C_DELAY;
	SDA_OUT;
	return ERROR_CODE_TRUE; // true
}

void _i2c_ack_send(void)
{

	DEBUG_MSG(("<<=====================_i2c_ack_send=======================>>\r\n"));

	SDA_LOW;
	I2C_DELAY;
	SCL_HIGH;
	I2C_DELAY;
	SCL_LOW;
	I2C_DELAY;
}
unsigned char _i2c_write_byte(unsigned char data)
{
	unsigned char i;

	DEBUG_MSG(("<<=====================_i2c_write_byte=======================>>\r\n"));
	I2C_DELAY;
	for(i = 0; i< 8; i++)
	{
		if( (data << i) & 0x80) SDA_HIGH;
		else SDA_LOW;
		I2C_DELAY;
		SCL_HIGH;
		I2C_DELAY;
		SCL_LOW;
		I2C_DELAY;
	}

	if(_i2c_ack_detect())
	{
		DEBUG_MSG(("<<=====================Acknoledge Error=======================>>\r\n"));
		return ERROR_CODE_FALSE;
	}
	return ERROR_CODE_TRUE;
}

unsigned char _i2c_read_byte(void)
{
	unsigned char i, data;

	DEBUG_MSG(("<<=====================_i2c_read_byte=======================>>\r\n"));

	data = 0;
	//SDA_HIGH;
	I2C_DELAY;
	SDA_IN;
	for(i = 0; i< 8; i++)
	{
		data <<= 1;
		I2C_DELAY;
		SCL_HIGH;
		I2C_DELAY_LONG;
		I2C_DELAY_LONG;
		if (SDA_DETECT) data |= 0x01;
		SCL_LOW;
		I2C_DELAY;
	}
	SDA_OUT;
	_i2c_ack_send();
	return data;
}

unsigned char _i2c_write(unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	unsigned char i;

	DEBUG_MSG(("<<=====================_i2c_write=======================>>\r\n"));

	_i2c_start();
	I2C_DELAY;
	if(_i2c_write_byte(device_addr)) {
		_i2c_stop();
		DEBUG_MSG(("<<=====================Write Error - Addr=======================>>\r\n"));
		return ERROR_CODE_WRITE_ADDR;
	}
	if(_i2c_write_byte(sub_addr)) {
		_i2c_stop();
		DEBUG_MSG(("<<=====================Write Error - Addr=======================>>\r\n"));
		return ERROR_CODE_WRITE_ADDR;
	}
	for(i = 0; i<ByteNo; i++) {
		if(_i2c_write_byte(buff[i])) {
			_i2c_stop();
			DEBUG_MSG(("<<=====================Write Error - Data=======================>>\r\n"));
			return ERROR_CODE_WRITE_DATA;
		}
	}
	I2C_DELAY;
	_i2c_stop();
	I2C_DELAY_LONG;
	return ERROR_CODE_TRUE;
}

unsigned char _i2c_read(unsigned char device_addr, unsigned char sub_addr, unsigned char *buff, int ByteNo)
{
	unsigned char i;

	DEBUG_MSG(("<<=====================_i2c_read=======================>>\r\n"));	
	I2C_DELAY_LONG;
	_i2c_start();
	I2C_DELAY;
	if(_i2c_write_byte(device_addr)) {
		_i2c_stop();
		DEBUG_MSG(("<<=====================Write Error - Addr=======================>>\r\n"));
		return ERROR_CODE_READ_ADDR;
	}
	if(_i2c_write_byte(sub_addr)) {
		_i2c_stop();
		DEBUG_MSG(("<<=====================Write Error - Addr=======================>>\r\n"));
		return ERROR_CODE_READ_ADDR;
	}
	_i2c_start();
	I2C_DELAY;
	if(_i2c_write_byte(device_addr+1)) {
		_i2c_stop();
		DEBUG_MSG(("<<=====================Write Error - Addr=======================>>\r\n"));
		return ERROR_CODE_READ_ADDR;
	}
	for(i = 0; i<ByteNo; i++) buff[i] = _i2c_read_byte();
	
	I2C_DELAY;
	_i2c_stop();
	I2C_DELAY_LONG;
	return ERROR_CODE_TRUE;
}

