import multiprocessing
from message import Message
from building_part import BuildingPart
from door import Door
from led import Led


class EntryReader(BuildingPart):
    def __init__(self, ctx):
        super().__init__('Entry Reader', ctx)
        self.authorized_badges = list()
        self.last_badge = None

    def work(self):
        while self.wait_badge():
            pass

    def wait_badge(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.print(f"badge {msg.data.name}")

            if self.is_authorized(msg.data):
                self.print("authorized !")

                self.msg('Led', Message(Message.DATA, Led.GREEN))
                self.msg('Door', Message(Message.DATA, Door.OPEN))

                self.last_badge = msg.data
            else:
                self.print("not authorized !")

                self.msg('Led', Message(Message.DATA, Led.RED))

        elif msg.type == Message.AUTHORIZE:
            self.print(f"authorize badge {msg.data.name}")
            self.authorize(msg.data)

        elif msg.type == Message.IS_AUTHORIZED:
            self.msg('Exit Reader', Message(Message.IS_AUTHORIZED, (msg.data, self.is_authorized(msg.data))))

        elif msg.type == Message.PERSON_DETECTED:
            self.msg('Alarm', Message(Message.DATA, self.last_badge is not None))

            if self.last_badge is not None:
                self.msg('Journal', Message(Message.ENTRY, self.last_badge))

                self.msg('Building', Message(Message.ENTRY, self.last_badge))

                self.msg('Door', Message(Message.DATA, Door.CLOSE))

            self.last_badge = None

        elif msg.type == Message.STOP:
            return False

        return True

    def authorize(self, badge):
        if badge.name not in [badge_name for badge_name in self.authorized_badges]:
            self.authorized_badges.append(badge.name)

    def is_authorized(self, badge):
        return badge.name in [badge for badge in self.authorized_badges]
