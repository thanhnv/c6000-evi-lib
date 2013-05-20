/*
 * gpio.h
 *
 *  Created on: May 7, 2013
 *      Author: NGUYEN
 */

#ifndef GPIO_H_
#define GPIO_H_

#ifdef GPIO_0_REGS
#undef GPIO_0_REGS
#endif

#define GPIO_INPUT						(1)
#define GPIO_OUTPUT						(0)

#define GPIO_SET						(1)
#define GPIO_CLR						(0)

#define GPIO_0_REGS                     (0x01E26000u)

#define GPIO_0_BANK_LENGTH				(40u)
#define GPIO_BANK0_BASE 	(GPIO_0_REGS + 0x010u) //GPIO_0_REGS+16
#define GPIO_BANK1_BASE 	(GPIO_BANK0_BASE+GPIO_0_BANK_LENGTH)
#define GPIO_BANK2_BASE 	(GPIO_BANK1_BASE+GPIO_0_BANK_LENGTH)
#define GPIO_BANK3_BASE 	(GPIO_BANK2_BASE+GPIO_0_BANK_LENGTH)
#define GPIO_BANK4_BASE 	(GPIO_BANK3_BASE+GPIO_0_BANK_LENGTH)

/*Define some macros to assign registers*/
#define GPIO_SET_DIR(port,pin,value)	{\
											*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x000) &= ~(1<<(pin + 16*(port%2)));\
											*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x000) |= (value<<(pin+ 16*(port%2)));\
										}
#define GPIO_SET_DIR_OUTPUT(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x000) &= ~(1<<(pin + 16*(port%2)))
#define GPIO_SET_DIR_INPUT(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x000) |= (1<<(pin + 16*(port%2)))

#define GPIO_SET_OUT_DATA(port,pin)		{\
											*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x004) |= (1<<(pin+ 16*(port%2)));\
										}
#define GPIO_CLR_OUT_DATA(port,pin)		{\
											*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x004) &= ~(1<<(pin + 16*(port%2)));\
										}

#define GPIO_SET_PIN(port,pin)			{\
											GPIO_SET_OUT_DATA(port,pin);\
										}

#define GPIO_CLR_PIN(port,pin)			{\
											GPIO_CLR_OUT_DATA(port,pin);\
										}

#define GPIO_IN_PIN(port,pin)				(*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x010) | (1<<(pin+ 16*(port%2))))

#define GPIO_SET_RISE_TRIG(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x014) |= (1<<(pin+ 16*(port%2)))
#define GPIO_CLR_RISE_TRIG(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x018) |= (1<<(pin+ 16*(port%2)))

#define GPIO_SET_FALL_TRIG(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x01C) |= (1<<(pin+ 16*(port%2)))
#define GPIO_CLR_FALL_TRIG(port,pin)		*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x020) |= (1<<(pin+ 16*(port%2)))

#define GPIO_INTSTAT_PIN(port,pin)				(*(unsigned int*)(GPIO_0_REGS + 0x010+GPIO_0_BANK_LENGTH*(port/2) + 0x024) | (1<<(pin+ 16*(port%2))))

/*GPIO Revision ID*/
#define GPIO_REVID			*(unsigned int*)(GPIO_0_REGS+0x00)
/*GPIO Interrupt enable*/
#define GPIO_BINTEN			*(unsigned int*)(GPIO_0_REGS+0x08)

/*GPIO Bank #0 control Registers*/
#define GPIO_BANK0_DIR				*(unsigned int*)(GPIO_BANK0_BASE+0x000)
#define GPIO_BANK0_OUT_DATA			*(unsigned int*)(GPIO_BANK0_BASE+0x004)
#define GPIO_BANK0_SET_DATA			*(unsigned int*)(GPIO_BANK0_BASE+0x008)
#define GPIO_BANK0_CLR_DATA			*(unsigned int*)(GPIO_BANK0_BASE+0x00C)
#define GPIO_BANK0_IN_DATA			*(unsigned int*)(GPIO_BANK0_BASE+0x010)
#define GPIO_BANK0_SET_RISE_TRIG	*(unsigned int*)(GPIO_BANK0_BASE+0x014)
#define GPIO_BANK0_CLR_RISE_TRIG	*(unsigned int*)(GPIO_BANK0_BASE+0x018)
#define GPIO_BANK0_SET_FALL_TRIG	*(unsigned int*)(GPIO_BANK0_BASE+0x01C)
#define GPIO_BANK0_CLR_FALL_TRIG	*(unsigned int*)(GPIO_BANK0_BASE+0x020)
#define GPIO_BANK0_INTSTAT			*(unsigned int*)(GPIO_BANK0_BASE+0x024)
/*GPIO Bank #1 control Registers (Port 0-1)*/
#define GPIO_BANK1_DIR				*(unsigned int*)(GPIO_BANK1_BASE+0x000)
#define GPIO_BANK1_OUT_DATA			*(unsigned int*)(GPIO_BANK1_BASE+0x004)
#define GPIO_BANK1_SET_DATA			*(unsigned int*)(GPIO_BANK1_BASE+0x008)
#define GPIO_BANK1_CLR_DATA			*(unsigned int*)(GPIO_BANK1_BASE+0x00C)
#define GPIO_BANK1_IN_DATA			*(unsigned int*)(GPIO_BANK1_BASE+0x010)
#define GPIO_BANK1_SET_RISE_TRIG	*(unsigned int*)(GPIO_BANK1_BASE+0x014)
#define GPIO_BANK1_CLR_RISE_TRIG	*(unsigned int*)(GPIO_BANK1_BASE+0x018)
#define GPIO_BANK1_SET_FALL_TRIG	*(unsigned int*)(GPIO_BANK1_BASE+0x01C)
#define GPIO_BANK1_CLR_FALL_TRIG	*(unsigned int*)(GPIO_BANK1_BASE+0x020)
#define GPIO_BANK1_INTSTAT			*(unsigned int*)(GPIO_BANK1_BASE+0x024)

