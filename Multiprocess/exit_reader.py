from building_part import BuildingPart
from message import Message
from door import Door
from led import Led


class ExitReader(BuildingPart):
    def __init__(self, ctx):
        super(ExitReader, self).__init__('Exit Reader', ctx)
        self.last_badge = None

    def work(self):
        while self.wait_order():
            pass

    def wait_order(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.print(f"asking if {msg.data.name} is in building...")
            self.msg('Building', Message(Message.IS_IN, msg.data))

        elif msg.type == Message.IS_IN:
            print(msg.data)
            if msg.data[1]:
                self.print("asking for authorization to leave...")
                self.msg('Entry Reader', Message(Message.IS_AUTHORIZED, msg.data[0]))

        elif msg.type == Message.IS_AUTHORIZED:
            if msg.data[1]:
                self.print("has been authorized to leave building")
                self.msg('Door', Message(Message.DATA, Door.OPEN))
                self.msg('Led', Message(Message.DATA, Led.GREEN))

                self.last_badge = msg.data[0]
            else:
                self.print("is not authorized to leave building !")
                self.msg('Led', Message(Message.DATA, Led.RED))

        elif msg.type == Message.PERSON_DETECTED:
            self.msg('Alarm', Message(Message.DATA, self.last_badge is not None))

            if self.last_badge is not None:
                self.msg('Journal', Message(Message.EXIT, self.last_badge))
                self.msg('Building', Message(Message.EXIT, self.last_badge))
                self.msg('Door', Message(Message.DATA, Door.CLOSE))

            self.last_badge = None

        elif msg.type == Message.STOP:
            return False

        return True
