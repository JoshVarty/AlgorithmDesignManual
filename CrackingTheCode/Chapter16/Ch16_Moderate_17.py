# Contiguous Sequence: You are given an array of integer (both positive and negative). Find the contiguous sequence with the largest sum. 
# Return the sum.

def findLargestSum(input):

    maxAtIndex = input[0]
    currentMax = input[0]

    for i in range(1, len(input)):
        currentNum = input[i]
        sum = maxAtIndex + currentNum

        if sum > currentNum:
            maxAtIndex = sum
        else:
            #If the sum is smaller than the current number, then we just want to start over from this number
            maxAtIndex = currentNum

        #If we've increased, keep track of global max
        if maxAtIndex > currentMax:
            currentMax = maxAtIndex

    return currentMax


resul2t = findLargestSum([2,-8,3,-2,4,-10])
