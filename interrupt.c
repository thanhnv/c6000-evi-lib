/*
 * interrupt.c
 *
 *  Created on: Jun 18, 2013
 *      Author: nvthanh
 */

#include "include/interrupt.h"

#define C674X_NMI 1
#define C674X_GEE 2
#define C674X_XEN 3
#define C674X_INT_COUNT 16
#define NUM_SYS_EVENTS 128


/******************************************************************************
**                      EXTERNALLY DEFINED FUNCTIONS
******************************************************************************/
#ifdef __TI_EABI__
extern void _intcVectorTable (void);
#else
extern void intcVectorTable (void);
#endif

/******************************************************************************
**                      STATIC VARIABLES/FUNCTIONS
******************************************************************************/
static c674xISR c674xISRtbl[C674X_INT_COUNT];


#ifdef __TI_EABI__
interrupt void _c674x_nmi_isr (void)
#else
interrupt void c674x_nmi_isr (void)
#endif
{
    c674xISRtbl[1]();
}

#ifdef __TI_EABI__
interrupt void _c674x_rsvd_int2_isr (void)
#else
interrupt void c674x_rsvd_int2_isr (void)
#endif
{
    c674xISRtbl[2]();
}

#ifdef __TI_EABI__
interrupt void _c674x_rsvd_int3_isr (void)
#else
interrupt void c674x_rsvd_int3_isr (void)
#endif
{
    c674xISRtbl[3]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int4_isr (void)
#else
interrupt void c674x_mask_int4_isr (void)
#endif
{
    c674xISRtbl[4]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int5_isr (void)
#else
interrupt void c674x_mask_int5_isr (void)
#endif
{
    c674xISRtbl[5]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int6_isr (void)
#else
interrupt void c674x_mask_int6_isr (void)
#endif
{
    c674xISRtbl[6]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int7_isr (void)
#else
interrupt void c674x_mask_int7_isr (void)
#endif
{
    c674xISRtbl[7]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int8_isr (void)
#else
interrupt void c674x_mask_int8_isr (void)
#endif
{
    c674xISRtbl[8]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int9_isr (void)
#else
interrupt void c674x_mask_int9_isr (void)
#endif
{
    c674xISRtbl[9]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int10_isr (void)
#else
interrupt void c674x_mask_int10_isr (void)
#endif
{
    c674xISRtbl[10]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int11_isr (void)
#else
interrupt void c674x_mask_int11_isr (void)
#endif
{
    c674xISRtbl[11]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int12_isr (void)
#else
interrupt void c674x_mask_int12_isr (void)
#endif
{
    c674xISRtbl[12]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int13_isr (void)
#else
interrupt void c674x_mask_int13_isr (void)
#endif
{
    c674xISRtbl[13]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int14_isr (void)
#else
interrupt void c674x_mask_int14_isr (void)
#endif
{
    c674xISRtbl[14]();
}

#ifdef __TI_EABI__
interrupt void _c674x_mask_int15_isr (void)
#else
interrupt void c674x_mask_int15_isr (void)
#endif
{
    c674xISRtbl[15]();
}
