# instrument server
This folder holds an attempt to access a C library from a web server running Django.

## files

### ./
manage.py - this is the module used to control Django start, stop, migrate, etc.

### ./fpga_control/
This folder holds the C library and the necessary python modules to expose it to Django.

instrument.c - The C library. It is a mock up of a library that will control an FPGA over PCIe.
fpga_test.cpp - C++ program to test instrument.c
Makefile - builds the C/C++, type "make" and then "make run"
libinstrument_wrapper.py - python module wraps the C functions to be callable in python
test_client.py - tests the library through libinstrument_wrapper.py
views.py - tells Django how to translate HTML GET and POST requests to libinstrument_wrapper.py function calls
urls.py - tells Django what URLs go to which function call.

### ./instrument_server/
This folder contains the standard files created when the Django project is created.


