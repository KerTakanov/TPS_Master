from entry_reader import EntryReader
from led import Led
from door import Door
from actor import Actor
from exit_reader import ExitReader
from building import Building
from laser import Laser
from alarm import Alarm
from journal import Journal
from fire_detector import FireDetector
from sls import SLS


if __name__ == '__main__':
    ctx = dict()

    parts = [Led, Door, EntryReader, ExitReader, Building, Laser, Alarm, Journal, FireDetector, SLS]
    objs_parts = []
    actor = Actor(ctx)

    for p in parts:
        objs_parts += [p(ctx)]

    for p in objs_parts:
        p.launch()

    actor.work()

    for p in objs_parts:
        p.join()
