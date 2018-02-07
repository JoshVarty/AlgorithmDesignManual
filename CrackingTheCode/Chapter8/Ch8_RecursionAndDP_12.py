# Eight Queens: Write an algorithm to print all of the ways of arranging eight queens on an 8x8 chessboard so that none of them share the 
# same row, column or diagonal.

def eightQueens(row, columns, gridSize, results):

    #We've gotten to the bottom of the board and all the queens fit.
    #Add it to the results and return
    if row == gridSize:
        results.append(columns[:])
    else:
        #Try a queen in each column position for this row
        for i in range(gridSize):
            if isValid(columns, row, col):
                columns[row] = i    #place queen
                placeQueens(row + 1, columns, gridSize, results)


def checkValid(colums, row1, row2):

    for row2 in range(row1):
        column2 = columns[row2]

        #Same column
        if column1 == column2:
            return False


        #Diagonal
        columnDistance = abs(column1 - column2)
        if rowDistance == row1 - row2:
            return False


    return False