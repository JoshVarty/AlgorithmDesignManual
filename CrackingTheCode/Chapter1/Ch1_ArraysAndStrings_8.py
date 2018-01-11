#Zero Matrix: Write an algorithm such that if an element in an NxN matrix is 0, its entire row and column are set to 0

def zeroMatrix(input, n):
    rowsToZero = [False for _ in range(n)]
    colsToZero = [False for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if input[i][j] == 0:
                rowsToZero[i] = True
                colsToZero[j] = True

    for idx in range(len(rowsToZero)):
        shouldZero = rowsToZero[idx]
        if shouldZero:
            for j in range(n):
                input[idx][j] = 0

    for idx in range(len(colsToZero)):
        shouldZero = colsToZero[idx]
        if shouldZero:
            for i in range(n):
                input[i][idx] = 0
    return input






#   1 1         ->      1 0
#   2 0         ->      0 0
result = zeroMatrix([[1,1],[2,0]], 2)
assert(result == [[1,0],[0,0]])

#   1 1 0       ->      0 0 0
#   2 2 2       ->      0 2 0
#   0 3 3       ->      0 0 0
result = zeroMatrix([[1,1,0],[2,2,2],[0,3,3]], 3)
assert(result == [[0,0,0],[0,2,0],[0,0,0]])

#   1 1 1 1     ->      1 1 0 1
#   2 2 0 2     ->      0 0 0 0
#   3 3 3 3     ->      3 3 0 3
#   4 4 0 4     ->      0 0 0 0
result = zeroMatrix([[1,1,1,1],[2,2,0,2],[3,3,3,3],[4,4,0,4]], 4)
assert(result == [[1,1,0,1],[0,0,0,0],[3,3,0,3],[0,0,0,0]])