/**
 * @file uart.h
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 16, 2013
 * @brief Define some macros, registers and prototypes of functions that are used to handle UART module.
 * @see http://www.embeddedvietnam.com
 */

#ifndef __UART_H
#define __UART_H
#include "types.h"
#include "memories.h"
#ifdef UART_0_REGS
#undef UART_0_REGS
#endif

#ifdef UART_1_REGS
#undef UART_1_REGS
#endif

#ifdef UART_2_REGS
#undef UART_2_REGS
#endif

#define UART_0_REGS                     (0x01C42000u)
#define UART_1_REGS                     (0x01D0C000u)
#define UART_2_REGS                     (0x01D0D000u)

#define		UART_0_RBR					*(unsigned int *)(UART_0_REGS+0x000u)	/*receiver register - RW*/
#define		UART_0_THR					*(unsigned int *)(UART_0_REGS+0x000u)	/*transmitter register - RW*/
#define		UART_0_IER					*(unsigned int *)(UART_0_REGS+0x004u)	/*Interrupt enable register - RW*/
#define		UART_0_IIR					*(unsigned int *)(UART_0_REGS+0x008u)	/*Interrupt Identification Register - RO*/
#define		UART_0_FCR					*(unsigned int *)(UART_0_REGS+0x008u)	/*FIFO Control Register - RW*/
#define		UART_0_LCR					*(unsigned int *)(UART_0_REGS+0x00Cu)	/*Line control register - RW*/
#define		UART_0_MCR					*(unsigned int *)(UART_0_REGS+0x010u)	/*Modem control register	- RW*/
#define		UART_0_LSR					*(unsigned int *)(UART_0_REGS+0x014u)	/*Line status register	- RO*/
#define		UART_0_MSR					*(unsigned int *)(UART_0_REGS+0x018u)	/*Modem status register - RO*/
#define		UART_0_SCR					*(unsigned int *)(UART_0_REGS+0x01Cu)	/*Scratch pad register*/
#define		UART_0_DLL					*(unsigned int *)(UART_0_REGS+0x020u)	/*Divisor LSB latch - RW*/
#define		UART_0_DLH					*(unsigned int *)(UART_0_REGS+0x024u)	/*Divisor MSB latch	- RW*/
#define		UART_0_REVID1				*(unsigned int *)(UART_0_REGS+0x028u)	/*Revision id 1*/
#define		UART_0_REVID2				*(unsigned int *)(UART_0_REGS+0x02Cu)	/*Revision id 2*/
#define		UART_0_PWREMU_MGMT			*(unsigned int *)(UART_0_REGS+0x030u)	/*Power management register - RW*/
#define		UART_0_MDR					*(unsigned int *)(UART_0_REGS+0x034u)	/*Mode definition register*/

#define		UART_1_RBR					*(unsigned int *)(UART_1_REGS+0x000u)
#define		UART_1_THR					*(unsigned int *)(UART_1_REGS+0x000u) 
#define		UART_1_IER					*(unsigned int *)(UART_1_REGS+0x004u)
#define		UART_1_IIR					*(unsigned int *)(UART_1_REGS+0x008u)
#define		UART_1_FCR					*(unsigned int *)(UART_1_REGS+0x008u) 
#define		UART_1_LCR					*(unsigned int *)(UART_1_REGS+0x00Cu)
#define		UART_1_MCR					*(unsigned int *)(UART_1_REGS+0x010u)
#define		UART_1_LSR					*(unsigned int *)(UART_1_REGS+0x014u)
#define		UART_1_MSR					*(unsigned int *)(UART_1_REGS+0x018u)
#define		UART_1_SCR					*(unsigned int *)(UART_1_REGS+0x01Cu)
#define		UART_1_DLL					*(unsigned int *)(UART_1_REGS+0x020u)
#define		UART_1_DLH					*(unsigned int *)(UART_1_REGS+0x024u)
#define		UART_1_REVID1				*(unsigned int *)(UART_1_REGS+0x028u)
#define		UART_1_REVID2				*(unsigned int *)(UART_1_REGS+0x02Cu)
#define		UART_1_PWREMU_MGMT			*(unsigned int *)(UART_1_REGS+0x030u)
#define		UART_1_MDR					*(unsigned int *)(UART_1_REGS+0x034u)

