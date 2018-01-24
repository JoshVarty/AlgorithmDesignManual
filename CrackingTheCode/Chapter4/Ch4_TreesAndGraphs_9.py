# BST Sequences: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary
# search tree with distinct elements, print all possible arrays that could have led to this tree 

from Graph import *

def generatePermutations(nums, lowIdx):
    """
    Vanilla permutation of a list of elements
    """

    permutations = []
    if lowIdx == len(nums) - 1:
        permutations.append(nums[:])
    else:
        i = lowIdx
        while i < len(nums):

            temp = nums[lowIdx]
            nums[lowIdx] = nums[i]
            nums[i] = temp

            currentPerms = generatePermutations(nums, lowIdx + 1)
            permutations.extend(currentPerms)

            temp = nums[lowIdx]
            nums[lowIdx] = nums[i]
            nums[i] = temp

            i = i + 1

    return permutations

nums = [1,2]
result = generatePermutations(nums, 0)
assert(result[0] == [1,2])
assert(result[1] == [2,1])

nums = [1,2,3]
result = generatePermutations(nums, 0)
assert(len(result) == 6)


def interleavePermutations(nums1, nums2, idx1 = 0, idx2 = 0, prefix = []):

    left = []
    right = []

    permutations = []

    if idx1 >= len(nums1):
        return [prefix + nums2[idx2:]]
    
    if idx2 >= len(nums2):
        return [prefix + nums1[idx1:]]


    prefix.append(nums1[idx1])
    left = interleavePermutations(nums1, nums2, idx1 + 1, idx2, prefix)
    prefix.pop()

    prefix.append(nums2[idx2])
    right = interleavePermutations(nums1, nums2, idx1, idx2 + 1, prefix)
    prefix.pop()

    left.extend(right)
    return left


result = interleavePermutations([1], [2])
assert(len(result) == 2)

result = interleavePermutations([1,2], [3])
assert(len(result) == 3)

result = interleavePermutations([1,2], [3,4])
assert(len(result) == 6)

result = interleavePermutations([1,2,3], [4,5])
assert(len(result) == 10)

result = interleavePermutations([1,2,3], [4,5,6])
assert(len(result) == 20)


def bstSequences(node):

    leftPermutations = [[]]
    rightPermutations = [[]]

    if node.left is None and node.right is None:
        return [[node.data]]

    if node.left is not None:
        leftPermutations = bstSequences(node.left)

    if node.right is not None:
        rightPermutations = bstSequences(node.right)

    permutations = []

    for i in leftPermutations:
        for j in rightPermutations:
            currentPermutations = interleavePermutations(i, j, prefix=[node.data])
            permutations.extend(currentPermutations)
    return permutations


root = Node(2)
root.left = Node(1)
root.right = Node(3)
result = bstSequences(root)
assert(len(result) == 2)
assert(result[0] == [2,1,3])
assert(result[1] == [2,3,1])

root = Node(4)
root.left = Node(2)
root.left.left = Node(1)
root.left.right = Node(3)
root.right = Node(5)
root.right.right = Node(6)
result = bstSequences(root)
assert(len(result) == 20)