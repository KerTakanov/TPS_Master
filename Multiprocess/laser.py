from building_part import BuildingPart
from message import Message


class Laser(BuildingPart):
    def __init__(self, ctx):
        super(Laser, self).__init__('Laser', ctx)

    def work(self):
        while self.wait_order():
            pass

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.msg('Entry Reader', Message(Message.PERSON_DETECTED, ''))
            self.msg('Exit Reader', Message(Message.PERSON_DETECTED, ''))

        elif msg.type == Message.STOP:
            return False

        return True