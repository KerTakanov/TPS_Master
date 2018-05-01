from building_part import BuildingPart
from message import Message
from time import sleep
from threading import Thread


class Led(BuildingPart):
    GREEN = 'green'
    RED = 'red'
    OFF = 'off'

    def __init__(self, ctx):
        super(Led, self).__init__('Led', ctx)
        self.state = Led.OFF

    def work(self):
        while self.wait_order():
            pass

    def change_state(self, new_state):
        self.print(new_state)
        self.state = new_state

    def differed_off(self):
        sleep(5)
        if self.state != Led.OFF:
            self.change_state(Led.OFF)

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.change_state(msg.data)

            Thread(target=self.differed_off).start()

            return True

        elif msg.type == Message.STOP:
            return False
