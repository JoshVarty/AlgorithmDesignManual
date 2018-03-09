# Sum Swap: Given two arrays of integers, find a pair of values (one value from each array) that you can swap to give the 
# two arrays the same sum.
# Example
# Input: {4,1,2,1,1,2} and {3,6,3,3}
# Output: {1, 3}

def sumSwap(input1, input2):

    short = input1
    long = input2
    #We need to keep track of the original order in which the arrays were passed
    #So we can pass back the results in the correct order
    switched = False
    
    if len(input1) > len(input2):
        switched = True
        (short, long) = (long, short)

    #n * log n
    long.sort()
    short.sort()

    shortSum = 0
    longSum = 0

    #n
    for i in short:
        shortSum = shortSum + i
    
    longLookup = {}
    for i in long:
        longLookup[i] = i
        longSum = longSum + i


    for i in short:

        difference = (longSum + i) - (shortSum - i)

        if difference % 2 == 0:
            target = int(difference/ 2)

            if target in longLookup:
                if switched:
                    return (target, i)
                else:
                    return (i, target)

    #Can't be done
    return (None, None)

r1, r2 = sumSwap([4,1,2,1,1,2], [3,6,3,3])
assert(r1 == 1)
assert(r2 == 3)

r1, r2 = sumSwap([3,6,3,3], [4,1,2,1,1,2])
assert(r1 == 3)
assert(r2 == 1)

r1, r2 = sumSwap([1,1,1,2], [1,2,2,2])
assert(r1 == 1)
assert(r2 == 2)

r1, r2 = sumSwap([2,2,1,2], [1,2,1,1])
assert(r1 == 2)
assert(r2 == 1)
