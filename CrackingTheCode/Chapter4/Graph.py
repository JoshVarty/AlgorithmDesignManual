

class Graph:
    def __init__(nodes):
        self.nodes = nodes

class Node:
    def __init__(self, value):
        self.data = value

        #Can be used as either a binary tree or regular graph
        self.children = []
        self.left = None
        self.right = None

def dfs(node, list = None):

    if list is None:
        list = []
        dfs(node, list)
        return list

    if node.left is not None:
        dfs(node.left, list)
   
    list.append(node.data)

    if node.right is not None:
        dfs(node.right, list)



node = Node(4)
node.left = Node(2)
node.right = Node(6)
node.left.left = Node(1)
node.left.right = Node(3)
node.right.left = Node(5)
node.right.right = Node(7)
result = dfs(node)
assert(result == [1,2,3,4,5,6,7])


