all: libinstrument.so 
.PHONY: clean

CFLAGS= -I./ -Wall 

DEPS = Makefile

libinstrument.so: instrument.c
	gcc -shared -fPIC -o libinstrument.so instrument.c

clean:
	rm -f *.so 




