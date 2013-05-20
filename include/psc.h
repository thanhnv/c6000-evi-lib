/*
 * psc.h
 *
 *  Created on: May 9, 2013
 *      Author: NGUYEN
 */

#ifndef PSC_H_
#define PSC_H_

#include "types.h"
/*PSC Module Related Registers*/
#define PSC0_BASE       0x01C10000
#define PSC1_BASE       0x01E27000

#define PSC0_MDCTL      (PSC0_BASE+0xA00)
#define PSC0_MDSTAT     (PSC0_BASE+0x800)
#define PSC0_PTCMD      *(unsigned int*) (PSC0_BASE + 0x120)
#define PSC0_PTSTAT     *(unsigned int*) (PSC0_BASE + 0x128)

#define PSC1_MDCTL      (PSC1_BASE+0xA00)
#define PSC1_MDSTAT     (PSC1_BASE+0x800)
#define PSC1_PTCMD      *(unsigned int*) (PSC1_BASE + 0x120)
#define PSC1_PTSTAT     *(unsigned int*) (PSC1_BASE + 0x128)

/* Peripherals in PSC0                                                        */

#define		PSC_CC               0
#define		PSC_TC0              1
#define		PSC_TC1              2
#define		PSC_EMIFA            3
#define		PSC_SPI0             4
#define		PSC_MMCSD0           5
#define		PSC_AINTC            6
#define		PSC_ARM_RAMROM       7
#define		PSC_SECCNTL_KEYMGR   8
#define		PSC_UART0            9
#define		PSC_SCR0_SS          10
#define		PSC_SCR1_SS          11
#define		PSC_SCR2_SS          12
#define		PSC_RESV0            13
#define		PSC_ARM              14
#define		PSC_DSP              15

/* Peripherals in PSC1                                                       */

#define		PSC_USB0			(1)
#define		PSC_USB1			(2)
#define		PSC_GPIO			(3)
#define		PSC_UHPI			(4)
#define		PSC_EMAC			(5)
#define		PSC_EMIFB			(6)
#define		PSC_MCASP0			7
#define		PSC_MCASP1       	8
#define		PSC_MCASP2       	9
#define		PSC_SPI1         	10
#define		PSC_I2C1         	11
#define		PSC_UART1        	12
#define		PSC_UART2        	13
#define		PSC_LCDC         	16
#define		PSC_EHRPWM0_1_2  	17
#define		PSC_ECAP0_1_2    	20
#define		PSC_EQEP0_1_2    	21
#define		PSC_SCR8_SS      	24
#define		PSC_SCR7_SS      	25
#define		PSC_SCR12_SS     	26
#define		PSC_SHRAM        	31

#define		LPSC_INSTANCE_MAX            2u
#define		LPSC_NUMBER_MAX              32u
/**
 *@brief This function is used to Power up a module that is handled by PSC0.
 *@param PD bit position of PTCMD register.
 *@param LPSC_num ID of module.
 *@see #PSC_CC,#PSC_TC0,#PSC_UART0...
 *@return status of powering up. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 PSC0_lPSC_enable(unsigned int PD, unsigned int LPSC_num);

/**
 *@brief This function is used to Power up a module that is handled by PSC1.
 *@param PD bit position of PTCMD register.
 *@param LPSC_num ID of module.
 *@see #PSC_USB0,#PSC_USB1,#PSC_UART1...
 *@return status of powering up. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 PSC1_lPSC_enable(unsigned int PD, unsigned int LPSC_num);

/**
 *@brief This function is used to Power down a module that is handled by PSC0.
 *@param PD bit position of PTCMD register.
 *@param LPSC_num ID of module.
 *@see #PSC_CC,#PSC_TC0,#PSC_UART0...
 *@return status of powering down. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 PSC0_lPSC_disable(unsigned int PD, unsigned int LPSC_num);

/**
 *@brief This function is used to Power down a module that is handled by PSC1.
 *@param PD bit position of PTCMD register.
 *@param LPSC_num ID of module.
 *@see #PSC_USB0,#PSC_USB1,#PSC_UART1...
 *@return status of powering down. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 PSC1_lPSC_disable(unsigned int PD, unsigned int LPSC_num);

#endif /* PSC_H_ */
