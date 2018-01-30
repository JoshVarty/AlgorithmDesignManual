# Power Set: Write a method to return all subsets of a set.

def findSubsets(input):

    subsets = findSubsetsWithIndex(input, len(input) - 1)
    #Append empty set at end
    subsets.append([])

    return subsets

def findSubsetsWithIndex(input, highIndex):

    if highIndex == 0:
        return [[input[0]]]
    
    lastItem = input[highIndex]
    subsets = findSubsetsWithIndex(input, highIndex - 1)

    setsWithLastItem = [[lastItem]]
    for i in subsets:
        setsWithLastItem.append(i + [lastItem])
    subsets.extend(setsWithLastItem)

    return subsets

subsets = findSubsets([1])
assert([] in subsets)
assert([1] in subsets)

subsets = findSubsets([1,2])
assert([] in subsets)
assert([1] in subsets)
assert([2] in subsets)
assert([1,2] in subsets)

subsets = findSubsets([1,2,3])
assert([] in subsets)
assert([1] in subsets)
assert([2] in subsets)
assert([3] in subsets)
assert([1,2] in subsets)
assert([1,3] in subsets)
assert([2,3] in subsets)
assert([1,2,3] in subsets)