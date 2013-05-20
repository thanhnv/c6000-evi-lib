/*
 * emifb.h
 *
 *  Created on: May 9, 2013
 *      Author: NGUYEN
 */

#ifndef EMIFB_H_
#define EMIFB_H_
#include "types.h"
#define EMIFB_BASE              0xB0000000 /**<Begin of EMIFB configure registers*/
#define EMIFB_SDSTAT            *(unsigned int*)(EMIFB_BASE + 0x04)    /**<SDRAM Status Register*/
#define EMIFB_SDCFG             *(unsigned int*)(EMIFB_BASE + 0x08)    /**<SDRAM Bank Config Register*/
#define EMIFB_SDREF             *(unsigned int*)(EMIFB_BASE + 0x0C)    /**<SDRAM Refresh Control Register*/
#define EMIFB_SDTIM1            *(unsigned int*)(EMIFB_BASE + 0x10)    /**<SDRAM Timing Register*/
#define EMIFB_SDTIM2            *(unsigned int*)(EMIFB_BASE + 0x14)    /**<SDRAM Timing Register*/

enum _configure_sdram_st{
	CONFIG_SDRAM_FAIL=0, /**<Configure failed, SDRAM can not be used.*/
	CONFIG_SDRAM_FINSH, /**<Configure well, SDRAM can be used.*/
	CONFIG_SDRAM_SUSPEND /**<Configuring and wait for return status.*/
};

/**
*@brief Setup/Initial external SDRAM.
*@return Status of configuration.
*@see #CONFIG_SDRAM_FAIL,#CONFIG_SDRAM_FINSH,...
*/
Int32 config_sdram();
/**
*@brief Enable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 enable_sdram();
/**
*@brief Disable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 disable_sdram();
/**
*@brief Power up module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_up_sdram();
/**
*@brief Power down module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_down_sdram();

#endif /* EMIFB_H_ */
