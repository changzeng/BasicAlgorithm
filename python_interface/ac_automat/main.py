# encoding: utf-8

import ctypes

ll = ctypes.cdll.LoadLibrary
lib = ll("./ac_automat.so")

lib.print()
