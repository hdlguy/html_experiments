
from django.urls import path
from . import views

urlpatterns = [
    path("temp/", views.get_temp, name="get_temp"),
]
