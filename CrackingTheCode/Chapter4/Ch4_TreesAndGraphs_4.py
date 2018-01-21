# Check Balanced: Implement a function to check if a binary tree is balanced. For the purpose of this question, a balanced tree is defined
# to be a tree such that the height of the two subtrees of any node never differs by more than one.

from Graph import *

def isTreeBalanced(node):
    
    if node.left is None and node.right is None:
        return (0, True)

    leftHeight = 0
    rightHeight = 0
    rightBalanced = True
    leftBalanced = True
    balanced = True

    if node.left is not None:
        (leftHeight, leftBalanced) = isTreeBalanced(node.left)
        leftHeight = leftHeight + 1
    if node.right is not None:
        (rightHeight, rightBalanced) = isTreeBalanced(node.right)
        rightHeight = rightHeight + 1

    if not leftBalanced or not rightBalanced or (abs(leftHeight - rightHeight) > 1):
        balanced = False

    maxHeight = max(leftHeight, rightHeight)
    return (maxHeight, balanced)


root = Node(4)
(height, result) = isTreeBalanced(root)
assert(result == True)
assert(height == 0)

root = Node(4)
root.right = Node(5)
(height, result) = isTreeBalanced(root)
assert(result == True)
assert(height == 1)

root = Node(4)
root.left = Node(2)
(height, result) = isTreeBalanced(root)
assert(result == True)
assert(height == 1)

root = Node(4)
root.left = Node(2)
root.left.right = Node(3)
root.right = Node(7)
root.right.left = Node(6)
root.right.left.left = Node(5)
root.right.right = Node(8)
(height, result) = isTreeBalanced(root)
assert(result == True) 
assert(height == 3)


root = Node(1)
root.right = Node(2)
root.right.right = Node(3)
(height, result) = isTreeBalanced(root)
assert(result == False) 
assert(height == 2)


root = Node(4)
root.left = Node(1)
root.left.right = Node(2)
root.left.right.right = Node(3) #unbalanced
root.right = Node(7)
root.right.left = Node(6)
root.right.right = Node(8)
(height, result) = isTreeBalanced(root)
assert(result == False) 
assert(height == 3)
