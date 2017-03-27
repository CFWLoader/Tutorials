__author__ = 'CFWLoader'

import networkx as nx;

G = nx.read_gml('./lesmiserables.gml', relabel=True)

deg = nx.degree(G)

degInt = []

for v in deg.values():
    degInt.append(int(v))

from numpy import percentile, mean, median

print(min(degInt))

print(percentile(degInt, 25))

print(median(degInt))

print(percentile(degInt, 75))

print(max(deg.values()))