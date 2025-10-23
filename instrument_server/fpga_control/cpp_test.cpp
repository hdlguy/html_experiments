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

    //fpga_get_id(&rval);
    printf("FPGA_ID = 0x%08x\n", rval);

    //fpga_get_version(&rval);
    printf("FPGA_VERSION = 0x%08x\n", rval);

    for (int i=0; i<4; i++) {
        fpga_get_led(&rval);
        printf("fpga_get_led -> 0x%08x\n", rval);
        wval = rval + 1;
        fpga_set_led(wval);
    }

    uint32_t write_data[BRAM_SIZE], read_data[BRAM_SIZE];
    for (int i=0; i<BRAM_SIZE; i++) write_data[i] = rand();
    fpga_write_bram(write_data);
    fpga_read_bram(read_data);
    int errors = 0;
    for (int i=0; i<BRAM_SIZE; i++) if (write_data[i] != read_data[i]) errors++;
    printf("bram test: errors = %d\n", errors);

    fpga_close();

    return(0);
}


