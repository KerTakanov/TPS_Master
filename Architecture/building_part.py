import multiprocessing
from message import Message


class BuildingPart:
    def __init__(self, name, ctx):
        ctx[name] = self
        self.name = name
        self.ctx = ctx
        self.process = multiprocessing.Process(target=self.work)
        self.parent_pipe, self.child_pipe = multiprocessing.Pipe()
        self.parent_queue, self.child_queue = multiprocessing.Queue(), multiprocessing.Queue()

    def print(self, msg):
        print(f"[{self.name}]: {msg}")

    def launch(self):
        self.process.start()

    def join(self):
        self.process.join()

    def work(self):
        raise NotImplementedError

    def msg(self, other_part, msg):
        self.ctx[other_part].parent_pipe.send(msg)
