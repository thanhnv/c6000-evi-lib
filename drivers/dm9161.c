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
    unsigned short data;
    data = DM9161_RESET;
    /* Reset the phy */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);
    /* wait till the reset bit is auto cleared */
#if 1
    while(data)
    {
        /* Read the reset */
        if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE)
        {
            return ;
        }
    }
#endif
}

unsigned int DM9161LoopBackEnable(unsigned int mdioBaseAddr,unsigned int phyAddr)
{
    unsigned short data;
    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE )
    {
        return FALSE;
    }
    data |= DM9161_LOOPBACK;
    /* Enable loop back */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);
    return TRUE;
}

unsigned int DM9161LoopBackDisable(unsigned int mdioBaseAddr,unsigned int phyAddr)
{
    unsigned short data;
    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE )
    {
        return FALSE;
    }
    data &= ~(DM9161_LOOPBACK);
    /* Enable loop back */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);
    return TRUE;

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
#if 1
    while(data)
    {
        /* Read the reset */
        if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE)
        {
            return FALSE;
        }
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
    volatile unsigned short data, anar;

    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE )
    {
        return FALSE;
    }

    data |= DM9161_AUTONEG;

    /* Enable Auto Negotiation */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);

    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMCR, &data) != TRUE )
    {
        return FALSE;
    }

    /* Write Auto Negotiation capabilities */
    MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_ANAR, &anar);
    anar &= ~0xff10;
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_ANAR, (anar |advVal));

    data |= DM9161_RESTART_AUTONEG;

    /* Start Auto Negotiation */
    MDIOPhyRegWrite(mdioBaseAddr, phyAddr, DM9161_BMCR, data);

    /* Get the auto negotiation status*/
    if(MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMSR, &data) != TRUE)
    {
         return FALSE;
    }

    /* Wait till auto negotiation is complete */
    while(0 == (data & DM9161_AUTONEG_COMP))
    {
         MDIOPhyRegRead(mdioBaseAddr, phyAddr, DM9161_BMSR, &data);
    }

    /* Check if the PHY is able to perform auto negotiation */
    if(data & DM9161_AUTONEG_ABILITY)
    {
         return TRUE;
    }

    return FALSE;
}

unsigned int DM9161RegRead(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   unsigned int regIdx,
                                   unsigned short *regValAdr)
{
	return MDIOPhyRegRead(mdioBaseAddr,phyAddr,regIdx,regValAdr);
}

void DM9161RegWrite(unsigned int mdioBaseAddr,
                             unsigned int phyAddr,
                             unsigned int regIdx,
                             unsigned short regVal)
{
	MDIOPhyRegWrite(mdioBaseAddr,phyAddr,regIdx,regVal);
}

unsigned int DM9161PartnerAbilityGet(unsigned int mdioBaseAddr,
                                              unsigned int phyAddr,
                                              unsigned short *ptnerAblty)
{
	return TRUE;
}

unsigned int DM9161LinkStatusGet(unsigned int mdioBaseAddr,
                                   unsigned int phyAddr,
                                   volatile unsigned int retries)
{
	while(retries){
		MDIOPhyLinkStatusGet(mdioBaseAddr);
		retries--;
	}
	return TRUE;
}
