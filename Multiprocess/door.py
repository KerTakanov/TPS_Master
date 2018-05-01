from building_part import BuildingPart
from message import Message
from time import sleep
from threading import Thread


class Door(BuildingPart):
    OPEN = "open"
    CLOSE = "close"
    EMERGENCY = "emergency"

    def __init__(self, ctx):
        super().__init__('Door', ctx)
        self.state = Door.CLOSE

    def work(self):
        while self.wait_order():
            pass

    def change_state(self, new_state):
        self.print(new_state)
        self.state = new_state

    def differed_close(self):
        sleep(5)
        if self.state == Door.OPEN:
            self.change_state(Door.CLOSE)

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.change_state(msg.data)

            Thread(target=self.differed_close).start()

            return True

        elif msg.type == Message.STOP:
            return False
