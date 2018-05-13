if __name__ == '__main__':
    graph = list()
    print("Ecrivez le texte représentant le graphe:")
    while True:
        l = input()
        if l == '}':
            graph += ['}']
            break
        graph += [l]

    from src.graph import Graph
    g = Graph()
    g.parse_file(graph)

    resolved = g.check_strat.check()
    if resolved:
        print(False)  # False, 0 = problème résolu
    else:
        print(True)  # True, 1 = problème non résolu
