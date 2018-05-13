class Suite:
    def __init__(self):
        self.suites = list()

    def append(self, suite):
        self.suites += [suite]
        return self
