# Permutation without Dups: Write a method to compute all permutations of a string of unique characters

def swap(input, idx1, idx2):
    temp = input[idx1]
    input[idx1] = input[idx2]
    input[idx2] = temp

def getPermutations(input, currentIndex = 0):

    if currentIndex == len(input) - 1:
        return [input[:]]

    allPerms = []
    for i in range(currentIndex, len(input)):
        swap(input, i, currentIndex)
        perms = getPermutations(input, currentIndex + 1)
        allPerms.extend(perms)
        #Swap back
        swap(input, i, currentIndex)


    return allPerms

results = getPermutations([1])
assert(results == [[1]])

results = getPermutations([1,2])
assert([1,2] in results)
assert([2,1] in results)

results = getPermutations([1,2,3])
assert([1,2,3] in results)
assert([1,3,2] in results)
assert([2,1,3] in results)
assert([2,3,1] in results)
assert([3,2,1] in results)
assert([3,1,2] in results)