#define		UART_2_RBR					*(unsigned int *)(UART_2_REGS+0x000u)
#define		UART_2_THR					*(unsigned int *)(UART_2_REGS+0x000u) 
#define		UART_2_IER					*(unsigned int *)(UART_2_REGS+0x004u)
#define		UART_2_IIR					*(unsigned int *)(UART_2_REGS+0x008u)
#define		UART_2_FCR					*(unsigned int *)(UART_2_REGS+0x008u) 
#define		UART_2_LCR					*(unsigned int *)(UART_2_REGS+0x00Cu)
#define		UART_2_MCR					*(unsigned int *)(UART_2_REGS+0x010u)
#define		UART_2_LSR					*(unsigned int *)(UART_2_REGS+0x014u)
#define		UART_2_MSR					*(unsigned int *)(UART_2_REGS+0x018u)
#define		UART_2_SCR					*(unsigned int *)(UART_2_REGS+0x01Cu)
#define		UART_2_DLL					*(unsigned int *)(UART_2_REGS+0x020u)
#define		UART_2_DLH					*(unsigned int *)(UART_2_REGS+0x024u)
#define		UART_2_REVID1				*(unsigned int *)(UART_2_REGS+0x028u)
#define		UART_2_REVID2				*(unsigned int *)(UART_2_REGS+0x02Cu)
#define		UART_2_PWREMU_MGMT			*(unsigned int *)(UART_2_REGS+0x030u)
#define		UART_2_MDR					*(unsigned int *)(UART_2_REGS+0x034u)



/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* RBR */


#define UART_RBR_DATA_MASK           (0x000000FFu)
#define UART_RBR_DATA_SHIFT          (0x00000000u)
#define UART_RBR_DATA_RESETVAL       (0x00000000u)

#define UART_RBR_RESETVAL            (0x00000000u)

/* THR */


#define UART_THR_DATA_MASK           (0x000000FFu)
#define UART_THR_DATA_SHIFT          (0x00000000u)
#define UART_THR_DATA_RESETVAL       (0x00000000u)

#define UART_THR_RESETVAL            (0x00000000u)

/* IER */


#define UART_IER_EDSSI_MASK          (0x00000008u)
#define UART_IER_EDSSI_SHIFT         (0x00000003u)
#define UART_IER_EDSSI_RESETVAL      (0x00000000u)
/*----EDSSI Tokens----*/
#define UART_IER_EDSSI_DISABLE       (0x00000000u)
#define UART_IER_EDSSI_ENABLE        (0x00000001u)

#define UART_IER_ELSI_MASK           (0x00000004u)
#define UART_IER_ELSI_SHIFT          (0x00000002u)
#define UART_IER_ELSI_RESETVAL       (0x00000000u)
/*----ELSI Tokens----*/
#define UART_IER_ELSI_DISABLE        (0x00000000u)
#define UART_IER_ELSI_ENABLE         (0x00000001u)

#define UART_IER_ETBEI_MASK          (0x00000002u)
#define UART_IER_ETBEI_SHIFT         (0x00000001u)
#define UART_IER_ETBEI_RESETVAL      (0x00000000u)
/*----ETBEI Tokens----*/
#define UART_IER_ETBEI_DISABLE       (0x00000000u)
#define UART_IER_ETBEI_ENABLE        (0x00000001u)

#define UART_IER_ERBI_MASK           (0x00000001u)
#define UART_IER_ERBI_SHIFT          (0x00000000u)
#define UART_IER_ERBI_RESETVAL       (0x00000000u)
/*----ERBI Tokens----*/
#define UART_IER_ERBI_DISABLE        (0x00000000u)
#define UART_IER_ERBI_ENABLE         (0x00000001u)

#define UART_IER_RESETVAL            (0x00000000u)

/* IIR */


