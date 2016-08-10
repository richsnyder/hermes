class Client(object):
    def __init__(self, context, endpoint, type):
        self.socket = context.socket(type)
        self.socket.connect(endpoint)

    def close(self):
        self.socket.close()
        self.socket = None
