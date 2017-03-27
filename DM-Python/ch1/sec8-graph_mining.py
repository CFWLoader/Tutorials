__author__ = 'CFWLoader'

import networkx as nx;

from pylab import savefig;

G = nx.read_gml('./lesmiserables.gml', relabel=True)

nx.draw(G, node_size = 0, edge_color = 'b', alpha = .2, font_size = 7)

savefig('./network_of_lesmiserables.jpg')
