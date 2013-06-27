/*
 * mdio.c
 *
 *  Created on: Jun 22, 2013
 *      Author: thanhnv
 */


#include "include/interrupt.h"
#include "include/types.h"
#include "include/commands.h"
#include "include/mdio.h"
#include "utilities/debug.h"
#include <stdbool.h>




/*******************************************************************************
*                       INTERNAL MACRO DEFINITIONS
*******************************************************************************/
#define PHY_REG_MASK                             (0x1Fu)
#define PHY_ADDR_MASK                            (0x1Fu)
#define PHY_DATA_MASK                            (0xFFFFu)
#define PHY_REG_SHIFT                            (21u)
#define PHY_ADDR_SHIFT                           (16u)

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

/**
 * \brief   Reads a PHY register using MDIO.
 *
 * \param   baseAddr      Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 * \param   regNum        Register Number to be read.
 * \param   dataPtr       Pointer where the read value shall be written.
 *
 * \return  status of the read \n
 *          TRUE - read is successful.\n
 *          FALSE - read is not acknowledged properly.
 *
 **/
unsigned int MDIOPhyRegRead(unsigned int baseAddr, unsigned int phyAddr,
                            unsigned int regNum, volatile unsigned short *dataPtr)
{
    /* Wait till transaction completion if any */
	//FDBG("")
    while(HWREG(baseAddr + MDIO_USERACCESS0) & MDIO_USERACCESS0_GO);
	//FDBG("")
    HWREG(baseAddr + MDIO_USERACCESS0)
                           = (MDIO_USERACCESS0_READ | MDIO_USERACCESS0_GO
                              |((regNum & PHY_REG_MASK) << PHY_REG_SHIFT)
                              |((phyAddr & PHY_ADDR_MASK) << PHY_ADDR_SHIFT));
	//FDBG("")
    /* wait for command completion */
    while(HWREG(baseAddr + MDIO_USERACCESS0) & MDIO_USERACCESS0_GO);
	//FDBG("")
    /* Store the data if the read is acknowledged */
    if((HWREG(baseAddr + MDIO_USERACCESS0)) & MDIO_USERACCESS0_ACK)
    {
        *dataPtr = (unsigned short)((HWREG(baseAddr + MDIO_USERACCESS0))
                                    & PHY_DATA_MASK);
       // FDBG("")
        return true;
    }
	//FDBG("")
    return FALSE;
}

/**
 * \brief   Writes a PHY register using MDIO.
 *
 * \param   baseAddr      Base Address of the MDIO Module Registers.
 * \param   phyAddr       PHY Adress.
 * \param   regNum        Register Number to be read.
 * \param   RegVal        Value to be written.
 *
 * \return  None
 *
 **/
void MDIOPhyRegWrite(unsigned int baseAddr, unsigned int phyAddr,
                     unsigned int regNum, unsigned short RegVal)
{
    /* Wait till transaction completion if any */
    while(HWREG(baseAddr + MDIO_USERACCESS0) & MDIO_USERACCESS0_GO);

    HWREG(baseAddr + MDIO_USERACCESS0)
                               = (MDIO_USERACCESS0_WRITE | MDIO_USERACCESS0_GO
                                  |((regNum & PHY_REG_MASK) << PHY_REG_SHIFT)
                                  |((phyAddr & PHY_ADDR_MASK) << PHY_ADDR_SHIFT)
                                  | RegVal);

    /* wait for command completion*/
    while(HWREG(baseAddr + MDIO_USERACCESS0) & MDIO_USERACCESS0_GO);
}
/**
 * \brief   Reads the alive status of all PHY connected to this MDIO.
 *          The bit correponding to the PHY address will be set if the PHY
 *          is alive.
 *
 * \param   baseAddr      Base Address of the MDIO Module Registers.
 *
 * \return  MDIO alive register state
 *
 **/
unsigned int MDIOPhyAliveStatusGet(unsigned int baseAddr)
{
    return (HWREG(baseAddr + MDIO_ALIVE));
}

/**
 * \brief   Reads the link status of all PHY connected to this MDIO.
 *          The bit correponding to the PHY address will be set if the PHY
 *          link is active.
 *
 * \param   baseAddr      Base Address of the MDIO Module Registers.
 *
 * \return  MDIO link register state
 *
 **/
unsigned int MDIOPhyLinkStatusGet(unsigned int baseAddr)
{
    return (HWREG(baseAddr + MDIO_LINK));
}

/**
 * \brief   Initializes the MDIO peripheral. This enables the MDIO state
 *          machine, uses standard pre-amble and set the clock divider value.
 *
 * \param   baseAddr       Base Address of the MDIO Module Registers.
 * \param   mdioInputFreq  The clock input to the MDIO module
 * \param   mdioOutputFreq The clock output required on the MDIO bus
 * \return  None
 *
 **/
void MDIOInit(unsigned int baseAddr, unsigned int mdioInputFreq,
              unsigned int mdioOutputFreq)
{
   unsigned int clkDiv = (mdioInputFreq/mdioOutputFreq) - 1;

   HWREG(baseAddr + MDIO_CONTROL) = ((clkDiv & MDIO_CONTROL_CLKDIV)
                                     | MDIO_CONTROL_ENABLE
                                     | MDIO_CONTROL_PREAMBLE
                                     | MDIO_CONTROL_FAULTENB);
}

/**
 * \brief   Saves the MDIO register context. Note that only MDIO control
 *          register context is saved here.
 *
 * \param   baseAddr       Base Address of the MDIO Module Registers.
 * \param   contextPtr     Pointer to the structure where MDIO context
 *                         needs to be saved.
 * \return  None
 *
 **/
void MDIOContextSave(unsigned int baseAddr, MDIOCONTEXT *contextPtr)
{
    contextPtr->mdioCtrl = HWREG(baseAddr + MDIO_CONTROL);
}

/**
 * \brief   Restores the MDIO register context. Note that only MDIO control
 *          register context is restored here. Hence enough delay shall be
 *          given after this API
 *
 * \param   baseAddr       Base Address of the MDIO Module Registers.
 * \param   contextPtr     Pointer to the structure where MDIO context
 *                         needs to be restored from
 * \return  None
 *
 **/
void MDIOContextRestore(unsigned int baseAddr, MDIOCONTEXT *contextPtr)
{
    HWREG(baseAddr + MDIO_CONTROL) = contextPtr->mdioCtrl;
}

/***************************** End Of File ***********************************/

