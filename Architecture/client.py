import socket
import sys
from message import Message
from product import Product
import pickle

HOST, PORT = "localhost", 33333


def product():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    data = pickle.dumps(Message(Message.PRODUCT, Product("aluminium", "leclerc", {
        'cost': 10,
        'requirements': ['aluminium'],
        'delay': 3,
        'quantity': 5
    })))

    sock.sendto(data + b"\n", (HOST, PORT))
    print("Sent:     {}".format(data))


def show():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    data = pickle.dumps(Message(Message.SHOW, ""))

    sock.sendto(data + b"\n", (HOST, PORT))
    print("Sent:     {}".format(data))


def accept(nb):
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    data = pickle.dumps(Message(Message.ACCEPT, int(nb)))

    sock.sendto(data + b"\n", (HOST, PORT))
    print("Sent:     {}".format(data))


if __name__ == '__main__':
    q = input("=> ")
    while q != "stop":
        if q == 'p':
            product()
        elif q == 's':
            show()
        elif 'a' in q:
            accept(q.split(' ')[1])

        q = input("=> ")
