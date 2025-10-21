#all: libinstrument.so libinstrument.a test
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

#test_static: fpga_test.cpp libinstrument.a
#	g++ -static -L. -o fpga_test fpga_test.cpp -linstrument


clean:
	rm -f *.o *.so *.a test_static test_dynamic

run: 
	@echo
	@echo static link
	./test_static
	@echo
	@echo dynamic link
	LD_LIBRARY_PATH=. ./test_dynamic