#define UART_IIR_FIFOEN_MASK         (0x000000C0u)
#define UART_IIR_FIFOEN_SHIFT        (0x00000006u)
#define UART_IIR_FIFOEN_RESETVAL     (0x00000000u)
/*----FIFOEN Tokens----*/
#define UART_IIR_FIFOEN_DISABLE      (0x00000000u)
#define UART_IIR_FIFOEN_ENABLE       (0x00000003u)


#define UART_IIR_INTID_MASK          (0x0000000Eu)
#define UART_IIR_INTID_SHIFT         (0x00000001u)
#define UART_IIR_INTID_RESETVAL      (0x00000000u)
/*----INTID Tokens----*/
#define UART_IIR_INTID_MODSTAT       (0x00000000u)
#define UART_IIR_INTID_THRE          (0x00000001u)
#define UART_IIR_INTID_RDA           (0x00000002u)
#define UART_IIR_INTID_RLS           (0x00000003u)
#define UART_IIR_INTID_CTI           (0x00000006u)

#define UART_IIR_IPEND_MASK          (0x00000001u)
#define UART_IIR_IPEND_SHIFT         (0x00000000u)
#define UART_IIR_IPEND_RESETVAL      (0x00000001u)
/*----IPEND Tokens----*/
#define UART_IIR_IPEND_PEND          (0x00000000u)
#define UART_IIR_IPEND_NO_PEND       (0x00000001u)

#define UART_IIR_RESETVAL            (0x00000001u)

/* FCR */


#define UART_FCR_RXFIFTL_MASK        (0x000000C0u)
#define UART_FCR_RXFIFTL_SHIFT       (0x00000006u)
#define UART_FCR_RXFIFTL_RESETVAL    (0x00000000u)
/*----RXFIFTL Tokens----*/
#define UART_FCR_RXFIFTL_CHAR1       (0x00000000u)
#define UART_FCR_RXFIFTL_CHAR4       (0x00000001u)
#define UART_FCR_RXFIFTL_CHAR8       (0x00000002u)
#define UART_FCR_RXFIFTL_CHAR14      (0x00000003u)


#define UART_FCR_DMAMODE1_MASK       (0x00000008u)
#define UART_FCR_DMAMODE1_SHIFT      (0x00000003u)
#define UART_FCR_DMAMODE1_RESETVAL   (0x00000000u)
/*----DMAMODE1 Tokens----*/
#define UART_FCR_DMAMODE1_DISABLE    (0x00000000u)
#define UART_FCR_DMAMODE1_ENABLE     (0x00000001u)

#define UART_FCR_TXCLR_MASK          (0x00000004u)
#define UART_FCR_TXCLR_SHIFT         (0x00000002u)
#define UART_FCR_TXCLR_RESETVAL      (0x00000000u)
/*----TXCLR Tokens----*/
#define UART_FCR_TXCLR_CLR           (0x00000001u)

#define UART_FCR_RXCLR_MASK          (0x00000002u)
#define UART_FCR_RXCLR_SHIFT         (0x00000001u)
#define UART_FCR_RXCLR_RESETVAL      (0x00000000u)
/*----RXCLR Tokens----*/
#define UART_FCR_RXCLR_CLR           (0x00000001u)

#define UART_FCR_FIFOEN_MASK         (0x00000001u)
#define UART_FCR_FIFOEN_SHIFT        (0x00000000u)
#define UART_FCR_FIFOEN_RESETVAL     (0x00000000u)
/*----FIFOEN Tokens----*/
#define UART_FCR_FIFOEN_DISABLE      (0x00000000u)
#define UART_FCR_FIFOEN_ENABLE       (0x00000001u)

#define UART_FCR_RESETVAL            (0x00000000u)

/* LCR */


#define UART_LCR_DLAB_MASK           (0x00000080u)
#define UART_LCR_DLAB_SHIFT          (0x00000007u)
#define UART_LCR_DLAB_RESETVAL       (0x00000000u)
/*----DLAB Tokens----*/
#define UART_LCR_DLAB_DISABLE        (0x00000000u)
#define UART_LCR_DLAB_ENABLE         (0x00000001u)

