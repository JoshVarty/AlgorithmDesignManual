# Paths with sum: You are given a binary tree in which each node contains an integer values (which might be positive or negative). Design an
# algorithm to count the number of paths that sum to a given value. The path does not need to start or end at the root or a leaf, but it 
# must go downwards (traveling only from parent nodes to children nodes).


def countPaths(root, targetSum):
    if root is None:
        return 0

    pathsFromRoot = countPathsWithSumFromNode(root, targetSum, 0)

    pathsOnLeft = countPaths(root.left, targetSum)
    pathsOnRight = countPaths(root.right, targetSum)

    return pathsFromRoot + pathsOnLeft + pathsOnRight

def countPathsWithSumFromNode(node, targetSum, currentSum):
    if node is None:
        return 0

    currentSum = currentSum + node.data

    totalPaths = 0
    if currentSum == targetSum:
        totalPaths = 1

    leftPaths = countPaths(node.left, targetSum, currentSum)
    rightPaths = countPaths(node.right, targetSum, currentSum)

    totalPaths = totalPaths + leftPaths + rightPaths
    return totalPaths
