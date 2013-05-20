/**
 * @file sdram.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Configure SDRAM (external sdram).
 * @see http://www.embeddedvietnam.com
 */


#include <include/emifb.h>
#include <include/commands.h>

/**
*@brief Setup/Initial external SDRAM.
*@return Status of configuration.
*@see #CONFIG_SDRAM_FAIL,#CONFIG_SDRAM_FINSH,...
*/
Int32 config_sdram()
{
    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
        |( 1 << 15)         // Unlock timing registers
        |( 2 << 9 )         // CAS latency is 2
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 1 << 0 );        // 512-word pages requiring 9 column address bits
    //FMK();
    EMIFB_SDREF = 0         // SDRAM Refresh Control Register
        |( 0 << 31)         // Low power mode disabled
        |( 0 << 30)         // MCLK stoping disabled
        |( 0 << 23)         // Selects self refresh instead of power down
        |( 1040 <<0);       // Refresh rate = 7812.5ns / 7.5ns

    EMIFB_SDTIM1 = 0        // SDRAM Timing Register 1
        |( 25 << 25)        // (67.5ns / 7.55ns) - 1 = TRFC  @ 133MHz
        |( 2 << 22 )        // (20ns / 7.5ns) - 1 =TRP
        |( 2 << 19 )        // (20ns / 7.5ns) - 1 = TRCD
        |( 1 << 16 )        // (14ns / 7.5ns) - 1 = TWR
        |( 5 << 11 )        // (45ns / 7.5ns) - 1 = TRAS
        |( 8 <<  6 )        // (67.5ns / 7.5ns) - 1 = TRC
        |( 2 <<  3 );       // *(((4 * 14ns) + (2 * 7.5ns)) / (4 * 7.5ns)) -1. = TRRD
                            // but it says to use this formula if 8 banks but only 4 are used here.
                            // and SDCFG1 register only suports upto 4 banks.

    EMIFB_SDTIM2 = 0        // SDRAM Timing Register 2
        |( 14<< 27)         // not sure how they got this number. the datasheet says value should be
                            // "Maximum number of refresh_rate intervals from Activate to Precharge command"
                            // but has no equation. TRASMAX is 120k.
        |( 9 << 16)         // ( 70 / 7.5) - 1
        |( 5 << 0 );        // ( 45 / 7.5 ) - 1

    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
        |( 1 << 16)
        |( 0 << 15)         // Unlock timing registers
        |( 2 << 9 )         // CAS latency is 2
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 1 << 0 );        // 512-word pages requiring 9 column address bits

	return 1;
}
/**
*@brief Enable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 enable_sdram()
{
	return 1;
}

/**
*@brief Disable using external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 disable_sdram()
{
	return 1;
}

/**
*@brief Power up module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_up_sdram()
{
	return 1;
}

/**
*@brief Power down module external SDRAM.
*@see #STATUS_FINISHED,#STATUS_FAILED.
*/
Int32 power_down_sdram()
{
	return 1;
}