#define UART_LCR_BC_MASK             (0x00000040u)
#define UART_LCR_BC_SHIFT            (0x00000006u)
#define UART_LCR_BC_RESETVAL         (0x00000000u)
/*----BC Tokens----*/
#define UART_LCR_BC_DISABLE          (0x00000000u)
#define UART_LCR_BC_ENABLE           (0x00000001u)

#define UART_LCR_SP_MASK             (0x00000020u)
#define UART_LCR_SP_SHIFT            (0x00000005u)
#define UART_LCR_SP_RESETVAL         (0x00000000u)
/*----SP Tokens----*/
#define UART_LCR_SP_DISABLE          (0x00000000u)
#define UART_LCR_SP_ENABLE           (0x00000001u)

#define UART_LCR_EPS_MASK            (0x00000010u)
#define UART_LCR_EPS_SHIFT           (0x00000004u)
#define UART_LCR_EPS_RESETVAL        (0x00000000u)
/*----EPS Tokens----*/
#define UART_LCR_EPS_ODD             (0x00000000u)
#define UART_LCR_EPS_EVEN            (0x00000001u)

#define UART_LCR_PEN_MASK            (0x00000008u)
#define UART_LCR_PEN_SHIFT           (0x00000003u)
#define UART_LCR_PEN_RESETVAL        (0x00000000u)
/*----PEN Tokens----*/
#define UART_LCR_PEN_DISABLE         (0x00000000u)
#define UART_LCR_PEN_ENABLE          (0x00000001u)

#define UART_LCR_STB_MASK            (0x00000004u)
#define UART_LCR_STB_SHIFT           (0x00000002u)
#define UART_LCR_STB_RESETVAL        (0x00000000u)
/*----STB Tokens----*/
#define UART_LCR_STB_1BIT            (0x00000000u)
#define UART_LCR_STB_WLS             (0x00000001u)

#define UART_LCR_WLS_MASK            (0x00000003u)
#define UART_LCR_WLS_SHIFT           (0x00000000u)
#define UART_LCR_WLS_RESETVAL        (0x00000000u)
/*----WLS Tokens----*/
#define UART_LCR_WLS_5BITS           (0x00000000u)
#define UART_LCR_WLS_6BITS           (0x00000001u)
#define UART_LCR_WLS_7BITS           (0x00000002u)
#define UART_LCR_WLS_8BITS           (0x00000003u)

#define UART_LCR_RESETVAL            (0x00000000u)

/* MCR */


#define UART_MCR_AFE_MASK            (0x00000020u)
#define UART_MCR_AFE_SHIFT           (0x00000005u)
#define UART_MCR_AFE_RESETVAL        (0x00000000u)
/*----AFE Tokens----*/
#define UART_MCR_AFE_DISABLE         (0x00000000u)
#define UART_MCR_AFE_ENABLE          (0x00000001u)

#define UART_MCR_LOOP_MASK           (0x00000010u)
#define UART_MCR_LOOP_SHIFT          (0x00000004u)
#define UART_MCR_LOOP_RESETVAL       (0x00000000u)
/*----LOOP Tokens----*/
#define UART_MCR_LOOP_DISABLE        (0x00000000u)
#define UART_MCR_LOOP_ENABLE         (0x00000001u)

#define UART_MCR_OUT2_MASK           (0x00000008u)
#define UART_MCR_OUT2_SHIFT          (0x00000003u)
#define UART_MCR_OUT2_RESETVAL       (0x00000000u)
/*----OUT2 Tokens----*/
#define UART_MCR_OUT2_DISABLE        (0x00000000u)
#define UART_MCR_OUT2_ENABLE         (0x00000001u)

#define UART_MCR_OUT1_MASK           (0x00000004u)
#define UART_MCR_OUT1_SHIFT          (0x00000002u)
#define UART_MCR_OUT1_RESETVAL       (0x00000000u)
/*----OUT1 Tokens----*/
#define UART_MCR_OUT1_DISABLE        (0x00000000u)
#define UART_MCR_OUT1_ENABLE         (0x00000001u)

