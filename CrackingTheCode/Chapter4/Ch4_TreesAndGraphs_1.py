#Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
from Graph import *

#Note: I'm pretty sure we have to run BFS (or DFS) on both nodes. Since the graph is directed, we might not 
#be able to reach one node from the other, but the reverse may be possible. Consider:
#   node2 -> 2 -> 3 -> node1

#We can't get from node1 to node2, but we can obviously get from node2 to node1.

def isPathBetweenNodes(graph, node1, node2):

    if node1 == node2:
        return True

    for node in graph.nodes:
        node.visited = False


    #BFS on node1
    queue = [node1]

    while len(queue) > 0:
        current = queue[0]
        del queue[0]
        current.visited = True

        if current == node2:
            return True

        for child in current.children:
            if not child.visited:
                queue.append(child)

    #BFS on node2
    queue = [node2]

    while len(queue) > 0:
        current = queue[0]
        del queue[0]
        current.visited = True

        if current == node1:
            return True

        for child in current.children:
            if not child.visited:
                queue.append(child)


    return False







    #Since the graph is directed, there may be a path between one of the nodes, but not the other.
    pass


