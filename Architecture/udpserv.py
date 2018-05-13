import socketserver


class ThreadedUDPServer(socketserver.ThreadingMixIn, socketserver.UDPServer):
    pass
