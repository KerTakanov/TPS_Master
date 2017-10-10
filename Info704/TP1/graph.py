import check_hamiltonien_strat_cho
import get_cycles_strat


class Graph:
    default_check_strat = check_hamiltonien_strat_cho.CheckHamiltonienStratCHO
    default_get_strat = get_cycles_strat.GetCycleStrats

    def __init__(self, filepath=None, check_strat=None, get_strat=None):
        self.name = ""
        self.nodes = list()
        self.edge = dict()

        self.check_strat = check_strat(self) if check_strat else Graph.default_check_strat(self)
        self.get_strat = get_strat(self) if get_strat else Graph.default_get_strat(self)

        if filepath:
            self.parse_file(open(filepath).readlines())

    # content: string[]
    def parse_file(self, content):
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


if __name__ == "__main__":
    g = Graph("./graphs/graph1")
    print(g.name)
    print(g.nodes)
    print("--------")
    print(g.edge)
