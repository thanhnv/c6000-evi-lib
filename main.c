/**
 * @file main.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Main program to test all modules.
 * @see http://www.embeddedvietnam.com
 */

#include <stdio.h>
#include "include/memories.h"
#include "include/sysconfig.h"
#include "include/gpio.h"
#include "include/pllc.h"
#include "include/psc.h"
#include "include/emifb.h"
#include "include/uart.h"
#include "utilities/debug.h"

void sw_sleep(Uint32 value)
{
	while(value--);
}


int main()
{
	setup_pll(25);
	uart_init(UART_1,115200);
	//uart1_sendchar(0xff);
	unsigned int x=0;
	printf("hello world\n");

	while(1){
		DBG("value %d, 0x%x\n",++x,x);
		sw_sleep(10000000);
	}

	//while(1);
}
