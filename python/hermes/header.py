import struct
import zmq

class Header(object):
    def __init__(self, encoding, more):
        self.encoding = encoding
        self.more = more

    @classmethod
    def recv(cls, socket):
        frame = socket.recv(0, False)
        return cls(frame.buffer, frame.get(zmq.MORE))

    def send(self, socket):
        flags = zmq.SNDMORE if self.more else 0
        socket.send(self.encoding, flags)

    def magic(self):
        return struct.unpack_from('<b', self.encoding, 0)[0]

    def number(self):
        return struct.unpack_from('<i', self.encoding, 4)[0]

class RequestHeader(Header):
    @classmethod
    def create(cls, number, more):
        return cls(struct.pack('<bxxxi', 0x01, number), more)

class ReplyHeader(Header):
    @classmethod
    def create(cls, number, more):
        return cls(struct.pack('<bxxxi', 0x02, number), more)
