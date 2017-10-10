import copy


class CheckHamiltonienStratCHO:
    def __init__(self, graph):
        self.graph = graph

    def check(self):
        resolved = False
        cache = copy.deepcopy(self.graph)

        for n in self.graph.nodes:
            stack = [n]
            print("-" * 20)
            while not resolved:
                popped = None
                if len(cache.edge[stack[-1]]):
                    popped = cache.edge[stack[-1]].pop()
                    while popped in stack and len(cache.edge[stack[-1]]) > 0:
                        popped = cache.edge[stack[-1]].pop()

                if popped and popped not in stack:
                    stack.append(popped)
                    print(f"{stack[-2]}->{popped}")
                elif len(stack) > 0:
                    cache.edge[stack[-1]] = self.graph.edge[stack[-1]]
                    print(f"BT: {stack.pop()}")

                if len(stack) == 0:
                    break

                complete = len(self.graph.nodes) == len(stack)
                resolved = stack[0] in self.graph.edge[stack[-1]] and complete
            if resolved:
                break

        return resolved