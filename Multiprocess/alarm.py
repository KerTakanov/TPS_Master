from building_part import BuildingPart
from message import Message


class Alarm(BuildingPart):
    ON = "on"
    OFF = "off"

    def __init__(self, ctx):
        super(Alarm, self).__init__('Alarm', ctx)

        self.state = Alarm.OFF
        self.alarm_count = 0
        self.alarm_triggers = []

    def work(self):
        while self.wait_orders():
            if self.state == Alarm.ON:
                self.alarm_count += 1
                self.print("!!!")

                if self.alarm_count > 10:
                    self.alarm_count = 0
                    self.change_state(Alarm.OFF)

    def change_state(self, new_state):
        self.print(new_state)
        self.state = new_state

    def wait_orders(self):
        msg = self.child_pipe.recv()

        if msg.type == Message.DATA:
            self.alarm_triggers += [msg.data]

            if len(self.alarm_triggers) == 2:
                if not self.alarm_triggers[0] and not self.alarm_triggers[1]:
                    self.change_state(Alarm.ON)

        elif msg.type == Message.STOP:
            return False

        return True
