/**
 * @file pllc.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Configure PLL module.
 * @see http://www.embeddedvietnam.com
 */


#include <include/pllc.h>
#include <include/sysconfig.h>
#include <include/systemConfigurations.h>
Int32 setup_pll(Uint32 multi)
{
    int i = 0;

    /* DSP at 300MHz, EMIFs at 133MHz */
    unsigned int DIV45_EN = 1;
    unsigned int CLKMODE = 0;
    if(multi * CRYSTAL_FREQ > MAX_PLL_FREQ){
    	//multi=MAX_PLL_FREQ/CRYSTAL_FREQ;
    }
    unsigned int PLLM = multi;
    DSPFreq=CRYSTAL_FREQ*multi/POST_PLL_DIVIDER;
    // /** @code // @endcode*/
    UARTFreq=(CRYSTAL_FREQ*multi)/(POST_PLL_DIVIDER*2); /** @code UARTFreq=(CRYSTAL_FREQ*multi)/(POST_PLL_DIVIDER*2); //calculate uart freqency @endcode*/
    TimerFreq=(CRYSTAL_FREQ); /** @code TimerFreq=(CRYSTAL_FREQ); //Always bypass mode. @endcode*/

    unsigned int POSTDIV = POST_PLL_DIVIDER - 1;
    unsigned int PLLDIV3 = 2; /** @code PLLDIV3 = 2; //EMIFA @endcode */
    unsigned int PLLDIV5 = 5; /** @code PLLDIV5 = 5; //EMIFB @endcode */
    unsigned int PLLDIV7 = 5; /** @code PLLDIV7 = 5; // RMII, EMAC. With DM9161 ethernet controler run at 50MHz. (24000000*25/2/6 = 50MHz) @endcode*/

   // Moved step 2c and 2d to step 0
   /*Set PLLEN=0 and PLLRST=0, Reset the PLL*/
    PLL0_PLLCTL &=  0xFFFFFFFE;     /*PLL BYPASS MODE*/

   /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
   for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}   /*Make PLLEN_MUX_SWITCH as bootpacket*/

   /*Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
    PLL0_PLLCTL &= 0xFFFFFEFF;
    PLL0_PLLCTL |= (CLKMODE<<8);  /* Make CLKSRC as BootPacket to pass the value*/

   /*Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR*/
    PLL0_PLLCTL &=  0xFFFFFFDF;

   /*PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Primus*/
    PLL0_PLLCTL &=  0xFFFFFDFF;

   /* Clear PLLRST bit to 0 -Reset the PLL */
   PLL0_PLLCTL &= 0xFFFFFFF7;

   /*Disable the PLL output*/
   PLL0_PLLCTL |= 0x10;

   /*PLL initialization sequence*/

   /*Power up the PLL- PWRDN bit set to 0 to bring the PLL out of power down bit*/
   PLL0_PLLCTL &= 0xFFFFFFFD;

   /*Enable the PLL from Disable Mode PLLDIS bit to 0 - This is step is not required for Primus*/
   PLL0_PLLCTL &= 0xFFFFFFEF;

   /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
  /* for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}   Make PLL_STABILIZATION_TIME as bootpacket*/

   /*Program the required multiplier value in PLLM*/
   PLL0_PLLM    = PLLM; /* Make PLLMULTIPLEIR as bootpacket*/

   /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
   PLL0_POSTDIV = 0x8000 | POSTDIV; /* Make POSTDIV as bootpacket*/

   /*If Necessary program the PLLDIVx*/
   /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
   while(PLL0_PLLSTAT & 0x1==1){}

   /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
   	PLL0_PLLDIV1 = 0x8000 | 0; /* Make PLLDIV3 as bootpacket, do it for other PLLDIVx to if required*/
    PLL0_PLLDIV3 = 0x8000 | PLLDIV3; /* Make PLLDIV3 as bootpacket, do it for other PLLDIVx to if required*/
    PLL0_PLLDIV5 = 0x8000 | PLLDIV5; /* Make PLLDIV5 as bootpacket, do it for other PLLDIVx to if required*/
    PLL0_PLLDIV7 = 0x8000 | PLLDIV7; /* Make PLLDIV7 as bootpacket, do it for other PLLDIVx to if required*/

    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL0_PLLCMD |= 0x1;

    /*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL0_PLLSTAT & 0x1==1) { }


   /*Wait for PLL to reset properly. See PLL spec for PLL reset time - This step is not required here -step11*/
  /* for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}   128 MXI Cycles Make PLL_RESET_TIME_CNT as boot packet*/

   /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
   PLL0_PLLCTL |= 0x8;

   /*Wait for PLL to lock. See PLL spec for PLL lock time*/
   for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;} /*Make PLL_LOCK_TIME_CNT as boot Packet*/

   /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
   PLL0_PLLCTL |=  0x1;

   KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
   KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)
   CFGCHIP3 |= 0x4;       // Enable 4.5 divider PLL
   CFGCHIP3 |= 0x1;       // Select 4.5 divider for EMIFB clock source only (not EMIFA)
   return 1;
}