#define UART_MCR_RTS_MASK            (0x00000002u)
#define UART_MCR_RTS_SHIFT           (0x00000001u)
#define UART_MCR_RTS_RESETVAL        (0x00000000u)
/*----RTS Tokens----*/
#define UART_MCR_RTS_HIGH            (0x00000000u)
#define UART_MCR_RTS_DISABLE         (0x00000000u)
#define UART_MCR_RTS_ENABLE          (0x00000001u)
#define UART_MCR_RTS_LOW             (0x00000001u)

#define UART_MCR_DTR_MASK            (0x00000001u)
#define UART_MCR_DTR_SHIFT           (0x00000000u)
#define UART_MCR_DTR_RESETVAL        (0x00000000u)
/*----DTR Tokens----*/
#define UART_MCR_DTR_DISABLE         (0x00000000u)
#define UART_MCR_DTR_ENABLE          (0x00000001u)

#define UART_MCR_RESETVAL            (0x00000000u)

/* LSR */


#define UART_LSR_RXFIFOE_MASK        (0x00000080u)
#define UART_LSR_RXFIFOE_SHIFT       (0x00000007u)
#define UART_LSR_RXFIFOE_RESETVAL    (0x00000000u)
/*----RXFIFOE Tokens----*/
#define UART_LSR_RXFIFOE_NOERROR     (0x00000000u)
#define UART_LSR_RXFIFOE_ERROR       (0x00000001u)

#define UART_LSR_TEMT_MASK           (0x00000040u)
#define UART_LSR_TEMT_SHIFT          (0x00000006u)
#define UART_LSR_TEMT_RESETVAL       (0x00000001u)
/*----TEMT Tokens----*/
#define UART_LSR_TEMT_FULL           (0x00000000u)
#define UART_LSR_TEMT_EMPTY          (0x00000001u)

#define UART_LSR_THRE_MASK           (0x00000020u)
#define UART_LSR_THRE_SHIFT          (0x00000005u)
#define UART_LSR_THRE_RESETVAL       (0x00000001u)
/*----THRE Tokens----*/
#define UART_LSR_THRE_FULL           (0x00000000u)
#define UART_LSR_THRE_EMPTY          (0x00000001u)

#define UART_LSR_BI_MASK             (0x00000010u)
#define UART_LSR_BI_SHIFT            (0x00000004u)
#define UART_LSR_BI_RESETVAL         (0x00000000u)
/*----BI Tokens----*/
#define UART_LSR_BI_NOBREAK          (0x00000000u)
#define UART_LSR_BI_BREAK            (0x00000001u)

#define UART_LSR_FE_MASK             (0x00000008u)
#define UART_LSR_FE_SHIFT            (0x00000003u)
#define UART_LSR_FE_RESETVAL         (0x00000000u)
/*----FE Tokens----*/
#define UART_LSR_FE_NOERROR          (0x00000000u)
#define UART_LSR_FE_ERROR            (0x00000001u)

#define UART_LSR_PE_MASK             (0x00000004u)
#define UART_LSR_PE_SHIFT            (0x00000002u)
#define UART_LSR_PE_RESETVAL         (0x00000000u)
/*----PE Tokens----*/
#define UART_LSR_PE_NOERROR          (0x00000000u)
#define UART_LSR_PE_ERROR            (0x00000001u)

#define UART_LSR_OE_MASK             (0x00000002u)
#define UART_LSR_OE_SHIFT            (0x00000001u)
#define UART_LSR_OE_RESETVAL         (0x00000000u)
/*----OE Tokens----*/
#define UART_LSR_OE_NOERROR          (0x00000000u)
#define UART_LSR_OE_ERROR            (0x00000001u)

#define UART_LSR_DR_MASK             (0x00000001u)
#define UART_LSR_DR_SHIFT            (0x00000000u)
#define UART_LSR_DR_RESETVAL         (0x00000000u)
/*----DR Tokens----*/
#define UART_LSR_DR_NOTREADY         (0x00000000u)
#define UART_LSR_DR_READY            (0x00000001u)

