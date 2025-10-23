# This little module tests libinstrument_wrapper.py

import libinstrument_wrapper as inst
import time

print("Initializing instrument...")
inst.fpga_open()

fpga_id = inst.fpga_get_id()
print("fpga_id = " + hex(fpga_id & 0xffffffff))

fpga_version = inst.fpga_get_version()
print("fpga_version = " + hex(fpga_version & 0xffffffff))


for mode in [0, 1, 2, 3]:

    # Simulate waiting for the instrument to stabilize
    #time.sleep(0.2)


    status = inst.fpga_set_led(mode)
    print(f"led {mode} → Status: {status}")

    led = inst.fpga_get_led()
    print(f"led = {led}")



data_out = [i for i in range(inst.BRAM_WORDS)]
inst.fpga_write_bram(data_out)
data_in = inst.fpga_read_bram()
print("First 8 words:", data_in[:8])

