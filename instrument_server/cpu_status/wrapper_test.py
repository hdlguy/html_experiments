# This little module tests libinstrument_wrapper.py

import cpu_wrapper as inst
import time

cpu_temperature = inst.read_cpu_temp()
print(f'cpu_temperature = {cpu_temperature}')

