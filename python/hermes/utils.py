from __future__ import print_function
import xdrlib
import sys

def xdr_pack_string(xdr, s):
    if sys.version_info[0] < 3:
        xdr.pack_string(s)
    else:
        xdr.pack_string(bytearray(s, 'utf-8'))

def xdr_unpack_string(xdr):
    if sys.version_info[0] < 3:
        return xdr.unpack_string()
    else:
        return xdr.unpack_string().decode('utf-8')
