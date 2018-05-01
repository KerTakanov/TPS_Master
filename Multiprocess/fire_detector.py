from building_part import BuildingPart
from message import Message


class FireDetector(BuildingPart):
    def __init__(self, ctx):
        super(FireDetector, self).__init__('Fire Detector', ctx)

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.print("fire detected!")
            self.msg('Building', Message(Message.FIRE, ''))

        elif msg.type == Message.STOP:
            return False

        return True