/*GPIO Bank #2 control Registers (Port 2-3)*/
#define GPIO_BANK2_DIR				*(unsigned int*)(GPIO_BANK2_BASE+0x000)
#define GPIO_BANK2_OUT_DATA			*(unsigned int*)(GPIO_BANK2_BASE+0x004)
#define GPIO_BANK2_SET_DATA			*(unsigned int*)(GPIO_BANK2_BASE+0x008)
#define GPIO_BANK2_CLR_DATA			*(unsigned int*)(GPIO_BANK2_BASE+0x00C)
#define GPIO_BANK2_IN_DATA			*(unsigned int*)(GPIO_BANK2_BASE+0x010)
#define GPIO_BANK2_SET_RISE_TRIG	*(unsigned int*)(GPIO_BANK2_BASE+0x014)
#define GPIO_BANK2_CLR_RISE_TRIG	*(unsigned int*)(GPIO_BANK2_BASE+0x018)
#define GPIO_BANK2_SET_FALL_TRIG	*(unsigned int*)(GPIO_BANK2_BASE+0x01C)
#define GPIO_BANK2_CLR_FALL_TRIG	*(unsigned int*)(GPIO_BANK2_BASE+0x020)
#define GPIO_BANK2_INTSTAT			*(unsigned int*)(GPIO_BANK2_BASE+0x024)

/*GPIO Bank #3 control Registers (Port 4-5)*/
#define GPIO_BANK3_DIR				*(unsigned int*)(GPIO_BANK3_BASE+0x000)
#define GPIO_BANK3_OUT_DATA			*(unsigned int*)(GPIO_BANK3_BASE+0x004)
#define GPIO_BANK3_SET_DATA			*(unsigned int*)(GPIO_BANK3_BASE+0x008)
#define GPIO_BANK3_CLR_DATA			*(unsigned int*)(GPIO_BANK3_BASE+0x00C)
#define GPIO_BANK3_IN_DATA			*(unsigned int*)(GPIO_BANK3_BASE+0x010)
#define GPIO_BANK3_SET_RISE_TRIG	*(unsigned int*)(GPIO_BANK3_BASE+0x014)
#define GPIO_BANK3_CLR_RISE_TRIG	*(unsigned int*)(GPIO_BANK3_BASE+0x018)
#define GPIO_BANK3_SET_FALL_TRIG	*(unsigned int*)(GPIO_BANK3_BASE+0x01C)
#define GPIO_BANK3_CLR_FALL_TRIG	*(unsigned int*)(GPIO_BANK3_BASE+0x020)
#define GPIO_BANK3_INTSTAT			*(unsigned int*)(GPIO_BANK3_BASE+0x024)

/*GPIO Bank #4 control Registers (Port 6-7)*/
#define GPIO_BANK4_DIR				*(unsigned int*)(GPIO_BANK4_BASE+0x000)
#define GPIO_BANK4_OUT_DATA			*(unsigned int*)(GPIO_BANK4_BASE+0x004)
#define GPIO_BANK4_SET_DATA			*(unsigned int*)(GPIO_BANK4_BASE+0x008)
#define GPIO_BANK4_CLR_DATA			*(unsigned int*)(GPIO_BANK4_BASE+0x00C)
#define GPIO_BANK4_IN_DATA			*(unsigned int*)(GPIO_BANK4_BASE+0x010)
#define GPIO_BANK4_SET_RISE_TRIG	*(unsigned int*)(GPIO_BANK4_BASE+0x014)
#define GPIO_BANK4_CLR_RISE_TRIG	*(unsigned int*)(GPIO_BANK4_BASE+0x018)
#define GPIO_BANK4_SET_FALL_TRIG	*(unsigned int*)(GPIO_BANK4_BASE+0x01C)
#define GPIO_BANK4_CLR_FALL_TRIG	*(unsigned int*)(GPIO_BANK4_BASE+0x020)
#define GPIO_BANK4_INTSTAT			*(unsigned int*)(GPIO_BANK4_BASE+0x024)

