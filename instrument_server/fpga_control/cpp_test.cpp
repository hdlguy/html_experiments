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
    uint32_t wval, rval;

    status = fpga_open();
    if (status != 0) return(1);

    for (int i=0; i<4; i++) {
        fpga_get_led(&rval);
        printf("fpga_get_led -> 0x%08x\n", rval);
        wval = rval + 1;
        fpga_set_led(wval);
    }


    fpga_close();

    return(0);
}


