# Diving Board: You are building a diving board by placing a bunch of planks of wood end-toend. There are two types of planks, one of 
# length shorter and one of length longer. You must use exactly K planks of wood. Write a method to generate all possible lengths for the 
# diving board.

def numLengthsOfBoard(shorter, longer, k):

    numLong = k
    numShort = 0

    ways = {}

    while numShort < k + 1:
        size = numLong * longer + numShort * short
        #Ignores multiple ways of making the same length
        ways[size] = True

        numShort = numShort + 1
        numLong = numLong - 1

    return len(ways)


