// instrument.c - this is a mock up of a library to access an FPGA over PCIe.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "fpga.h"

static int fpga_initialized = 0;
static uint32_t regarray[NUM_REGS]; // stand-in for FPGA register file
static uint32_t* regptr;
static uint32_t bramarray[BRAM_SIZE/4]; // stand-in for bram memory in the FPGA

// open the PCIe driver and get a pointer to the FPGA memory map
int fpga_open()
{
    regptr = regarray;
    fpga_initialized = 1;
    return(0);
}

// 
int fpga_close()
{
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

// get data from block ram
int fpga_read_bram(uint32_t* data)
{
    for (int i=0; i<BRAM_SIZE/4; i++) data[i] = bramarray[i];
    return(0);
}

// write data to block ram
int fpga_write_bram(uint32_t* data)
{
    for (int i=0; i<BRAM_SIZE/4; i++) bramarray[i] = data[i];
    return(0);
}

