from src import suite


class GetCycleStrats:
    def __init__(self, graph):
        self.graph = graph

    def get(self):
        def get2(graph, start_node, node, suite, suites):
            if all([item in suite for item in graph.nodes]):
                suites.append(suite + [start_node])

            if node not in graph.edge:
                return suites

            for n in graph.edge[node]:
                if n not in suite:
                    get2(graph, start_node, n, suite + [n], suites)

            return suites

        suites = suite.Suite()
        for i, node in enumerate(self.graph.nodes):
            get2(self.graph, node, node, [node], suites)

        return suites
