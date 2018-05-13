import check_hamiltonien_strat_cho

from src import get_cycles_strat


class Graph:
    default_check_strat = check_hamiltonien_strat_cho.CheckHamiltonienStratCHO
    default_get_strat = get_cycles_strat.GetCycleStrats

    MODE_GRAPH = "graph"
    MODE_CS = "cs"

    def __init__(self, filepath=None, check_strat=None, get_strat=None, mode=MODE_GRAPH):
        self.name = ""
        self.nodes = list()
        self.edge = dict()
        self.mode = mode
        self.max_val = None
        self.k = None

        self.check_strat = check_strat(self) if check_strat else Graph.default_check_strat(self)
        self.get_strat = get_strat(self) if get_strat else Graph.default_get_strat(self)

        if filepath and mode == Graph.MODE_GRAPH:
            self.parse_file(open(filepath).readlines())
        if filepath and mode == Graph.MODE_CS:
            self.parse_file_cs(open(filepath).readlines())

    def parse_file(self, content: str):
        self.name = content[0].strip().replace('{', '').strip()
        self.nodes = [s for s in content[1].split()]
        content.pop(0)
        content.pop(0)

        for l in content:
            l = l.replace('}', '').strip()
            if l:
                values = l.split("->")
                lvalue = values[0]
                rvalue = values[1]

                if lvalue not in self.edge:
                    self.edge[lvalue] = [rvalue]
                else:
                    self.edge[lvalue] += [rvalue]
