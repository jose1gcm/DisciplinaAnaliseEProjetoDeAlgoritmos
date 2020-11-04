import networkx as nx
import matplotlib.pyplot as plt

G=nx.cubical_graph()
pos=nx.spring_layout(G)
#g= nx.petersen_graph()

#g.add_edges_from([(4,5),(5,6),(6,7),(7,8),(8,9),(9,1),(1,2),(2,4)])
#g.add_nodes_from([(7,5),(8,3)])
#g.add_edges_from([(6,7),(7,4)])
nx.draw(G,pos,nodelist=[0,1,2,3],node_color='blue',node_size=1500,alpha=1.0)
nx.draw(G,pos,nodelist=[4,5,6,7],node_color='blue',node_size=1500,alpha=1.0)
labels={}
labels[0]=r'$C$'
labels[1]=r'$O$'
labels[2]=r'$R$'
labels[3]=r'$I$'
labels[4]=r'$R$'
labels[5]=r'$E$'
labels[6]=r'$Z$'
labels[7]=r'$U$'
nx.draw_networkx_labels(G,pos,labels,font_size=30)
plt.show()
