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
#include <stdlib.h>

void example_timer();
void example_emac();

void sw_sleep(Uint32 value)
{
	while(value--);
}

int example_sdram();
int main()
{
	setup_pll(25);
	uart_init(UART_1,115200);
#if 0
	unsigned char * mm = malloc(100);
	if(mm){
		printf("memory allocate %p\n",mm);
		free(mm);
	}

	mm = malloc(100);
	if(mm){
		printf("memory allocate %p\n",mm);
	}
	unsigned int x=0;
	printf("hello world\n");
	while(1){
		DBG("value %d, 0x%x, %f\n",++x,x,(float)x+0.123456,x,x);
		sw_sleep(100000);
	}
#endif
	//example_sdram();
	example_timer();
	example_emac();
	while(1);
}
