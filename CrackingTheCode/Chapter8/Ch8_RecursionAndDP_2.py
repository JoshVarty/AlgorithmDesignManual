# Robot in a Grid: Imagine a robot sitting on the upper left corner of a grid with r rows and c columns. The robot can only move in two
# directions, right and down, but certain cells are "off limits" such that the robot cannot step on them. Design an algorithm to find a 
#  path for the robot from the top left to the bottom right

def getPath(grid):

    path = []

    rows = len(grid)
    cols = len(grid[0])
    visited = [[False for i in range(len(rows))] for j in range(cols)]

    foundPath = tryFindPath(grid, 0, 0, visited, path)

def findPath(grid, i, j, visited, path):

    if i < 0 or j < 0 or grid[i][j] == False:
        return 

    #We've already been here
    if visited[i][j] == True:
        return False

    visited[i][j] = True
    path.append((i,j))

    atEnd = False
    if i == len(grid) - 1 and j == len(grid[0]) - 1:
        atEnd = True

    if atEnd:
        return True

    rightPathWorks = findPath(grid, i, j + 1, visited, path)
    if rightPathWorks:
        return True

    downPathWorks = findPath(grid, i, j + 1, visited, path)
    if downPathWorks:
        return True

    #Remove this node because this path didn't work.
    path.pop()
    return False










