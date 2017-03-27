__author__ = 'CFWLoader'

import networkx as nx;
import matplotlib.pyplot as plt;

G = nx.read_gml('./lesmiserables.gml', relabel=True)

cliques = list(nx.find_cliques(G))

print(max(cliques, key=lambda l: len(l)))