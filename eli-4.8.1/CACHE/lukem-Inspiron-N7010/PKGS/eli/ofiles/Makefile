CC	= gcc
CFLAGS	= -g -O2

SRCS	= try.c rdsymb.c
OBJS	= try.o rdsymb.o

try.exe:	$(OBJS) data.o
	$(CC) $(CFLAGS) -o $@ $(OBJS)

test:	try.exe
	@if ./try.exe >/dev/null; then echo ok; else echo ng; fi

tidy:
	rm -f *.o *~ *.bak

clean:	tidy
	rm -f try.exe

distclean:	clean
	rm -f config.* Makefile ofile.h

rdsymb.o:	rdsymb.c rdsymb.h symbinfo.h
try.o:		try.c    rdsymb.h
