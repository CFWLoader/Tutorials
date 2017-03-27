__author__ = 'CFWLoader'

import networkx as nx;
import matplotlib.pyplot as plt;

# data source: https://gephi.org/datasets/lesmiserables.gml.zip
G = nx.read_gml('./lesmiserables.gml', relabel=True)

Gt = G.copy()

dn = nx.degree(Gt)

for n in Gt.nodes():
    if dn[n] <= 10:
        Gt.remove_node(n)

nx.draw(Gt,node_size=0,edge_color='b',alpha=.2,font_size=12)

plt.savefig('./lesmiserables_extracted.jpg')