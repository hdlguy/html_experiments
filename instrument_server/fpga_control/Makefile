all: libinstrument.so cpp_test
.PHONY: clean run

libinstrument.so: instrument.c fpga.h Makefile
	gcc -shared -fPIC -o libinstrument.so instrument.c

cpp_test: cpp_test.cpp instrument.h libinstrument.so
	g++ -I./ -L. -o cpp_test cpp_test.cpp -linstrument

clean:
	rm -f *.so 

run: 
	@echo
	LD_LIBRARY_PATH=. ./cpp_test


