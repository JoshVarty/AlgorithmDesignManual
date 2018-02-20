# Smallest Difference: Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative)
# difference. Return the difference.



def smallestDifference(list1, list2):
    list1.sort()
    list2.sort()

    smallestDiff = 999

    while len(list1) > 0 and len(list2) > 0:

        small = list1
        big = list2
        if big[0] < small[0]:
            (small,big) = (big,small)

        diff = big[0] - small[0]

        if diff < smallestDiff:
            smallestDiff = diff

        #Delete smallest item
        #Alternatively we could just keep track of pointers so we don't pay overhead of array manipulation
        del small[0]

    return smallestDiff


l1 = [1,3,15,11,2]
l2 = [23,127,235,19,8]
result = smallestDifference(l1, l2)
assert(result == 3)