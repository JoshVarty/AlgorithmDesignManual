# BST Sequences: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary
# search tree with distinct elements, print all possible arrays that could have led to this tree 


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


def permutateInterleavings(nums1, nums2, idx1 = 0, idx2 = 0, prefix = []):

    left = []
    right = []

    permutations = []

    if idx1 >= len(nums1):
        return [prefix + nums2[idx2:]]
    
    if idx2 >= len(nums2):
        return [prefix + nums1[idx1:]]

    leftPrefix = prefix + [nums1[idx1]]
    left = permutateInterleavings(nums1, nums2, idx1 + 1, idx2, leftPrefix)

    rightPrefix = prefix + [nums2[idx2]]
    right = permutateInterleavings(nums1, nums2, idx1, idx2 + 1, rightPrefix)

    left.extend(right)
    return left



result = permutateInterleavings([1], [2])
assert(len(result) == 2)

result = permutateInterleavings([1,2], [3])
assert(len(result) == 3)

result = permutateInterleavings([1,2], [3,4])
assert(len(result) == 6)

result = permutateInterleavings([1,2,3], [4,5])
assert(len(result) == 10)

result = permutateInterleavings([1,2,3], [4,5,6])
assert(len(result) == 20)