/*Define Pins Tokens*/
#define GP0P0  (1 <<  0)
#define GP0P1  (1 <<  1)
#define GP0P2  (1 <<  2)
#define GP0P3  (1 <<  3)
#define GP0P4  (1 <<  4)
#define GP0P5  (1 <<  5)
#define GP0P6  (1 <<  6)
#define GP0P7  (1 <<  7)
#define GP0P8  (1 <<  8)
#define GP0P9  (1 <<  9)
#define GP0P10 (1 << 10)
#define GP0P11 (1 << 11)
#define GP0P12 (1 << 12)
#define GP0P13 (1 << 13)
#define GP0P14 (1 << 14)
#define GP0P15 (1 << 15)
#define GP1P0  (1 << 16)
#define GP1P1  (1 << 17)
#define GP1P2  (1 << 18)
#define GP1P3  (1 << 19)
#define GP1P4  (1 << 20)
#define GP1P5  (1 << 21)
#define GP1P6  (1 << 22)
#define GP1P7  (1 << 23)
#define GP1P8  (1 << 24)
#define GP1P9  (1 << 25)
#define GP1P10 (1 << 26)
#define GP1P11 (1 << 27)
#define GP1P12 (1 << 28)
#define GP1P13 (1 << 29)
#define GP1P14 (1 << 30)
#define GP1P15 (1 << 31)

#define GP2P0  (1 <<  0)
#define GP2P1  (1 <<  1)
#define GP2P2  (1 <<  2)
#define GP2P3  (1 <<  3)
#define GP2P4  (1 <<  4)
#define GP2P5  (1 <<  5)
#define GP2P6  (1 <<  6)
#define GP2P7  (1 <<  7)
#define GP2P8  (1 <<  8)
#define GP2P9  (1 <<  9)
#define GP2P10 (1 << 10)
#define GP2P11 (1 << 11)
#define GP2P12 (1 << 12)
#define GP2P13 (1 << 13)
#define GP2P14 (1 << 14)
#define GP2P15 (1 << 15)
#define GP3P0  (1 << 16)
#define GP3P1  (1 << 17)
#define GP3P2  (1 << 18)
#define GP3P3  (1 << 19)
#define GP3P4  (1 << 20)
#define GP3P5  (1 << 21)
#define GP3P6  (1 << 22)
#define GP3P7  (1 << 23)
#define GP3P8  (1 << 24)
#define GP3P9  (1 << 25)
#define GP3P10 (1 << 26)
#define GP3P11 (1 << 27)
#define GP3P12 (1 << 28)
#define GP3P13 (1 << 29)
#define GP3P14 (1 << 30)
#define GP3P15 (1 << 31)

#define GP4P0  (1 <<  0)
#define GP4P1  (1 <<  1)
#define GP4P2  (1 <<  2)
#define GP4P3  (1 <<  3)
#define GP4P4  (1 <<  4)
#define GP4P5  (1 <<  5)
#define GP4P6  (1 <<  6)
#define GP4P7  (1 <<  7)
#define GP4P8  (1 <<  8)
#define GP4P9  (1 <<  9)
#define GP4P10 (1 << 10)
#define GP4P11 (1 << 11)
#define GP4P12 (1 << 12)
#define GP4P13 (1 << 13)
#define GP4P14 (1 << 14)
#define GP4P15 (1 << 15)
#define GP5P0  (1 << 16)
#define GP5P1  (1 << 17)
#define GP5P2  (1 << 18)
#define GP5P3  (1 << 19)
#define GP5P4  (1 << 20)
#define GP5P5  (1 << 21)
#define GP5P6  (1 << 22)
#define GP5P7  (1 << 23)
#define GP5P8  (1 << 24)
#define GP5P9  (1 << 25)
#define GP5P10 (1 << 26)
#define GP5P11 (1 << 27)
#define GP5P12 (1 << 28)
#define GP5P13 (1 << 29)
#define GP5P14 (1 << 30)
#define GP5P15 (1 << 31)

#define GP6P0  (1 <<  0)
#define GP6P1  (1 <<  1)
#define GP6P2  (1 <<  2)
#define GP6P3  (1 <<  3)
#define GP6P4  (1 <<  4)
#define GP6P5  (1 <<  5)
#define GP6P6  (1 <<  6)
#define GP6P7  (1 <<  7)
#define GP6P8  (1 <<  8)
#define GP6P9  (1 <<  9)
#define GP6P10 (1 << 10)
#define GP6P11 (1 << 11)
#define GP6P12 (1 << 12)
#define GP6P13 (1 << 13)
#define GP6P14 (1 << 14)
#define GP6P15 (1 << 15)
#define GP7P0  (1 << 16)
#define GP7P1  (1 << 17)
#define GP7P2  (1 << 18)
#define GP7P3  (1 << 19)
#define GP7P4  (1 << 20)
#define GP7P5  (1 << 21)
#define GP7P6  (1 << 22)
#define GP7P7  (1 << 23)
#define GP7P8  (1 << 24)
#define GP7P9  (1 << 25)
#define GP7P10 (1 << 26)
#define GP7P11 (1 << 27)
#define GP7P12 (1 << 28)
#define GP7P13 (1 << 29)
#define GP7P14 (1 << 30)
#define GP7P15 (1 << 31)



#endif /* GPIO_H_ */
