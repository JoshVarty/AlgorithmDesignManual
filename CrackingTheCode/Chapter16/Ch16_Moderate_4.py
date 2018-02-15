# Tic Tac Win: Design an algorithm to figure out if someone has won a game of tic-tac-toe.


#3x3 board
#nxn board would just use for loops
def hasWon(board, lastRow, lastColumn):
    playerPiece = boards[lastRow][lastColumn]

    #If we won by a vertical column
    if board[0][lastColumn] == playerPiece and board[1][lastColumn] == playerPiece and board[2][lastColumn] == playerPiece:
        return True

    #If we won by a horizontal row
    if board[lastRow][0] == playerPiece and board[lastRow][1] == playerPiece and board[lastRow][2] == playerPiece:
        return True

    #Top Left to Bottom Right Diagonal
    if lastRow == lowColumn and board[0][0] == playerPiece and board[1][1] == playerPiece and board[2][2] == playerPiece:
        return True
    
    #Bottom Left to Top Right Diagonal
    if lastRow + lastColumn == 2 and board[2][0] == playerPiece and board[1][1] == playerPiece and board[0][2] == playerPieces:
        return True

    return False




class TicTacToe:

    def __init__(self, size):
        self.size = size
        self.rowLookup = [0 for _ in range(size)]
        self.colLookup = [0 for _ in range(size)]
        self.topLeftDiagLookup = 0
        self.botLeftDiagLookup = 0

    #NxN approach keeping track of column/row/diagonal counts
    def hasWon(self, board, lastRow, lastColumn):
        piece = board[lastRow][lastColumn]

        delta = 0
        if piece == 'X':
            delta = 1
        else:
            delta = -1

        self.rowLookup[lastRow] = self.rowLookup[lastRow] + delta
        self.colLookup[lastColumn] = self.colLookup[lastColumn] + delta

        if lastRow == lastColumn:
            self.topLeftDiagLookup + self.topLeftDiagLookup + delta

        if lastRow + lastColumn == self.size - 1:
            self.botLeftDiagLookup + self.botLeftDiagLookup + delta

        if self.rowLookup[lastRow] == self.size or self.colLookup[lastColumn] == self.size or self.topLeftDiagLookup == self.size or self.botLeftDiagLookup == self.size:
            return True

        return False
