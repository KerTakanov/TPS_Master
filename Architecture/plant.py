import building_part
import socket
import pickle
import random
from message import Message


class Designer(building_part.BuildingPart):
    def __init__(self, ctx):
        super(Designer, self).__init__('designer', ctx)

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.PRODUCT:
            print("Designers received product!")
            self.msg('plant', Message(Message.PROPOSITION, {'id': msg.data.name, 'cost': msg.data.cdc['cost'] + random.randint(1, 20)}))

        return True


class Workshop(building_part.BuildingPart):
    def __init__(self, ctx):
        super(Workshop, self).__init__('workshop', ctx)

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.PRODUCT:
            print("Workshopers received product!")
            self.msg('plant', Message(Message.PROPOSITION, {'id': msg.data.name, 'delay': msg.data.cdc['delay'] + random.randint(1, 10)}))

        return True


class Plant(building_part.BuildingPart):
    def __init__(self, ctx):
        super(Plant, self).__init__('plant', ctx)
        self.propositions = {}
        self.address = ('', 33333)

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        self.print(f"Recv: {msg.type}")

        if msg.type == Message.PRODUCT:
            print("Sending product to designer and workshop...")
            self.msg('workshop', msg)
            self.msg('designer', msg)

        elif msg.type == Message.PROPOSITION:
            self.print(msg.data)
            if msg.data['id'] in self.propositions:
                self.propositions[msg.data['id']].update(msg.data)
                print(f"Sending PROPOSITION {self.propositions[msg.data['id']]}")

                sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
                sock.sendto(pickle.dumps(Message(Message.PROPOSITION, self.propositions[msg.data['id']])), ('localhost', 33333))

                self.propositions.pop(msg.data['id'])
            else:
                self.propositions[msg.data['id']] = msg.data

        return True


if __name__ == '__main__':
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("", 0))
    print("Server started at 0.0.0.0 port " + str(server.getsockname()[1]))

    ctx = {}

    plant = Plant(ctx)
    workshop = Workshop(ctx)
    designer = Designer(ctx)

    plant.launch()
    workshop.launch()
    designer.launch()

    # On dit à notre Logistics qu'on se connecte
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(pickle.dumps(Message(Message.CONNECTED, server.getsockname()[1])), ('localhost', 33333))

    print(f"ctx:{ctx}")

    while True:
        data, addr = server.recvfrom(1024)
        print(f"Data recv: {data}")
        msg = pickle.loads(data)
        plant.parent_pipe.send(msg)
