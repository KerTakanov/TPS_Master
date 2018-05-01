from building_part import BuildingPart
from message import Message


class Journal(BuildingPart):
    def __init__(self, ctx):
        super(Journal, self).__init__('Journal', ctx)
        self.entries = list()

    def work(self):
        while self.wait_orders():
            pass

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.ENTRY:
            entry = f"{msg.data.name} entered building"
            self.print(f"entry added: {entry}")
            self.entries += [entry]

        elif msg.type == Message.EXIT:
            entry = f"{msg.data.name} leaved building"
            self.print(f"entry added: {entry}")
            self.entries += [entry]

        elif msg.type == Message.STOP:
            return False

        return True
