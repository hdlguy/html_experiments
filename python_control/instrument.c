// instrument.c - this is a mock up of a library to access an FPGA over PCIe.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

static int fpga_initialized = 0;
static uint32_t regarray[16];
static uint32_t* regptr;

// open the PCIe driver and get a pointer to the FPGA memory map
int fpga_open()
{
    regptr = regarray;
    fpga_initialized = 1;
    return(0);
}

// Set the visible LEDs on the board
int fpga_set_led(uint32_t val)
{
    regptr[2] = val;
    return(0);
}

// Get the current value of the LEDs
int fpga_get_led(uint32_t* val)
{
    *val = regptr[2];
    return(0);
}

int fpga_close()
{
    return(0);
}