#define UART_LSR_RESETVAL            (0x00000060u)

/* MSR */


#define UART_MSR_CD_MASK             (0x00000080u)
#define UART_MSR_CD_SHIFT            (0x00000007u)
#define UART_MSR_CD_RESETVAL         (0x00000000u)
/*----CD Tokens----*/
#define UART_MSR_CD_NOCD             (0x00000000u)
#define UART_MSR_CD_CD               (0x00000001u)

#define UART_MSR_RI_MASK             (0x00000040u)
#define UART_MSR_RI_SHIFT            (0x00000006u)
#define UART_MSR_RI_RESETVAL         (0x00000000u)
/*----RI Tokens----*/
#define UART_MSR_RI_NORI             (0x00000000u)
#define UART_MSR_RI_RI               (0x00000001u)

#define UART_MSR_DSR_MASK            (0x00000020u)
#define UART_MSR_DSR_SHIFT           (0x00000005u)
#define UART_MSR_DSR_RESETVAL        (0x00000000u)
/*----DSR Tokens----*/
#define UART_MSR_DSR_NODSR           (0x00000000u)
#define UART_MSR_DSR_DSR             (0x00000001u)

#define UART_MSR_CTS_MASK            (0x00000010u)
#define UART_MSR_CTS_SHIFT           (0x00000004u)
#define UART_MSR_CTS_RESETVAL        (0x00000000u)
/*----CTS Tokens----*/
#define UART_MSR_CTS_NOCTS           (0x00000000u)
#define UART_MSR_CTS_CTS             (0x00000001u)

#define UART_MSR_DCD_MASK            (0x00000008u)
#define UART_MSR_DCD_SHIFT           (0x00000003u)
#define UART_MSR_DCD_RESETVAL        (0x00000000u)
/*----DCD Tokens----*/
#define UART_MSR_DCD_NODCD           (0x00000000u)
#define UART_MSR_DCD_DCD             (0x00000001u)

#define UART_MSR_TERI_MASK           (0x00000004u)
#define UART_MSR_TERI_SHIFT          (0x00000002u)
#define UART_MSR_TERI_RESETVAL       (0x00000000u)
/*----TERI Tokens----*/
#define UART_MSR_TERI_NOTERI         (0x00000000u)
#define UART_MSR_TERI_TERI           (0x00000001u)

#define UART_MSR_DDSR_MASK           (0x00000002u)
#define UART_MSR_DDSR_SHIFT          (0x00000001u)
#define UART_MSR_DDSR_RESETVAL       (0x00000000u)
/*----DDSR Tokens----*/
#define UART_MSR_DDSR_NODDSR         (0x00000000u)
#define UART_MSR_DDSR_DDSR           (0x00000001u)

#define UART_MSR_DCTS_MASK           (0x00000001u)
#define UART_MSR_DCTS_SHIFT          (0x00000000u)
#define UART_MSR_DCTS_RESETVAL       (0x00000000u)
/*----DCTS Tokens----*/
#define UART_MSR_DCTS_NODCTS         (0x00000000u)
#define UART_MSR_DCTS_DCTS           (0x00000001u)

#define UART_MSR_RESETVAL            (0x00000000u)

/* SCR */


#define UART_SCR_SCR_MASK            (0x000000FFu)
#define UART_SCR_SCR_SHIFT           (0x00000000u)
#define UART_SCR_SCR_RESETVAL        (0x00000000u)

#define UART_SCR_RESETVAL            (0x00000000u)

/* DLL */


#define UART_DLL_DLL_MASK            (0x000000FFu)
#define UART_DLL_DLL_SHIFT           (0x00000000u)
#define UART_DLL_DLL_RESETVAL        (0x00000000u)

#define UART_DLL_RESETVAL            (0x00000000u)

/* DLH */


#define UART_DLH_DLH_MASK            (0x000000FFu)
#define UART_DLH_DLH_SHIFT           (0x00000000u)
#define UART_DLH_DLH_RESETVAL        (0x00000000u)

