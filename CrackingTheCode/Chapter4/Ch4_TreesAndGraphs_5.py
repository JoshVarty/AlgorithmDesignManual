# Validate BST: Implement a function to check if a binary tree is a binary search tree.

from Graph import *

def isValidTree(node, minVal = -999999, maxVal = 999999):

    if node.left is None and node.right is None:
        return True

    isValidLeft = True
    isValidRight = True
    if node.left is not None:
        if node.left.data > min(node.data, maxVal) or node.left.data < minVal:
            return False

        isValidLeft = isValidTree(node.left, minVal, min(node.data, maxVal))

    if node.right is not None:
        if node.right.data < max(node.data, minVal) or node.right.data > maxVal:
            return False

        isValidRight = isValidTree(node.right, max(node.data, minVal), maxVal)

    return isValidLeft & isValidRight


root = Node(4)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.left = Node(2)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.right = Node(5)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.left = Node(2)
root.right = Node(5)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.left = Node(1)
root.left.right = Node(2)
root.left.right.right = Node(3) #unbalanced
root.right = Node(7)
root.right.left = Node(6)
root.right.right = Node(8)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.left = Node(2)
root.left.right = Node(3)
root.right = Node(7)
root.right.left = Node(6)
root.right.left.left = Node(5)
root.right.right = Node(8)
result = isValidTree(root)
assert(result == True)

root = Node(4)
root.left = Node(1)
root.left.right = Node(2)
result = isValidTree(root)
assert(result == True)


#Invalid trees
root = Node(4)
root.left = Node(5)
result = isValidTree(root)
assert(result == False)

root = Node(4)
root.right = Node(2)
result = isValidTree(root)
assert(result == False)

root = Node(4)
root.left = Node(1)
root.left.right = Node(5)
result = isValidTree(root)
assert(result == False)

root = Node(4)
root.left = Node(1)
root.left.right = Node(2)
root.left.right.right = Node(5)
result = isValidTree(root)
assert(result == False)

root = Node(4)
root.left = Node(2)
root.left.right = Node(3)
root.left.right.left = Node(1)
result = isValidTree(root)
assert(result == False)
