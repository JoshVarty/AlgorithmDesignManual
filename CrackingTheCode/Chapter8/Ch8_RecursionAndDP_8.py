# Permutations with Dupes: Write a method to compute all the permutations of a string whose characters are not necessarily unique. 
# The list of permutations should not have duplicates.

def getPermutations(lookup, prefix, remaining, result):
    if remaining == 0:
        result.append(prefix)
        return

    #To start: We choose which of the characters we'd like at the first index. 
    #Because we're using a map, we give each character one opportunity to fill this role. The same continues for the 2nd, 3rd etc.
    for char, count in lookup.items():
        if count > 0:
            lookup[char] = count - 1
            getPermutations(lookup, prefix + [char], remaining - 1, result)
            lookup[char] = count

def getPermutationsDupes(input):
    result = []
    lookup = {}
 
    #Count all the characters
    for i in input:
        if i not in lookup:
            lookup[i] = 0
        lookup[i] = lookup[i] + 1

    getPermutations(lookup, [], len(input), result)

    return result



#Ensure it still works on non-dupe strings
results = getPermutationsDupes([1])
assert(results == [[1]])

results = getPermutationsDupes([1,2])
assert([1,2] in results)
assert([2,1] in results)

results = getPermutationsDupes([1,2,3])
assert([1,2,3] in results)
assert([1,3,2] in results)
assert([2,1,3] in results)
assert([2,3,1] in results)
assert([3,2,1] in results)
assert([3,1,2] in results)


#Dupes
results = getPermutationsDupes([1,1])
assert(results == [[1,1]])

results = getPermutationsDupes([1,1,2])
assert(len(results) == 3)
assert([1,1,2] in results)
assert([1,2,1] in results)
assert([2,1,1] in results)

results = getPermutationsDupes([1,1,2,3])
assert(len(results) == 12)

results = getPermutationsDupes([1,1,2,3,4])
assert(len(results) == 60)

