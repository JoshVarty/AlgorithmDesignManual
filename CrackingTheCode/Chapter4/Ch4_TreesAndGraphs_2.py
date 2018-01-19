# Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to
# create a binary search tree with minimal height.

from Graph import Node
from Graph import dfs


def makeBinarySearchTree(input, leftIdx = None, rightIdx = None):
    if leftIdx is None or rightIdx is None:
        leftIdx = 0
        rightIdx = len(input) - 1

    #We're at a terminal node for our graph
    if leftIdx == rightIdx:
        return Node(input[leftIdx])

    middleIdx = int((leftIdx + rightIdx) / 2)
    newNode = Node(input[middleIdx])

    if leftIdx <= middleIdx - 1:
        leftNode = makeBinarySearchTree(input, leftIdx, middleIdx - 1)
        newNode.left = leftNode
    if rightIdx >= middleIdx + 1:
        rightNode = makeBinarySearchTree(input, middleIdx + 1, rightIdx)
        newNode.right = rightNode

    return newNode

input = [1]
root = makeBinarySearchTree(input)
assert(root.data == 1)
assert(dfs(root) == input)

input = [1,2]
root = makeBinarySearchTree(input)
assert(root.data == 1)
assert(dfs(root) == input)

input = [1,2,3]
root = makeBinarySearchTree(input)
assert(root.data == 2)
assert(dfs(root) == input)

input = [1,2,3,4,5,6,7]
root = makeBinarySearchTree(input)
assert(root.data == 4)
x = dfs(root)
assert(dfs(root) == input)

input = [1,2,3,4,5,6]
root = makeBinarySearchTree(input)
assert(root.data == 3)
assert(dfs(root) == input)