#define UART_DLH_RESETVAL            (0x00000000u)

/* PID1 */

#define UART_REVID1_REV_MASK           (0xFFFFFFFFu)
#define UART_REVID1_REV_SHIFT          (0x00000000u)
#define UART_REVID1_REV_RESETVAL       (0x11020002u)

#define UART_REVID1_RESETVAL           (0x44141102u)

/* PID2 */


#define UART_REVID2_REV_MASK           (0xFFFFFFFFu)
#define UART_REVID2_REV_SHIFT          (0x00000000u)
#define UART_REVID2_REV_RESETVAL       (0x00000000u)

#define UART_REVID2_RESETVAL           (0x00000000u)

/* PWREMU_MGMT */



#define UART_PWREMU_MGMT_UTRST_MASK  (0x00004000u)
#define UART_PWREMU_MGMT_UTRST_SHIFT (0x0000000Eu)
#define UART_PWREMU_MGMT_UTRST_RESETVAL (0x00000000u)
/*----UTRST Tokens----*/
#define UART_PWREMU_MGMT_UTRST_RESET (0x00000000u)
#define UART_PWREMU_MGMT_UTRST_ENABLE (0x00000001u)

#define UART_PWREMU_MGMT_URRST_MASK  (0x00002000u)
#define UART_PWREMU_MGMT_URRST_SHIFT (0x0000000Du)
#define UART_PWREMU_MGMT_URRST_RESETVAL (0x00000000u)
/*----URRST Tokens----*/
#define UART_PWREMU_MGMT_URRST_RESET (0x00000000u)
#define UART_PWREMU_MGMT_URRST_ENABLE (0x00000001u)



#define UART_PWREMU_MGMT_FREE_MASK   (0x00000001u)
#define UART_PWREMU_MGMT_FREE_SHIFT  (0x00000000u)
#define UART_PWREMU_MGMT_FREE_RESETVAL (0x00000000u)
/*----FREE Tokens----*/
#define UART_PWREMU_MGMT_FREE_STOP   (0x00000000u)
#define UART_PWREMU_MGMT_FREE_RUN    (0x00000001u)

#define UART_PWREMU_MGMT_RESETVAL    (0x00000002u)

/* MDR */


#define UART_MDR_OSM_SEL_MASK        (0x00000001u)
#define UART_MDR_OSM_SEL_SHIFT       (0x00000000u)
#define UART_MDR_OSM_SEL_RESETVAL    (0x00000000u)
/*----OSM_SEL Tokens----*/
#define UART_MDR_OSM_SEL_16XOVERSAMPLING (0x00000000u)
#define UART_MDR_OSM_SEL_13XOVERSAMPLING (0x00000001u)

#define UART_MDR_RESETVAL            (0x00000000u)

/**
 *@brief This function is used to initial a uart port with baudrate
 *@param port Port number.
 *@see #UART_0,#UART_1,#UART_2.
 *@param baudrate Indicate baudrate of uart port (2400,9600,19200,38400,57600,115200,...).
 *@return status of initialization. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 uart_init(Uint32 port,Uint32 baudrate);

/**
 *@brief This function is used to disable an uart port.
 *@param port Port number.
 *@see #UART_0,#UART_1,#UART_2.
 *@param baudrate Indicate baudrate of uart port (2400,9600,19200,38400,57600,115200,...).
 *@return status of disabling. \n
 *@see #STATUS_FINISHED,#STATUS_FAILED.
 */

Int32 uart_disable(Uint32 port);

/**
 *@brief This function is used to send one byte to uart 0.
 *@param x value of byte that is sent to uart 0.
 */
void uart0_sendchar(Uint8 x);

/**
 *@brief This function is used to send one byte to uart 1.
 *@param x value of byte that is sent to uart 1.
 */
void uart1_sendchar(Uint8 x);

/**
 *@brief This function is used to send one byte to uart 2.
 *@param x value of byte that is sent to uart 2.
 */
void uart2_sendchar(Uint8 x);

#endif

