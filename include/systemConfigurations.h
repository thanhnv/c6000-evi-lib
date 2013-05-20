/**
 * @file systemConfigurations.h
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Extern some variables that is used for configure system. (All module can use these variables)
 * @see http://www.embeddedvietnam.com
 */

#ifndef SYSTEMCONFIGURATIONS_H_
#define SYSTEMCONFIGURATIONS_H_
#include <stdbool.h>
#include "types.h"
#define CRYSTAL_FREQ (24000000)
#define MAX_PLL_FREQ (600000000)
#define POST_PLL_DIVIDER (2)

extern bool UART0_run ;
extern bool UART1_run ;
extern bool UART2_run ;
extern Uint32 DSPFreq;
extern Uint32 CrystalFreq;
extern Uint32 UARTFreq;
extern Uint32 TimerFreq;

#endif /* SYSTEMCONFIGURATIONS_H_ */
