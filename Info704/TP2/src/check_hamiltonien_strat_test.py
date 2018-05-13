class CheckHamiltonienStratTest:
    def __init__(self, graph):
        self.graph = graph

    def check(self, nodes):
        if len(nodes) <= 1:
            return False

        already_checked = list()
        prec = nodes[0]
        for n in nodes[1:]:
            if n in already_checked or n not in self.graph.edge[prec]:
                return True

            prec = n
            already_checked += [n]

        return not all([item in already_checked for item in self.graph.nodes])
