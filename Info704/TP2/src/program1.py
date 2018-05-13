if __name__ == '__main__':
    from src.check_hamiltonien_strat_test import CheckHamiltonienStratTest

    graph = list()
    print("Ecrivez le texte représentant le graphe:")
    while True:
        l = input()
        if l == '}':
            graph += ['}']
            break
        graph += [l]

    from src.graph import Graph
    g = Graph(check_strat=CheckHamiltonienStratTest)
    g.parse_file(graph)

    suites = g.get_strat.get()
    filtered = [s for s in suites.suites if g.check_strat.check(s)]
    if filtered:
        print(False)  # False, 0 = problème résolu
    else:
        print(True)  # True, 1 = problème non résolu
