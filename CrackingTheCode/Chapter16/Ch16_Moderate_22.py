# Langton's Ant: An ant is sitting on an infinite grid of white and black squares. It initially faces right. At each step, it does the 
# following:
# 1. At a white square, flip the color of the square, turn 90 degrees right (clockwise), and move forward one unit
# 2. At a black square, flip the color of the square, turn 90 degrees left (counter-clockwise), and move forward one unit.
# 
# Write a program to simulated the first K moves that the ant makes and print the final board as a grid.
# Note that you are not provided with the data structure to represent the grid, this is something you must design yourself.
# The only input to your method is K. You should print the final grid and return nothing. The method signature might be something like
# void printKMoves(int K)
 
import random

class DumbGame:


    def printKMoves(self,k):

        grid = Grid(k)
        pos_i = k
        pos_j = k

        facing = 'R'

        for i in range(k):

            isWhite = Grid.grid[pos_i][pos_j]

            if isWhite:
                #Turn right (clockwise)
                if facing == 'R':
                    facing = 'D'
                elif facing == 'D':
                    facing = 'L'
                elif facing == 'L':
                    facing = 'U'
                elif facing == 'U':
                    facing = 'R'
            else:
                #Turn left (counter-clockwise)
                if facing == 'R':
                    facing = 'U'
                elif facing == 'D':
                    facing = 'R'
                elif facing == 'L':
                    facing = 'D'
                elif facing == 'U':
                    facing = 'L'

            #Flip color of square
            Grid.grid[pos_i][pos_j] = not Grid.grid[pos_i][pos_j]
            
            #Move forward
            if facing == 'R':
                pos_j = pos_j + 1
            elif facing == 'D':
                pos_i = pos_i + 1
            elif facing == 'L':
                pos_j = pos_j - 1
            elif facing == 'U':
                pos_i = pos_i = 1


            grid.printSelf()


    def move():
        pass


class Grid:

    def __init__(self, k):

        nRows = 2 * k + 1
        nCols = 2 * k + 1

        #Create random grid of size 2k
        self.grid = [[random.choice([True, False]) for _ in range(nCols)] for _ in range(nRows)] 
        self.nRows = nRows
        self.nCols = nCols


    def printSelf(self):

        for i in range(self.nRows):
            print()
            for j in range(self.nCols):
                print(self.grid[i][j], end=" ")


    