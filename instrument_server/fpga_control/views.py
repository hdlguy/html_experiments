from django.http import JsonResponse
from fpga_control import libinstrument_wrapper as inst

# Initialize FPGA once (optional)
inst.fpga_open()

def set_led(request, value):
    """Example URL: /fpga/led/3/"""
    val = int(value)
    inst.fpga_set_led(val)
    led = inst.fpga_get_led()
    return JsonResponse({"requested": val, "actual": led})

def read_bram(request):
    """Return first few words of BRAM as JSON."""
    data = inst.fpga_read_bram()
    return JsonResponse({"bram_first_8": data[:8]})

