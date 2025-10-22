all: libinstrument.so 
.PHONY: clean

libinstrument.so: instrument.c fpga.h Makefile
	gcc -shared -fPIC -o libinstrument.so instrument.c

clean:
	rm -f *.so 




