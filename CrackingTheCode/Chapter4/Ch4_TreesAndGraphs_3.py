# List of depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth 
# (e.g. if you have a tree with depth D, you'll have D linked lists)

from node import *

def listOfDepths(root):

    lists = []
    #Queue up the root next
    nextLevel = [root]
    currentLevel = []
    

    while len(nextLevel) > 0:

        (currentLevel, nextLevel) = (nextLevel, currentLevel)
    
        current = currentLevel[0]
        del currentLevel[0]
        #Create the linked list head
        head = Node(current.data)
        currentNode = head

        while len(currentLevel) > 0:
            current = currentLevel[0]
            del currentLevel[0]

            currentNode.next = Node(current.data)
            currentNode = currentNode.next

            if current.left is not None:
                nextLevel.add(current.left)

            if current.right is not None:
                nextLevel.add(current.right)

        lists.append(head)

    return lists