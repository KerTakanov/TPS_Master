if __name__ == '__main__':
    from graph import Graph
    from check_hamiltonien_strat_test import CheckHamiltonienStratTest

    testgraph = Graph()
    """testgraph.nodes = ["s" + str(i) for i in range(1, 6)]
    testgraph.edge["s1"] = ["s2", "s4"]
    testgraph.edge["s2"] = ["s3"]
    testgraph.edge["s3"] = ["s5", "s4"]
    testgraph.edge["s4"] = ["s5"]
    testgraph.edge["s5"] = ["s2", "s1"]

    print(testgraph.check_strat.check())
    """
    suites = testgraph.get_strat.get()
    for s in suites.suites:
        print(s)
    print("On passe le filtre")
    filtered = [s for s in suites.suites if not testgraph.check_strat.check(s)]
    print(filtered, suites.suites)
    for f in filtered:
        print(f)
    """
    s1 -> s2, s2 -> s3, s3 -> s5, s5 -> s2 *stop
                                  s5 -> s1 *stop

                        s3 -> s4, s4 -> s5, s5 -> s2 *stop
                                            s5 -> s1
        -> s4, s4 -> s5, s5 -> s2, s2 -> s3, s3 -> s5 *stop
                                             s3 -> s4 *stop
                         s5 -> s1 *stop

[
[s1, s2, s3, s5, s2] x
[s1, s2, s3, s5, s1] x
[s1, s2, s3, s4, s5, s2] x
[s1, s2, s3, s4, s5, s1] x
]
"""
