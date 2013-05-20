#Makefile for the socket programming example
#

SRCS:= xprintf.c
all : xprintf
xprintf: $(SRCS)
	gcc -o $@ $(SRCS) -DRUN_APP
clean:
	rm -f xprintf *.o *~
