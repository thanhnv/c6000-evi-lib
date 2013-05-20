/**
 * @file commands.h
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 19, 2013
 * @brief Define some macros that are used to assign field for register.
 * @see http://www.embeddedvietnam.com
 */

#ifndef COMMANDS_H_
#define COMMANDS_H_

/**
 * @brief Field make.
 */
#define FMK(PER_REG_FIELD, val)                                         \
    (((val) << PER_REG_FIELD##_SHIFT) & PER_REG_FIELD##_MASK)

/**
 * @brief Field insert.
 */
#define FINS(regs,PER_REG_FIELD,val) ((regs) = ((regs) & ~PER_REG_FIELD##_##MASK) | FMK(PER_REG_FIELD, val))

/**
 * @brief Field make token.
 */
#define FMKT(PER_REG_FIELD, TOKEN)                                      \
    FMK(PER_REG_FIELD, PER_REG_FIELD##_##TOKEN)

#endif /* COMMANDS_H_ */
