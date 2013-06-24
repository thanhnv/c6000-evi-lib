/*
 * dm9161.c
 *
 *  Created on: Jun 22, 2013
 *      Author: My Life
 */

#include "../include/emac.h"
#include "../include/mdio.h"
#include "../include/interrupt.h"
#include "../include/types.h"
#include "../include/commands.h"

#include "dm9161.h"


unsigned int DM9161IDGet(unsigned int mdioBaseAddr,
                                  unsigned int phyAddr)
{
    unsigned int id = 0;
    unsigned short data;

    /* read the ID1 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_PHYID1, &data);

    /* update the ID1 value */
    id = data << PHY_ID_SHIFT;

    /* read the ID2 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_PHYID1, &data);

    /* update the ID2 value */
    id |= data;

    /* return the ID in ID1:ID2 format */
    return id;
}

void DM9161Reset(unsigned int mdioBaseAddr, unsigned int phyAddr)
{

}

unsigned int DM9161LoopBackEnable(unsigned int mdioBaseAddr,unsigned int phyAddr)
{

}

unsigned int DM9161LoopBackDisable(unsigned int mdioBaseAddr,unsigned int phyAddr)
{

}

unsigned int DM9161Configure(unsigned int mdioBaseAddr,
									  unsigned int phyAddr,
                                      unsigned short speed,
                                      unsigned short dulplexMode)
{

}

unsigned int DM9161AutoNegotiate(unsigned int mdioBaseAddr,
                                          unsigned int phyAddr,
                                          unsigned short advVal)
{

}

unsigned int DM9161RegRead(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   unsigned int regIdx,
                                   unsigned short *regValAdr)
{

}

void DM9161RegWrite(unsigned int mdioBaseAddr,
                             unsigned int phyAddr,
                             unsigned int regIdx,
                             unsigned short regVal)
{

}

unsigned int DM9161PartnerAbilityGet(unsigned int mdioBaseAddr,
                                              unsigned int phyAddr,
                                              unsigned short *ptnerAblty)
{

}

unsigned int DM9161LinkStatusGet(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   volatile unsigned int retries)
{

}
