/**
 * @file sdram.c
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 18, 2013
 * @brief Configure SDRAM (external sdram).
 * @see http://www.embeddedvietnam.com
 */


#include <include/emifb.h>

/**
*@brief Setup/Initial external SDRAM.
*@return Status of configuration.
*@see #CONFIG_SDRAM_FAIL,#CONFIG_SDRAM_FINSH,...
*/
Int32 config_sdram()
{
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

