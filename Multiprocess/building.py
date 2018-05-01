from building_part import BuildingPart
from message import Message
from door import Door


class Building(BuildingPart):
    def __init__(self, ctx):
        super(Building, self).__init__('Building', ctx)
        self.inside = list()

    def register(self, badge):
        if badge.name not in self.inside:
            self.inside.append(badge.name)
            self.print(f"badge {badge.name} registered in building")
        else:
            self.print(f"badge {badge.name} already registered !")

    def unregister(self, badge):
        if badge.name in self.inside:
            self.inside.remove(badge.name)
            self.print(f"badge {badge.name} unregistered from building")
        else:
            self.print(f"badge {badge.name} not registered in building !")

    def work(self):
        while self.wait_order():
            pass

    def is_in(self, badge):
        return badge, badge.name in self.inside

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.IS_IN:
            self.print(f"is {msg.data.name} in ? -> {'yes' if self.is_in(msg.data)[1] else 'no'}")
            self.msg('Exit Reader', Message(Message.IS_IN, self.is_in(msg.data)))

        elif msg.type == Message.ENTRY:
            self.print(f"registering {msg.data.name}")
            self.register(msg.data)

        elif msg.type == Message.EXIT:
            self.print(f"unregistering {msg.data.name}")
            self.unregister(msg.data)

        elif msg.type == Message.FIRE:
            self.msg('SLS', Message(Message.FIRE, self.inside))
            self.msg('Door', Message(Message.DATA, Door.EMERGENCY))

        elif msg.type == Message.STOP:
            return False

        return True
