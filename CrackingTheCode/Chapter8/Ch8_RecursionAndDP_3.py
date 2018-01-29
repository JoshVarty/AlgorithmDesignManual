# Magic Index: A magic index in an array A[1..n-1] is defined to be an index such that A[i] = i. Given a sorted array of distinct integers, 
# write a method to find a magic index, if one exists, in A. 
# FOLLOW UP
# What if the values are not distinct

def magicIndex(array):
    return findMagicIndex(array, 0, len(array) - 1)

def findMagicIndex(array, low, high):

    if low > high:
        return None

    midPoint = int((high + low) / 2)

    if array[midPoint] == midPoint:
        return midPoint

    if array[midPoint] > midPoint:
        #Search left
        magicIndex = findMagicIndex(array, low, midPoint - 1)
        return magicIndex
    else:
        #Search right
        magicIndex = findMagicIndex(array, midPoint + 1, high)
        return magicIndex

result = magicIndex([0])
assert(result == 0)

result = magicIndex([-1,1])
assert(result == 1)

result = magicIndex([-1,0,2])
assert(result == 2)

result = magicIndex([-1,0,1,2,4,9,16])
assert(result == 4)

result = magicIndex([1])
assert(result == None)

result = magicIndex([-1,2])
assert(result == None)

result = magicIndex([-1,0,3])
assert(result == None)

result = magicIndex([-1,0,1,2,5,9,16])
assert(result == None)

