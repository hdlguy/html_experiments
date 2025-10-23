// instrument.h - this is a mock up of a library to access an FPGA over PCIe.
//
#include <stdint.h>

int fpga_open();
int fpga_close();
int fpga_set_led(uint32_t val);
int fpga_get_led(uint32_t* val);
int fpga_read_bram(uint32_t* data);
int fpga_write_bram(uint32_t* data);

