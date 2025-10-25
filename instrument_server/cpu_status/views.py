
from django.http import JsonResponse
from django.views.decorators.http import require_http_methods
from cpu_status import cpu_wrapper as inst
from django.views.decorators.csrf import csrf_exempt # for testing

@require_http_methods(["GET"])
def get_temp(request):
    """Read the current cpu temperature."""
    try:
        temp = inst.read_cpu_temp()
        return JsonResponse({"temp": temp})
    except Exception as e:
        return JsonResponse({"status": "error", "message": str(e)}, status=500)


