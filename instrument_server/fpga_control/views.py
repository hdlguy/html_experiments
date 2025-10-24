
from django.http import JsonResponse
from django.views.decorators.http import require_http_methods
from fpga_control import libinstrument_wrapper as inst
from django.views.decorators.csrf import csrf_exempt # for testing


# Initialize FPGA once
inst.fpga_open()

@csrf_exempt # for testing
@require_http_methods(["POST"])
def set_led(request, value):
    """Set the FPGA LED register to a new value."""
    try:
        val = int(value)
        inst.fpga_set_led(val)
        return JsonResponse({"status": "ok", "led_set_to": val})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)


@require_http_methods(["GET"])
def get_led(request):
    """Read the current FPGA LED register value."""
    try:
        led = inst.fpga_get_led()
        return JsonResponse({"led_value": led})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)


@require_http_methods(["GET"])
def read_bram(request):
    """Read the first few BRAM words."""
    try:
        data = inst.fpga_read_bram()
        #return JsonResponse({"bram_first_8": data[:8]})
        return JsonResponse({"bram_data": data})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)


@csrf_exempt
@require_http_methods(["POST"])
def write_bram(request):
    """Write a list of uint32 words to BRAM."""
    try:
        import json
        payload = json.loads(request.body.decode("utf-8"))
        data = payload.get("data")
        if not isinstance(data, list):
            return JsonResponse({"status": "error", "message": "Expected 'data' as a list of integers"}, status=400)
        inst.fpga_write_bram(data)
        return JsonResponse({"status": "ok", "words_written": len(data)})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)


@require_http_methods(["GET"])
def get_id(request):
    """Read the current FPGA ID register value."""
    try:
        id = inst.fpga_get_id()
        return JsonResponse({"id": hex(id & 0xffffffff)})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)

@require_http_methods(["GET"])
def get_version(request):
    """Read the current FPGA VERSION register value."""
    try:
        version = inst.fpga_get_version()
        return JsonResponse({"version": hex(version & 0xffffffff)})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)

