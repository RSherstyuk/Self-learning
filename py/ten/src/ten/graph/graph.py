import networkx as nx
import matplotlib.pyplot as plt
import numpy as np 

edges = [(1, 2), (1, 3), (2, 3), (2, 4), (2, 5), (3, 5)]
graph1 = nx.Graph()
graph1.add_edges_from(edges)

adjacency_matrix = np.array([
    [0, 1, 1, 0, 0],
    [1, 0, 1, 1, 1],
    [1, 1, 0, 0, 1],
    [0, 1, 0, 0, 0],
    [0, 1, 1, 0, 0]
])
graph2 = nx.from_numpy_array(adjacency_matrix)

degrees = [4, 2, 2, 2, 2]
graph3 = nx.random_degree_sequence_graph(degrees)  

plt.figure(figsize=(12, 4))

plt.subplot(131)
nx.draw(graph1, with_labels=True)
plt.title('Из списка рёбер')

plt.subplot(132)
nx.draw(graph2, with_labels=True)
plt.title('Из матрицы смежности')

plt.subplot(133)
nx.draw(graph3, with_labels=True)
plt.title('Из списка степеней')

plt.tight_layout()
plt.show()
