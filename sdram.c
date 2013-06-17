/**
 * @file sdram.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Configure SDRAM (external sdram).
 * @see http://www.embeddedvietnam.com
 */


#include <include/emifb.h>
#include <include/commands.h>
#include <include/sysconfig.h>
#include <include/psc.h>
/**
*@brief Setup/Initial external SDRAM.
*@return Status of configuration.
*@see #CONFIG_SDRAM_FAIL,#CONFIG_SDRAM_FINSH,...
*/
Int32 config_sdram()
{
    KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
    KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)

    PINMUX0  = 0x11111188;  // EMIFB, Check EMU0/RTCK
    PINMUX1  = 0x11111111;  // EMIFB
    PINMUX2  = 0x11111111;  // EMIFB
    PINMUX3  = 0x11111111;  // EMIFB
    PINMUX4  = 0x11111111;  // EMIFB
    PINMUX5  = 0x11111111;  // EMIFB
    PINMUX6  = 0x11111111;  // EMIFB
    PINMUX7  = 0x11111111;  // EMIFB, SPI0

    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
        |( 1 << 15)         // Unlock timing registers
        |( 1 << 14)         // 16Bits
        |( 2 << 9 )         // CAS latency is 3
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 2 << 0 );        // 1024-word pages requiring 10 column address bits

    EMIFB_SDREF = 0         // SDRAM Refresh Control Register
        |( 0 << 31)         // Low power mode disabled
        |( 0 << 30)         // MCLK stoping disabled
        |( 0 << 23)         // Selects self refresh instead of power down
        |( 1040 <<0);       // Refresh rate = 7812.5ns / 7.5ns

    EMIFB_SDTIM1 = 0        // SDRAM Timing Register 1
        |( 25 << 25)        // (67.5ns / 7.55ns) - 1 = TRFC  @ 133MHz
        |( 2 << 22 )        // (20ns / 7.5ns) - 1 =TRP
        |( 2 << 19 )        // (20ns / 7.5ns) - 1 = TRCD
        |( 1 << 16 )        // (14ns / 7.5ns) - 1 = TWR
        |( 5 << 11 )        // (45ns / 7.5ns) - 1 = TRAS
        |( 8 <<  6 )        // (67.5ns / 7.5ns) - 1 = TRC
        |( 2 <<  3 );       // *(((4 * 14ns) + (2 * 7.5ns)) / (4 * 7.5ns)) -1. = TRRD
                            // but it says to use this formula if 8 banks but only 4 are used here.
                            // and SDCFG1 register only supports upto 4 banks.

    EMIFB_SDTIM2 = 0        // SDRAM Timing Register 2
        |( 14<< 27)         // not sure how they got this number. the datasheet says value should be
                            // "Maximum number of refresh_rate intervals from Activate to Precharge command"
                            // but has no equation. TRASMAX is 120k.
        |( 9 << 16)         // ( 70 / 7.5) - 1
        |( 5 << 0 );        // ( 45 / 7.5 ) - 1

    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
        |( 1 << 16)
        |( 0 << 15)         // Unlock timing registers
        |( 1 << 14)         // Unlock timing registers
        |( 2 << 9 )         // CAS latency is 3
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 2 << 0 );        // 1024-word pages requiring 10 column address bits
	return 1;
}
/**
*@brief Enable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 enable_sdram()
{
	PSC1_lPSC_enable(0,PSC_EMIFB);
	return 1;
}

/**
*@brief Disable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 disable_sdram()
{
    KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
    KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)

    PINMUX0  = 0x00000000;  // EMIFB, Check EMU0/RTCK
    PINMUX1  = 0x00000000;  // EMIFB
    PINMUX2  = 0x00000000;  // EMIFB
    PINMUX3  = 0x00000000;  // EMIFB
    PINMUX4  = 0x00000000;  // EMIFB
    PINMUX5  = 0x00000000;  // EMIFB
    PINMUX6  = 0x00000000;  // EMIFB
    PINMUX7  = 0x00000000;  // EMIFB, SPI0

	PSC1_lPSC_disable(0,PSC_EMIFB);
	return 1;
}

/**
*@brief Power up module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_up_sdram()
{
	PSC1_lPSC_enable(0,PSC_EMIFB);
	return 1;
}

/**
*@brief Power down module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_down_sdram()
{
	PSC1_lPSC_disable(0,PSC_EMIFB);
	return 1;
}

#define SDRAM_HEAP 4
#if (SDRAM_HEAP == 1)
typedef unsigned char SDRAM_DATA_TYPE;
#define VALUE_PATTERN 0xFF
#elif (SDRAM_HEAP == 2)
typedef unsigned short SDRAM_DATA_TYPE;
#define VALUE_PATTERN 0xFFFF
#elif (SDRAM_HEAP == 4)
typedef unsigned int SDRAM_DATA_TYPE;
#define VALUE_PATTERN 0xAAAAAAAA
#else
#undef SDRAM_HEAP
#define SDRAM_HEAP 4
typedef unsigned int SDRAM_DATA_TYPE;
#define VALUE_PATTERN 0xFFFFFFFF
#endif

#include <stdio.h>
#include <string.h>
#include "utilities/debug.h"
int example_sdram()
{
	enable_sdram();
	config_sdram();

	unsigned int base_addr = 0xC0000000;
	unsigned int i=0;
	volatile SDRAM_DATA_TYPE * position = (SDRAM_DATA_TYPE*)base_addr;
	volatile SDRAM_DATA_TYPE r,w;
	while(1){
		memset((void*)position,0xAA,32*1024*1024);
		DBG("W\n");
		memcpy((void*)((unsigned int)position+32*1024*1024),(void*)position,32*1024*1024);
		DBG("C\n");
	}
	//return 0;
	__START:
	i=0;
	position=(SDRAM_DATA_TYPE*)base_addr;
	while(i < (64 *1024 * 1024 )){
		//position
		//DBG("next page %d\n",i);
		//for(j=0;j<(0x100 / SDRAM_HEAP);j++){
#if 1
			*position=i/4;
			//sw_sleep(10);
			r=(*position);
//			if( r==i/4){
//				//printf("0x%x  ==> 0x%x\n",position,(*position));
//			}else{
//				DBG("Fail 0x%x  ==> 0x%X\n",position,r);
//			}
			position++;
		//}
			i+=4;
#endif

	}
	DBG("Finish: %d; 0x%X\n",i,position);
	goto __START;
}
