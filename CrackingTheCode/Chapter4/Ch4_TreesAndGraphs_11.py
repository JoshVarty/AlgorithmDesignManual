# Random Node: You are implementing a binary tree class from scratch which, in addition to insert, find and delete has a method 
# getRandomNode() which returns a random node from the tree. All nodes should be equally likely to be chosen. Design and implement an 
# algorithm for get RandomNode, and explain how you would implement the rest of the methods.

#Option 1:
# Insert O(log n)   Increment counter `numberOfNodes`
# Delete O(log n)   Decrement counter `numberOfNodes`
# Find O(log n)
# getRandomNode O(n)

import random

class BinaryTree1:
    def __init__(self):
        self.numNodes = 0
        self.root = None

    def insert(self, value):
        # ...
        # Normal insert
        # ...

        self.numNodes = self.numNodes + 1

    def delete(self, value):
        # ...
        # Normal delete
        # ...

        self.numNodes = self.numNodes - 1
        
    def getRandomNode(self):

        randomNodeNumber = random.randint(0, self.numNodes + 1) #upper bound is exclusive
        (_, result) = dfsSearch(node, 0, randomNodeNumber)
        return result

    def dfsSearch(node, currentNodeNumber, targetNodeNumber):
        
        if currentNodeNumber == targetNodeNumber:
            return (currentNodeNumber, node)

        if node.left is None and node.right is None:
            return(currentNodeNumber, None)

        if node.left is not None:
            (currentNodeNumber, result)  = dfsSearch(node.left, currentNodeNumber + 1, targetNodeNumber)
            if result is not None:
                return (currentNodeNumber, result)

        if node.right is not None:
            (currentNodeNumber, result) = dfsSearch(node.right, currentNodeNumber + 1, targetNodeNumber)

            if result is not None:
                return (currentNodeNumber, result)

        #Looks like it wasn't found in this subtree
        return (currentNodeNumber, None)






#Option 2:
# Insert O(log n)       Increment counter `numberOfNodes` on each parent node of the inserted node
# Delete O(log n)       Decrement counter `numberOfNodes`on former parent nodes of the deleted node
# Find O(log n)
# getRandomNode O(log n)


class BinaryTree1:
    def __init__(self):
        self.root = None
    
    def insert(self, value):
        # ...
        # while inserting, incremement "Child count" on each node
        # ...
        pass

    def delete(self, value):
        # ...
        # While deleting, decrement "Child count" on each node
        # ...
        pass


    def getRandomNode(self):


        x = chooseNode(self.root)

        pass

    def chooseNode(self, node):

        #We're at a terminal node and we're choosing it.
        if node.left is None and node.right is None:
            return node

        #Decide whether or not to choose this node with probability 1/(numChildren)
        randNum = random.randInt(0, node.numChildren + 1)

        if randNum == 0:
            return node

        if node.left is not None and node.right is not None:

            #Choose whether to go left or right based with probability based on number of children
            randNum = random.randInt(0, node.numChildren)
            if node.left.numChildren <= randNum:
                return chooseNode(node.left)
            else:
                return chooseNode(node.right)

        if node.left is not None:
            return chooseNode(node.left)
        else:
            return chooseNode(node.right)