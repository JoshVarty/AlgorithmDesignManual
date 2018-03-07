# Pond Sizes: You have an integer matrix representing a plot of land, where the value at that location represents the height above sea 
# level. A value of zero indicates water. A pond is a region of water connected vertically, horizontally or diagonally. The size of 
# the pond is the total number of connected water cells. Write a method to compute the sizes of all ponds in the matrix

def getPondSizes(map):
    nRows = len(map)
    nCols = len(map[0])

    visited = [[False for _ in range(nCols)] for _ in range(nRows)] 
    ponds = []

    for i in range(nRows):
        for j in range(nCols):

            if not visited[i][j]:
                if map[i][j] == 0:
                    pondSize = getPondSize(map, visited, i, j, nRows, nCols)
                    ponds.append(pondSize)

                visited[i][j] = True

    return ponds


def getPondSize(map, visited, i, j, nRows, nCols):

    #Need valid index
    if i < 0 or j < 0 or i >= nRows or j >= nCols:
        return 0

    #Only visit ones we haven't seen before
    if visited[i][j] == True:
        return 0

    #If it's not water, just mark it as visited
    if map[i][j] != 0:
        visited[i][j] = True
        return 0

    visited[i][j] = True

    topLeft = getPondSize(map, visited, i - 1, j - 1, nRows, nCols)
    top = getPondSize(map, visited, i - 1, j, nRows, nCols)
    topRight = getPondSize(map, visited, i - 1, j + 1, nRows, nCols)

    left = getPondSize(map, visited, i, j - 1, nRows, nCols)
    right = getPondSize(map, visited, i, j + 1, nRows, nCols)

    botLeft = getPondSize(map, visited, i + 1, j - 1, nRows, nCols)
    bot = getPondSize(map, visited, i + 1, j, nRows, nCols)
    botRight = getPondSize(map, visited, i + 1, j + 1, nRows, nCols)

    return topLeft + top + topRight + left + right + botLeft + bot + botRight + 1


map = [[0,2,1,0],[0,1,0,1],[1,1,0,1],[0,1,0,1]]
result = getPondSizes(map)

assert(2 in result)
assert(4 in result)
assert(1 in result)
