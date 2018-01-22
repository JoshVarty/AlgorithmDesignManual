# Successor: Write an algorithm to find the "next" node (ie. in-order successor) of a given node in a binary search tree. 
# You may assume each node has a link to its parent.

from Graph import *


def findNext(node, target, nextClosest = None):
    
    if nextClosest is None:
        nextClosest = Node(99999)

    if node.data > target and node.data < nextClosest.data:
        nextClosest = node

    if node.data > target:
        #We want to go left
        if node.left is not None:
            return findNext(node.left, target, nextClosest)
        else:
            return nextClosest
    elif node.data <= target:
        #We want to go right
        if node.right is not None:
            return findNext(node.right, target, nextClosest)
        else:
            return nextClosest


root = Node(4)
result = findNext(root, 3)
assert(result == root)

root = Node(4)
root.left = Node(2)
result = findNext(root, 1)
assert(result == root.left)

root = Node(4)
root.right = Node(5)
result = findNext(root, 4)
assert(result == root.right)

root = Node(4)
root.right = Node(6)
root.right.left = Node(5)
root.right.right = Node(7)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
result = findNext(root, 1)
assert(result == root.left)

root = Node(4)
root.right = Node(6)
root.right.left = Node(5)
root.right.right = Node(7)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
result = findNext(root, 2)
assert(result == root.left.right)

root = Node(4)
root.right = Node(6)
root.right.left = Node(5)
root.right.right = Node(7)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
result = findNext(root, 3)
assert(result == root)

root = Node(4)
root.right = Node(6)
root.right.left = Node(5)
root.right.right = Node(7)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
result = findNext(root, 6)
assert(result == root.right.right)
