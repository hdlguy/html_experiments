
import libinstrument_wrapper as inst
import time

print("Initializing instrument...")
inst.init()
inst.fpga_open()

for mode in [0, 1, 2, 3]:
    print(f"\nSetting mode to {mode}")
    inst.set_mode(mode)

    # Simulate waiting for the instrument to stabilize
    time.sleep(0.2)

    status = inst.read_status()
    print(f"Mode {mode} → Status: {status}")

    status = inst.fpga_set_led(mode)
    print(f"led {mode} → Status: {status}")
    led = inst.fpga_get_led()
    print(f"led = {led}")



