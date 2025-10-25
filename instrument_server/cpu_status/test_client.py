# This little module tests libinstrument_wrapper.py

import cpu_wrapper as inst

temp = str(inst.read_cpu_temp())
print("cpu temperature = " + temp)




