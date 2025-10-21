
import ctypes

# Load your library
lib = ctypes.CDLL("./libinstrument.so")

# Define argument and return types
lib.instrument_init.restype = ctypes.c_int
lib.instrument_set_mode.argtypes = [ctypes.c_int]
lib.instrument_set_mode.restype = ctypes.c_int
lib.instrument_read_status.argtypes = [ctypes.POINTER(ctypes.c_int)]
lib.instrument_read_status.restype = ctypes.c_int

# Call functions
assert lib.instrument_init() == 0

# Try setting different modes
for mode in [1, 2, 3]:
    lib.instrument_set_mode(mode)
    status = ctypes.c_int()
    rc = lib.instrument_read_status(ctypes.byref(status))
    if rc != 0:
        raise RuntimeError("FPGA not initialized")

    print(f"Mode={mode} → Status={status.value}")



