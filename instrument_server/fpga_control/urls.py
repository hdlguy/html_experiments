
from django.urls import path
from . import views

urlpatterns = [
    path("led/<int:value>/", views.set_led, name="set_led"),  # POST: set LEDs
    path("led/", views.get_led, name="get_led"),              # GET: read LEDs
    path("bram/read/", views.read_bram, name="read_bram"),
    path("bram/write/", views.write_bram, name="write_bram"),
]
