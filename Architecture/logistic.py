from building_part import BuildingPart
from message import Message
import socket
import pickle


class Logistic(BuildingPart):
    def __init__(self, ctx):
        super(Logistic, self).__init__('logistic', ctx)
        self.plants = []
        self.propositions = []

    def work(self):
        while self.wait_order():
            pass

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.CONNECTED:
            self.print(f"Plant {msg.data} connected")
            self.plants += [msg.data]
        elif msg.type == Message.PRODUCT:
            self.print("Sending product to plants...")
            for plant in self.plants:
                sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                sock.sendto(pickle.dumps(msg), ('localhost', plant))
        elif msg.type == Message.PROPOSITION:
            self.print("Received proposition")
            self.propositions += [msg.data]
        elif msg.type == Message.SHOW:
            self.print("Proposal:")
            for proposition in self.propositions:
                self.print(proposition)
        elif msg.type == Message.ACCEPT:
            self.print(f"Client accepted proposition {msg.data}. Removing other proposal.")
            self.propositions.clear()

        return True


if __name__ == '__main__':
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("", 33333))
    print("Server started at 0.0.0.0 port " + str(server.getsockname()[1]))

    ctx = {}

    logistic = Logistic(ctx)
    logistic.launch()

    print(f"ctx:{ctx}")

    while True:
        data, addr = server.recvfrom(1024)
        print(f"Data recv: {data}")
        msg = pickle.loads(data)
        logistic.parent_pipe.send(msg)
