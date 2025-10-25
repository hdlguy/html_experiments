
import subprocess

def read_cpu_temp() -> float:
    """Read CPU temperature in Celsius."""
    try:
        with open("/sys/class/thermal/thermal_zone3/temp", "r") as f:
            temp_str = f.read().strip()
        return float(temp_str) / 1000.0
    except Exception as e:
        print(f"Error reading CPU temperature: {e}")
        return float("nan")

# /sys/class/hwmon/hwmon5/temp1_input
