
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

//static int initialized = 0;
//static int fake_status = 42;

static int fpga_initialized = 0;
static uint32_t regarray[16];
static uint32_t* regptr;
/*
int instrument_init(void) {
    srand(time(NULL));
    initialized = 1;
    printf("[libinstrument] initialized\n");
    return 0;
}

int instrument_set_mode(int mode) {
    if (!initialized) return -1;
    printf("[libinstrument] mode set to %d\n", mode);
    fake_status = mode * 10 + (rand() % 10);
    return 0;
}

int instrument_read_status(int *status) {
    if (!initialized) return -1;
    *status = fake_status;
    printf("[libinstrument] status read: %d\n", *status);
    return 0;
}
*/

int fpga_open()
{
    regptr = regarray;
    fpga_initialized = 1;
    return(0);
}

int fpga_set_led(uint32_t val)
{
    regptr[2] = val;
    return(0);
}

int fpga_get_led(uint32_t* val)
{
    *val = regptr[2];
    return(0);
}


