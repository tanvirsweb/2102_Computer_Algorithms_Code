import igraph as ig
import matplotlib.pyplot as plt


with open("tvsp.txt", "r") as f:
    lines = f.read().splitlines()

edges = []
weights = []

# input vetices which should be colored: where repeater should be placed
with open("boster.txt", "r") as c:
    repeat = c.read().split()
colored=[]
for each in repeat:
    colored.append( int(each) )
    
# colored = [2,4]
'''will read from output of C++ file'''
for line in lines:
    li = line.split()
    edges.append((int(li[0])-1,int(li[1])-1))
    weights.append(int(li[2]))

g = ig.Graph(edges, directed=True)
g.es["weight"] = weights
'''edge sequence list'''
g.vs["label"] = range(1, len(g.vs) + 1)
'''vertex sequence list'''
#set colors
g.vs["color"] = ["red" if i in colored else "green" for i in range(1,len(g.vs)+1)]
layout = g.layout("rt")
'''layout to draw tree structure'''
g.vs["label_color"] = ["white"]

fix, ax = plt.subplots()
# set axes for tree
# normally root is botoom of tree and child is upper part.So make it in reverse dirction invert Y axis.
plt.gca().invert_yaxis()

ig.plot(g, target=ax, layout=layout, vertex_size=0.40, vertex_label_color = g.vs["label_color"] , edge_label=g.es["weight"])


plt.show()