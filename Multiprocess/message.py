class Message:
    CONNECTED = "connected"
    DATA = "data"
    AUTHORIZE = "authorize"
    STOP = "stop"

    IS_AUTHORIZED = "is_authorized"

    IS_IN = "is_in"
    ENTRY = "entry"
    EXIT = "exit"

    PERSON_DETECTED = "person_detected"
    FIRE = "fire"

    def __init__(self, type, data):
        self.type = type
        self.data = data
