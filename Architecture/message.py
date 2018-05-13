class Message:
    CONNECTED = "connected"
    DATA = "data"

    PRODUCT = "product"
    PROPOSITION = "proposition"

    SHOW = "show"
    ACCEPT = "accept"

    def __init__(self, type, data):
        self.type = type
        self.data = data
