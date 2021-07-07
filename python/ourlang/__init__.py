#from _ourlang import *
import sys
import ctypes
flags = sys.getdlopenflags()
sys.setdlopenflags(flags | ctypes.RTLD_GLOBAL)
from _ourlang import *
sys.setdlopenflags(flags)
