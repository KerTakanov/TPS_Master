from building_part import BuildingPart
from message import Message


class SLS(BuildingPart):
    def __init__(self, ctx):
        super(SLS, self).__init__('SLS', ctx)

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.FIRE:
            self.print(f"saving {msg.data}")

        elif msg.type == Message.STOP:
            return False

        return True
