# Sub Sort: Given an array of integers, write a method to find indices m and n such that if you sorted the elements m through n, the entire
# array would be sroted. Minimze n - m (that is, find the smallest such sequence).
# Example
# Input 1,2,4,7,10,11,7,12,6,7,16,18,19
# Output (3, 9)

#Josh Note: I think this answer is incorrect. If you sort from (4,9) you'll get a sorted sequence with smaller n-m. 

def subSort(input):

    lowViolationIdx = -1

    #Find low violation
    for i in range(1, len(input)):
        current = input[i]
        prev = input[i - 1]

        if current < prev:
            lowViolationIdx = i
            break

    #If there were no unordered elements, we won't need to sort
    if lowViolationIdx == -1:
        return (None, None)

    lowBound = -1
    
    for i in range(len(input)):
        if input[lowViolationIdx] < input[i]:
            lowBound = i
            break


    highViolationIdx = -1
    #Find high violation
    x = list(reversed(range(len(input) - 1)))
    for i in reversed(range(len(input) - 1)):
        
        current = input[i]
        next = input[i + 1]
        
        if current > next:
            highViolationIdx = i 
            break

    highBound = -1
    for i in reversed(range(len(input))):
        if input[highViolationIdx] > input[i]:
            highBound = i
            break

    return (lowBound, highBound)


l,h = subSort([1,2,4,7,10,11,7,12,6,7,16,18,19])
assert(l == 4)
assert(h == 9)

l,h = subSort([1])
assert(l is None)
assert(h is None)

l,h = subSort([1,2,3])
assert(l is None)
assert(h is None)

