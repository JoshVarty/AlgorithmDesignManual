# Master Mind: The Game of Master Mind is played as follows: 
# The computer has four slots, and each slot will contain a ball that is red (R), yellow (Y), green (G) or blue (B). For example the computer
# might have RGGB (Slot #1 is red, Slots #2 and #3 are green, Slot #4 is blue)
# 
# You, the user are trying to guess the solution. You might, for example, guess YRBG.
# When you guess the correct color for the correct slow, you get a "hit". If you guess a color that exists but is in the wrong slot, you get
# a "pseudo-hit". Note that a slot that is hit can never count as a pseudo-hit.
# 
# For example, if the actual solution is RGBY and you guess GGRR you have one hit and one pseudo-hit. Write a method that, given a guess
# and a solution, returns the number of hits and pseudo-hits.

def returnClue(solution, guess):

    solution = list(solution.lower())
    guess = list(guess.lower())

    numHit = 0
    numClose = 0

    matchingIndices = []
    #Check matches
    for i in range(len(solution)):
        currentSolution = solution[i]
        currentGuess = guess[i]

        if currentSolution == currentGuess:
            numHit = numHit + 1
            #Overwrite em
            matchingIndices.append(i)

    for i in reversed(matchingIndices):
        del solution[i]
        del guess[i]
    
    for currentGuess in guess:
        if currentGuess in solution:
            numClose = numClose + 1
            solution.remove(currentGuess)

    return (numHit, numClose)


hit, close = returnClue("RGBY", "GGRR")
assert(hit == 1)
assert(close == 1)

hit, close = returnClue("RRRR", "RRRR")
assert(hit == 4)
assert(close == 0)

hit, close = returnClue("RRRR", "BBBB")
assert(hit == 0)
assert(close == 0)

hit, close = returnClue("GRBY", "RBYG")
assert(hit == 0)
assert(close == 4)
