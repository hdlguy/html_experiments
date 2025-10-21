all: libinstrument.a libinstrument.so test_static test_dynamic
.PHONY: clean run

CFLAGS= -I./ -Wall 

DEPS = Makefile ./fpga.h 

# library C to object file
libinstrument.o: libinstrument.c $(DEPS)
	gcc -c -fPIC libinstrument.c -o libinstrument.o $(CFLAGS)

# dynamic library
libinstrument.so: libinstrument.o
	gcc -shared -o libinstrument.so libinstrument.o

# static library
libinstrument.a: libinstrument.o
	ar rcs libinstrument.a libinstrument.o

# test program
test_static: test.cpp libinstrument.a
	g++ -static -L. -o test_static test.cpp -linstrument
test_dynamic: test.cpp libinstrument.so
	g++ -L. -o test_dynamic test.cpp -linstrument

#instrument_server: instrument_server.cpp libinstrument.so
#	g++ -I../../ -I../../json/include -L. -o instrument_server instrument_server.cpp -linstrument

clean:
	rm -f *.o *.so *.a test_static test_dynamic

run: 
	@echo
	@echo static link
	./test_static
	@echo
	@echo dynamic link
	LD_LIBRARY_PATH=. ./test_dynamic



