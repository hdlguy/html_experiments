
from django.urls import path
from . import views

urlpatterns = [
    path("led/<int:value>/", views.set_led, name="set_led"),
    path("read_bram/", views.read_bram, name="read_bram"),
]

