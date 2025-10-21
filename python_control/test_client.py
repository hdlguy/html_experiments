
import libinstrument_wrapper as inst
import time

print("Initializing instrument...")
inst.init()

for mode in [0, 1, 2, 3]:
    print(f"\nSetting mode to {mode}")
    inst.set_mode(mode)

    # Simulate waiting for the instrument to stabilize
    time.sleep(0.2)

    status = inst.read_status()
    print(f"Mode {mode} → Status: {status}")


