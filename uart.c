/**
 * @file uart.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 16, 2013
 * @brief Driver for UART module.
 * @see http://www.embeddedvietnam.com
 */



#include <include/uart.h>
#include <include/psc.h>
#include <include/commands.h>
#include <include/sysconfig.h>
#include <include/systemConfigurations.h>
void sw_sleep(Uint32);
Int32 uart_init(Uint32 port,Uint32 baudrate)
{
	KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
	KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)
	if(port == 0){
		PSC0_lPSC_enable(0,PSC_UART0);
		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_19_16,SYSCFG_PINMUX8_PINMUX8_19_16_UART0_TXD); /**<Chose UART_0_TXD functionality.*/
		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_15_12,SYSCFG_PINMUX8_PINMUX8_15_12_UART0_RXD); /**<Chose UART_0_RXD functionality.*/
		UART_0_LCR=	UART_LCR_WLS_8BITS << UART_LCR_WLS_SHIFT;
		UART_0_MCR=0;
		unsigned int tmp=0;
		tmp=UARTFreq/(16*baudrate);
		UART_0_DLL=tmp & 0x000000FFu;
		UART_0_DLH=(tmp & 0x0000FF00u)>>8;
		UART_0_MDR=UART_MDR_OSM_SEL_16XOVERSAMPLING <<UART_MDR_OSM_SEL_SHIFT;
		UART_0_PWREMU_MGMT=UART_PWREMU_MGMT_URRST_ENABLE <<UART_PWREMU_MGMT_URRST_SHIFT
							|UART_PWREMU_MGMT_UTRST_ENABLE <<UART_PWREMU_MGMT_UTRST_SHIFT;;
		UART0_run=true;
	}else 	if(port == 1){
		PSC1_lPSC_enable(0,PSC_UART1);
		FINS(PINMUX11,SYSCFG_PINMUX11_PINMUX11_15_12,SYSCFG_PINMUX11_PINMUX11_15_12_UART1_TXD); /**<Chose UART_1_TXD functionality.*/
		FINS(PINMUX11,SYSCFG_PINMUX11_PINMUX11_11_8,SYSCFG_PINMUX11_PINMUX11_11_8_UART1_RXD); /**<Chose UART_1_RXD functionality.*/
		UART_1_LCR=	UART_LCR_WLS_8BITS << UART_LCR_WLS_SHIFT;
		UART_1_MCR=0;
		unsigned int tmp=0;
		tmp=UARTFreq/(16*baudrate);
		UART_1_DLL=tmp & 0x000000FFu;
		UART_1_DLH=(tmp & 0x0000FF00u)>>8;
		UART_1_MDR=UART_MDR_OSM_SEL_16XOVERSAMPLING <<UART_MDR_OSM_SEL_SHIFT;
		UART_1_PWREMU_MGMT=UART_PWREMU_MGMT_URRST_ENABLE <<UART_PWREMU_MGMT_URRST_SHIFT
							|UART_PWREMU_MGMT_UTRST_ENABLE <<UART_PWREMU_MGMT_UTRST_SHIFT;;
		UART1_run=true;
	}else 	if(port == 2){
		PSC1_lPSC_enable(0,PSC_UART2);
		FINS(PINMUX9,SYSCFG_PINMUX9_PINMUX9_3_0,SYSCFG_PINMUX9_PINMUX9_3_0_UART2_TXD); /**<Chose UART_2_TXD functionality.*/
		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_31_28,SYSCFG_PINMUX8_PINMUX8_31_28_UART2_RXD); /**<Chose UART_2_RXD functionality.*/
		UART_2_LCR=	UART_LCR_WLS_8BITS << UART_LCR_WLS_SHIFT;
		UART_2_MCR=0;
		unsigned int tmp=0;
		tmp=UARTFreq/(16*baudrate);
		UART_2_DLL=tmp & 0x000000FFu;
		UART_2_DLH=(tmp & 0x0000FF00u)>>8;
		UART_2_MDR=UART_MDR_OSM_SEL_16XOVERSAMPLING <<UART_MDR_OSM_SEL_SHIFT;
		UART_2_PWREMU_MGMT=UART_PWREMU_MGMT_URRST_ENABLE <<UART_PWREMU_MGMT_URRST_SHIFT
							|UART_PWREMU_MGMT_UTRST_ENABLE <<UART_PWREMU_MGMT_UTRST_SHIFT;
		UART2_run=true;
	}
	return STATUS_FINISHED;
}

Int32 uart_disable(Uint32 port)
{
	KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
	KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)
	if(port == 0){
		PSC0_lPSC_disable(0,PSC_UART0);
//		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_19_16,SYSCFG_PINMUX8_PINMUX8_19_16_DEFAULT); /**<Chose default state.*/
//		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_15_12,SYSCFG_PINMUX8_PINMUX8_15_12_DEFAULT); /**<Chose default state.*/
		UART0_run=false;
	}else if(port == 1){
		PSC1_lPSC_disable(0,PSC_UART1);
//		FINS(PINMUX11,SYSCFG_PINMUX11_PINMUX11_15_12,SYSCFG_PINMUX11_PINMUX11_15_12_DEFAULT); /**<Chose default state.*/
//		FINS(PINMUX11,SYSCFG_PINMUX11_PINMUX11_11_8,SYSCFG_PINMUX11_PINMUX11_11_8_DEFAULT); /**<Chose default state.*/
		UART1_run=false;
	}else if(port == 2){
		PSC1_lPSC_enable(0,PSC_UART2);
//		FINS(PINMUX9,SYSCFG_PINMUX9_PINMUX9_3_0,SYSCFG_PINMUX9_PINMUX9_3_0_DEFAULT); /**<Chose default state.*/
//		FINS(PINMUX8,SYSCFG_PINMUX8_PINMUX8_31_28,SYSCFG_PINMUX8_PINMUX8_31_28_DEFAULT); /**<Chose default state.*/
		UART2_run=false;
	}
	return STATUS_FINISHED;
}

void uart0_sendchar(Uint8 x)
{
	if(!UART0_run) return;
	UART_0_THR = (Uint32)x;
	while(( UART_0_LSR & UART_LSR_TEMT_MASK) == 0);
}

void uart1_sendchar(Uint8 x)
{
	if(!UART1_run) return;
	UART_1_THR = (Uint32)x;
	while(( UART_1_LSR & UART_LSR_TEMT_MASK) == 0);
	sw_sleep(1000);
}

void uart2_sendchar(Uint8 x)
{
	if(!UART2_run) return;
	UART_2_THR = (Uint32)x;
	while(( UART_2_LSR & UART_LSR_TEMT_MASK) == 0);
}
