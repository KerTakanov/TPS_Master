from building_part import BuildingPart
from message import Message
from badge import Badge
from time import sleep


class Actor(BuildingPart):
    def __init__(self, ctx):
        super(Actor, self).__init__('actor', ctx)
        self.badge = Badge('actor')

    def work(self):
        while self.command():
            sleep(0.2)

    def command(self):
        print("Commands: send, badge, enter, leave, laser, authorize, stop, fire")
        command = input('-> ')

        if command == 'send':
            msg = Message(Message.DATA, input('Message data -> '))
            self.msg(input('Message target -> '), msg)

        if command == 'enter':
            self.msg('Entry Reader', Message(Message.DATA, self.badge))

        if command == 'leave':
            self.msg('Exit Reader', Message(Message.DATA, self.badge))

        if command == 'laser':
            self.msg('Laser', Message(Message.DATA, ''))

        if command == 'badge':
            self.badge = Badge(input('Badge name -> '))

        if command == 'authorize':
            self.msg('Entry Reader', Message(Message.AUTHORIZE, self.badge))

        if command == 'fire':
            self.msg('Fire Detector', Message(Message.DATA, ''))

        if command == 'stop':
            return False

        return True