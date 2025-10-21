
#include <stdio.h>

extern "C" {
#include "libinstrument.h"
}

int main()
{

    void* fpga_addr = open_fpga();

    printf("fpga_addr = %p\n", fpga_addr);

    printf("fpga version = 0x%08x\n", get_fpga_version(fpga_addr));
    printf("fpga ID = 0x%08x\n", get_fpga_id(fpga_addr));

    close_fpga(fpga_addr);

    return(0);
}
