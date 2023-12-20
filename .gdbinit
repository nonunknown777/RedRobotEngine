python
import sys
sys.path.insert(0, '/usr/share/gcc-<version>/python')

from gdb import printers
from libstdcxx.v6.printers import register_libstdcxx_printers

register_libstdcxx_printers(printers)
end