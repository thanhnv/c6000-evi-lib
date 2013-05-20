/**
 * @file xprintf.h
 * @author <b>Thanh Nguyen </b>, Email: thanhembeddedvietnam@gmail.com or thanh_bk05@yahoo.com
 * @date May 19, 2013
 * @brief Define some prototypes of functions that use stdarg to parse input arguments, dump character out output device (UART/I2C) with a format (like printf,sprintf,...).
 * @see http://www.embeddedvietnam.com
 */

#ifndef XPRINTF_H_
#define XPRINTF_H_


#define _USE_XFUNC_OUT	1	/* 1: Use output functions */
#define	_CR_CRLF		1	/* 1: Convert \n ==> \r\n in the output char */

#define _USE_XFUNC_IN	1	/* 1: Use input function */
#define	_LINE_ECHO		1	/* 1: Echo back input chars in xgets function */


#if _USE_XFUNC_OUT
#include <stdarg.h>
#define xdev_out(func) xfunc_out = (void(*)(unsigned char))(func)
extern void (*xfunc_out)(unsigned char);
void xputc (unsigned char c);
void xputs (const unsigned char* str);
void xfputs (void (*func)(unsigned char), const unsigned char* str);
void xprintf (const unsigned char* fmt, ...);
void xsprintf (char* buff, const unsigned char* fmt, ...);
void xfprintf (void (*func)(unsigned char), const unsigned  char*	fmt, ...);
void put_dump (const void* buff, unsigned long addr, int len, int width);
void xvprintf (	const unsigned char*	fmt,va_list arp);

#define DW_CHAR		sizeof(char)
#define DW_SHORT	sizeof(short)
#define DW_LONG		sizeof(long)
#endif

#if _USE_XFUNC_IN
#define xdev_in(func) xfunc_in = (unsigned char(*)(void))(func)
extern unsigned char (*xfunc_in)(void);
int xgets (char* buff, int len);
int xfgets (unsigned char (*func)(void), char* buff, int len);
int xatoi (char** str, long* res);
#endif



#endif /* XPRINTF_H_ */
