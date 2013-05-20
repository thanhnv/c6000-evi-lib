/**
 * @file systemConfigurations.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Declaration some system configure variables, that are used to handle running environment.
 * @see http://www.embeddedvietnam.com
 */



#include <include/types.h>
#include <stdbool.h>
#include <include/systemConfigurations.h>

bool UART0_run = false;
bool UART1_run = false;
bool UART2_run = false;

Uint32 CrystalFreq = CRYSTAL_FREQ;
Uint32 DSPFreq=CRYSTAL_FREQ/1; /**<Default bypass mode.*/
Uint32 UARTFreq = CRYSTAL_FREQ/2; /**<Default bypass mode.*/
Uint32 TimerFreq = CRYSTAL_FREQ; /**<Always bypass mode.*/
