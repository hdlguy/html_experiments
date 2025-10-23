// fpga_test.cpp - simple C++ program to test libinstrument library.
//
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include "fpga.h"

extern "C" {
#include "instrument.h"
}

int main()
{

    int status;

    status = fpga_open();
    if (status != 0) return(1);

    fpga_close();

    return(0);
}


