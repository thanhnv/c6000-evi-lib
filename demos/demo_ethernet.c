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

}

void example_emac()
{
	init_emac();
	unsigned int id;
	id=DM9161IDGet(MDIO_0_REGS,2);
	DBG("0x%X\n",id)
}

