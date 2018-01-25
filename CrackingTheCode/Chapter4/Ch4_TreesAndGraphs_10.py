# Check Subtree: T1 and T2 are two very large binary trees, with T1 much bigger than T2. Create an algorithm to determine if T2 is a subtree
# of T1.
# 
# A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree
# at node n, the two trees would be identical 

#Josh: It sounds like they don't mean reference equality here.

from Graph import *

def isSubtree(root1, root2):
    if root1 is None or root2 is None:
        return False

    list1 = dfsToListWithNoneNodes(root1)
    list2 = dfsToListWithNoneNodes(root2)

    #Can't be a subtree if its bigger than the first tree
    if len(list2) > len(list1):
        return False

    #Check if the second list is contained within the first
    idx1 = 0
    while idx1 < len(list1):
        idx2 = 0
        while idx2 < len(list2) and list1[idx1] == list2[idx2]:
            idx1 = idx1 + 1
            idx2 = idx2 + 1

        if idx2 == len(list2):
            return True

        idx1 = idx1 + 1
        
    return False


def dfsToListWithNoneNodes(node):

    results = [node.data]

    if node.left is None:
        results.append(None)
    else:
        leftResults = dfsToListWithNoneNodes(node.left)
        results.extend(leftResults)

    if node.right is None:
        results.append(None)
    else:
        rightResults = dfsToListWithNoneNodes(node.right)
        results.extend(rightResults)

    return results



root1 = Node(4)
root2  = Node(4)
result = isSubtree(root1, root2)
assert(result == True)

root1 = Node(4)
root2  = None
result = isSubtree(root1, root2)
assert(result == False)

root1 = Node(4)
root2  = Node(5)
result = isSubtree(root1, root2)
assert(result == False)

root1 = Node(4)
root1.left = Node(1)
root1.left.right = Node(2)
root1.left.right.right = Node(3) #unbalanced
root1.right = Node(7)
root1.right.left = Node(6)
root1.right.right = Node(8)
root2  = Node(3)
result = isSubtree(root1, root2)
assert(result == True)

root1 = Node(4)
root1.left = Node(1)
root1.left.right = Node(2)
root1.left.right.right = Node(3) #unbalanced
root1.right = Node(7)
root1.right.left = Node(6)
root1.right.right = Node(8)
root2 = Node(4)
root2.left = Node(1)
root2.left.right = Node(2)
root2.left.right.right = Node(3) #unbalanced
root2.right = Node(7)
root2.right.left = Node(6)
root2.right.right = Node(8)
result = isSubtree(root1, root2)
assert(result == True)

root1 = Node(4)
root1.left = Node(1)
root1.left.right = Node(2)
root1.left.right.right = Node(3) #unbalanced
root1.right = Node(7)
root1.right.left = Node(6)
root1.right.right = Node(8)
root2 = Node(4)
root2.left = Node(1)
root2.left.right = Node(2)
root2.left.right.right = Node(3) #unbalanced
root2.right = Node(7)
root2.right.left = Node(6)
result = isSubtree(root1, root2)
assert(result == False)


    