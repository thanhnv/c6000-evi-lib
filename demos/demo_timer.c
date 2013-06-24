/*
 * timer.c
 *
 *  Created on: Jun 21, 2013
 *      Author: thanhnv
 */

#include "../include/timer.h"
#include "../include/uart.h"
#include "../include/interrupt.h"
#include "../utilities/debug.h"
#define TMR_PERIOD_LSB32               (0x07FFFFFF)
#define TMR_PERIOD_MSB32               (0x0)

void init_timer()
{
    TimerConfigure(TMR_0_REGS, TMR_CFG_32BIT_CH_CLK_INT);

    /* Set the 64 bit timer period */
    TimerPeriodSet(TMR_0_REGS, TMR_TIMER12, 24000000);
    TimerPeriodSet(TMR_0_REGS, TMR_TIMER34, TMR_PERIOD_MSB32);
}
void isr_timer();
void enable_interrupt_timer()
{
    IntDSPINTCInit();

    /* Register the Timer ISR */
    IntRegister(C674X_MASK_INT4, isr_timer);

    /* Map Timer interrupts to DSP maskable interrupt */
    IntEventMap(C674X_MASK_INT4, SYS_INT_T64P0_TINT12);

    /* Enable DSP interrupt in DSPINTC */
    IntEnable(C674X_MASK_INT4);

    /* Enable DSP interrupts */
    IntGlobalEnable();

}

void isr_timer()
{
	DBG("interrupt\n");
	TimerIntDisable(TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
	IntEventClear(SYS_INT_T64P0_TINT12);
	TimerIntStatusClear(TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
	//TimerPeriodSet(TMR_0_REGS, TMR_TIMER12, 24000000);
	TimerIntEnable(TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
}

void example_timer()
{
	init_timer();
	enable_interrupt_timer();
	TimerIntEnable(TMR_0_REGS, TMR_INT_TMR12_NON_CAPT_MODE);
	TimerEnable(TMR_0_REGS, TMR_TIMER12, TMR_ENABLE_CONT);
	//while(1);
	//TimerDisable(TMR_0_REGS, TMR_TIMER12);

}
