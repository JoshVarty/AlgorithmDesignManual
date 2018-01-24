# BST Sequences: A binary search tree was created by traversing through an array from left to right and inserting each element. Given a binary
# search tree with distinct elements, print all possible arrays that could have led to this tree 



def generatePermutations(nums, lowIdx):

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