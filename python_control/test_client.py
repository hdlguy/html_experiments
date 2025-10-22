
import libinstrument_wrapper as inst
import time

print("Initializing instrument...")
inst.fpga_open()

for mode in [0, 1, 2, 3]:

    # Simulate waiting for the instrument to stabilize
    time.sleep(0.2)


    status = inst.fpga_set_led(mode)
    print(f"led {mode} → Status: {status}")

    led = inst.fpga_get_led()
    print(f"led = {led}")



