/**
 * @file pllc.h
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Define some macros, registers, and function prototype to handle PLL module.
 * @see http://www.embeddedvietnam.com
 */

#ifndef PLLC_H_
#define PLLC_H_
#include "types.h"
#define PLL0_BASE       0x01C11000                              /*SYSTEM PLL BASE ADDRESS*/
#define PLL0_REVID      *(unsigned int*) (PLL0_BASE + 0x00)     /*REVID*/
#define PLL0_RSTYPE     *(unsigned int*) (PLL0_BASE + 0xE4)     /*Reset Type status Reg*/
#define PLL0_PLLCTL     *(unsigned int*) (PLL0_BASE + 0x100)    /*PLL Control Register*/
#define PLL0_OCSEL      *(unsigned int*) (PLL0_BASE + 0x104)    /*OBSCLK Select Register*/
#define PLL0_SECCTL     *(unsigned int*) (PLL0_BASE + 0x108)    /*PLL Secondary Control Register*/
#define PLL0_PLLM       *(unsigned int*) (PLL0_BASE + 0x110)    /*PLL Multiplier*/
#define PLL0_PREDIV     *(unsigned int*) (PLL0_BASE + 0x114)    /*Pre divider*/
#define PLL0_PLLDIV1    *(unsigned int*) (PLL0_BASE + 0x118)    /*Diveder-1*/
#define PLL0_PLLDIV2    *(unsigned int*) (PLL0_BASE + 0x11C)    /*Diveder-2*/
#define PLL0_PLLDIV3    *(unsigned int*) (PLL0_BASE + 0x120)    /*Diveder-3*/
#define PLL0_OSCDIV1    *(unsigned int*) (PLL0_BASE + 0x124)    /*Oscilator Divider*/
#define PLL0_POSTDIV    *(unsigned int*) (PLL0_BASE + 0x128)    /*Post Divider*/
#define PLL0_BPDIV      *(unsigned int*) (PLL0_BASE + 0x12C)    /*Bypass Divider*/
#define PLL0_WAKEUP     *(unsigned int*) (PLL0_BASE + 0x130)    /*Wakeup Reg*/
#define PLL0_PLLCMD     *(unsigned int*) (PLL0_BASE + 0x138)    /*Command Reg*/
#define PLL0_PLLSTAT    *(unsigned int*) (PLL0_BASE + 0x13C)    /*Status Reg*/
#define PLL0_ALNCTL     *(unsigned int*) (PLL0_BASE + 0x140)    /*Clock Align Control Reg*/
#define PLL0_DCHANGE    *(unsigned int*) (PLL0_BASE + 0x144)    /*PLLDIV Ratio Chnage status*/
#define PLL0_CKEN       *(unsigned int*) (PLL0_BASE + 0x148)    /*Clock Enable Reg*/
#define PLL0_CKSTAT     *(unsigned int*) (PLL0_BASE + 0x14C)    /*Clock Status Reg*/
#define PLL0_SYSTAT     *(unsigned int*) (PLL0_BASE + 0x150)    /*Sysclk status reg*/
#define PLL0_PLLDIV4    *(unsigned int*) (PLL0_BASE + 0x160)    /*Divider 4*/
#define PLL0_PLLDIV5    *(unsigned int*) (PLL0_BASE + 0x164)    /*Divider 5*/
#define PLL0_PLLDIV6    *(unsigned int*) (PLL0_BASE + 0x168)    /*Divider 6*/
#define PLL0_PLLDIV7    *(unsigned int*) (PLL0_BASE + 0x16C)    /*Divider 7*/
#define PLL0_PLLDIV8    *(unsigned int*) (PLL0_BASE + 0x170)    /*Divider 8*/
#define PLL0_PLLDIV9    *(unsigned int*) (PLL0_BASE + 0x174)    /*Divider 9*/
#define PLL0_PLLDIV10   *(unsigned int*) (PLL0_BASE + 0x178)    /*Divider 10*/
#define PLL0_PLLDIV11   *(unsigned int*) (PLL0_BASE + 0x17C)    /*Divider 11*/
#define PLL0_PLLDIV12   *(unsigned int*) (PLL0_BASE + 0x180)    /*Divider 12*/
#define PLL0_PLLDIV13   *(unsigned int*) (PLL0_BASE + 0x184)    /*Divider 13*/
#define PLL0_PLLDIV14   *(unsigned int*) (PLL0_BASE + 0x188)    /*Divider 14*/
#define PLL0_PLLDIV15   *(unsigned int*) (PLL0_BASE + 0x18C)    /*Divider 15*/
#define PLL0_PLLDIV16   *(unsigned int*) (PLL0_BASE + 0x190)    /*Divider 16*/
#define PLLEN_MUX_SWITCH  4
#define PLL_LOCK_TIME_CNT 2400

/**
 * @author Thanh Nguyen
 * @brief This method is used to set up PLL multiplier.
 * @param multi Multiplier, Crystal = 24MHz, multi=10 ==> DSP core freqency = 24*10/2 = 120MHz.
 * @return Status of setting up.
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 setup_pll(Uint32 multi);

/**
 * @author Thanh Nguyen
 * @brief This method is used to enable module PLL.
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 enable_pll();

/**
 * @author Thanh Nguyen
 * @brief This method is used to disable module PLL.
 * @return Status of disabling PLL, run in by pass schema.
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 disable_pll();

#endif /* PLLC_H_ */
