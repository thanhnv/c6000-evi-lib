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
#include "../utilities/debug.h"
#include "../include/commands.h"

#include "dm9161.h"


unsigned int DM9161IDGet(unsigned int mdioBaseAddr,
                                  unsigned int phyAddr)
{
    unsigned int id = 0;
    unsigned short data=0;

    /* read the ID1 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_PHYID1, &data);

    /* update the ID1 value */
    id = data << PHY_ID_SHIFT;

    /* read the ID2 register */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_PHYID2, &data);

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
    unsigned short data;

    data = DM9161_RESET;

    /* Reset the phy */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);

    /* wait till the reset bit is auto cleared */
#if 0
    while(data)
    {
        /* Read the reset */
        if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE)
        {
            return FALSE;
        }
        //FDBG("0x%X",data)
    }
#endif
    /* Set the configurations */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, (speed | dulplexMode));

    return TRUE;

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
