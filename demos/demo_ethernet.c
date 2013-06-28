/*
 * demo_ethernet.c
 *
 *  Created on: Jun 22, 2013
 *      Author: THANH NGUYEN
 */

#include "../include/timer.h"
#include "../include/uart.h"
#include "../include/emac.h"
#include "../include/mdio.h"
#include "../include/commands.h"
#include "../include/sysconfig.h"
#include "../include/psc.h"
#include "../include/interrupt.h"
#include "../utilities/debug.h"

#include "../drivers/dm9161.h"

void example_emac();
void startup_emac();
void stop_emac();
void init_emac();

void startup_emac()
{
	PSC1_lPSC_enable(0,PSC_EMAC);
}

void stop_emac()
{
	PSC1_lPSC_disable(0,PSC_EMAC);
}

void init_emac()
{
	startup_emac();
	PINMUX11 |= (FMK(SYSCFG_PINMUX11_PINMUX11_7_4,SYSCFG_PINMUX11_PINMUX11_7_4_MDIO_D)|
				FMK(SYSCFG_PINMUX11_PINMUX11_3_0,SYSCFG_PINMUX11_PINMUX11_3_0_MDIO_CLK));
}

void example_emac()
{
	DBG("example_emac 1\n")
	init_emac();
	EMACInit(EMAC_DSC_CTRL_MOD_REG,EMAC_DSC_CONTROL_REG);
	MDIOInit(MDIO_0_REGS,75000000,12500000);

	DM9161Configure(MDIO_0_REGS,0,1,1);

	//EMACRMIISpeedSet(EMAC_DSC_CONTROL_REG,EMAC_RMIISPEED_100MBPS);
	unsigned int id;
	DBG("example_emac 2\n")
	id=DM9161IDGet(MDIO_0_REGS,0);
	DBG("0x%X\n",id)
	unsigned int i=0;
	unsigned short data=0;
	while(i<=24){
		if(MDIOPhyRegRead(MDIO_0_REGS,0,i,&data)==TRUE){
			DBG("%d: 0x%X\n",i,data)
		}else{
			DBG("FAIL %d\n",i,data)
		}
		i++;
	}
}
