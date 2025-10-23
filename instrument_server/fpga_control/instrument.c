// instrument.c - this is a mock up of a library to access an FPGA over PCIe.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "fpga.h"
#include "instrument.h"

static int fpga_initialized = 0;
static uint32_t regarray[NUM_REGS]; // stand-in for FPGA register file
static uint32_t* regptr;
static uint32_t bramarray[BRAM_SIZE]; // stand-in for bram memory in the FPGA
static uint32_t* bramptr;

// open the PCIe driver and get a pointer to the FPGA memory map
int fpga_open()
{
    // get pointers
    regptr = regarray;
    bramptr = bramarray;

    //
    regptr[FPGA_VERSION] = 0x00000101;
    regptr[FPGA_ID] = 0xdeadbeef;
    fpga_initialized = 1;

    return(0);
}

// 
int fpga_close()
{
    return(0);
}

// Get the current fpga ID register
int fpga_get_id(uint32_t* val)
{
    *val = regptr[FPGA_ID];
    return(0);
}

// Get the current fpga version register
int fpga_get_version(uint32_t* val)
{
    *val = regptr[FPGA_VERSION];
    return(0);
}

// Set the visible LEDs on the board
int fpga_set_led(uint32_t val)
{
    regptr[FPGA_LED] = val;
    return(0);
}

// Get the current value of the LEDs
int fpga_get_led(uint32_t* val)
{
    *val = regptr[FPGA_LED];
    return(0);
}

// get data from block ram
int fpga_read_bram(uint32_t* data)
{
    for (int i=0; i<BRAM_SIZE; i++) data[i] = bramptr[i];
    return(0);
}

// write data to block ram
int fpga_write_bram(uint32_t* data)
{
    for (int i=0; i<BRAM_SIZE; i++) bramptr[i] = data[i];
    return(0);
}

