class Server(object):
    def __init__(self, context, endpoint, type):
        self.socket = context.socket(type)
        self.socket.bind(endpoint)

    def close(self):
        self.socket.close()
        self.socket = None

    def serve(self, count=None):
        if count is None:
            while True:
                self.serve_once()
        else:
            for n in range(count):
                self.serve_once()
