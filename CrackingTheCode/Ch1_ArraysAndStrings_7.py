#Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image
#by 90 degrees. Can you do this in place?
#   00 01 02 03     ->      4 3 2 1
#   10 11 12 11     ->      4 3 2 1
#   20 21 22 23     ->      4 3 2 1
#   30 31 32 33     ->      4 3 2 1
def rotateExtraSpace(input, n):

    newArray = [[0 for _ in range(n)] for _ in range(n)] 

    i2 = 0
    j2 = n - 1

    for i1 in range(n):
        for j1 in range(n):
            current = input[i1][j1]
            newArray[i2][j2] = current
            i2 = i2 + 1
        i2 = 0
        j2 = j2 - 1


    return newArray

def rorateInPlace(input, n):
    #Rotate four points in the square at a time, starting with corners.
    
    offset = 0
    numIterations = int(n / 2)
    for _ in range(numIterations):

        for i in range(offset, n - offset - 1):

            topLeft  = input[0 + offset][0 + offset + i]
            topRight = input[0 + offset + i][n - offset - 1]
            botRight = input[n - offset - 1][n - offset - i - 1]
            botLeft  = input[n - offset - i - 1][0 + offset]

            #topRight = topLeft
            input[0 + offset + i][n - offset - 1] = topLeft
            #botRight = topRight
            input[n - offset - 1][n - offset - i - 1] = topRight
            #botLeft = botRight
            input[n - offset - i - 1][0 + offset] = botRight
            #topLeft = botLeft
            input[0 + offset][0 + offset + i] = botLeft


        offset = offset + 1

    return input



#   1 1         ->      2 1
#   2 2         ->      2 1
result = rotateExtraSpace([[1,1],[2,2]], 2)
assert(result == [[2,1],[2,1]])

#   1 1 1       ->      3 2 1
#   2 2 2       ->      3 2 1
#   3 3 3       ->      3 2 1
result = rotateExtraSpace([[1,1,1],[2,2,2],[3,3,3]], 3)
assert(result == [[3,2,1],[3,2,1],[3,2,1]])

#   1 1 1 1     ->      4 3 2 1
#   2 2 2 2     ->      4 3 2 1
#   3 3 3 3     ->      4 3 2 1
#   4 4 4 4     ->      4 3 2 1
result = rotateExtraSpace([[1,1,1,1],[2,2,2,2],[3,3,3,3],[4,4,4,4]], 4)
assert(result == [[4,3,2,1],[4,3,2,1],[4,3,2,1],[4,3,2,1]])


#   1 1         ->      2 1
#   2 2         ->      2 1
result = rorateInPlace([[1,1],[2,2]], 2)
assert(result == [[2,1],[2,1]])

#   1 1 1       ->      3 2 1
#   2 2 2       ->      3 2 1
#   3 3 3       ->      3 2 1
result = rorateInPlace([[1,1,1],[2,2,2],[3,3,3]], 3)
assert(result == [[3,2,1],[3,2,1],[3,2,1]])

#   1 1 1 1     ->      4 3 2 1
#   2 2 2 2     ->      4 3 2 1
#   3 3 3 3     ->      4 3 2 1
#   4 4 4 4     ->      4 3 2 1
result = rorateInPlace([[1,1,1,1],[2,2,2,2],[3,3,3,3],[4,4,4,4]], 4)
assert(result == [[4,3,2,1],[4,3,2,1],[4,3,2,1],[4,3,2,1]])