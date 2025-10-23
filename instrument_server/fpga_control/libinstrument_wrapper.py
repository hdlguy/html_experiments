
import ctypes
import os

# some constants that must match fpga.h
BRAM_SIZE = 4096
BRAM_WORDS = BRAM_SIZE // 4

# Load the shared library (use absolute path for safety)
_libpath = os.path.join(os.path.dirname(__file__), "libinstrument.so")
_lib = ctypes.CDLL(_libpath)

# define args and return value
_lib.fpga_open.restype = ctypes.c_int

_lib.fpga_set_led.argtypes = [ctypes.c_int]
_lib.fpga_set_led.restype = ctypes.c_int

_lib.fpga_get_led.argtypes = [ctypes.POINTER(ctypes.c_int)]
_lib.fpga_get_led.restype = ctypes.c_int

# python wrapper functions
def fpga_open():
    rc = _lib.fpga_open()
    if rc != 0:
        raise RuntimeError("fpga_open failed")
    return 0

def fpga_set_led(val: int):
    rc = _lib.fpga_set_led(val)
    if rc != 0:
        raise RuntimeError(f"fpga_set_led({val}) failed")
    return 0

def fpga_get_led() -> int:
    value = ctypes.c_int()
    rc = _lib.fpga_get_led(ctypes.byref(value))
    if rc != 0:
        raise RuntimeError("fpga_get_led failed")
    return value.value

def fpga_read_bram() -> list[int]:
    """Read FPGA BRAM contents into a Python list of uint32 values."""
    buffer = (ctypes.c_uint32 * BRAM_WORDS)()
    rc = _lib.fpga_read_bram(buffer)
    if rc != 0:
        raise RuntimeError("fpga_read_bram failed")
    return list(buffer)


def fpga_write_bram(data: list[int]):
    """Write a Python list of uint32 values into FPGA BRAM."""
    if len(data) != BRAM_WORDS:
        raise ValueError(f"Expected {BRAM_WORDS} words, got {len(data)}")
    array_type = ctypes.c_uint32 * BRAM_WORDS
    buffer = array_type(*data)
    rc = _lib.fpga_write_bram(buffer)
    if rc != 0:
        raise RuntimeError("fpga_write_bram failed")
    return 0

