# Triple Step: A child is running up a staircase with n steps and can either hop 1 step, 2 steps or 3 steps at a time. Implement a method 
# to count how many possible ways the child can run up the stairs.


def countWays(numSteps):

    lookup = [0 for _ in range(numSteps + 1)]
    lookup[0] = 1

    for i in range(1, numSteps + 1):

        threeBackIdx = i - 3
        twoBackIdx = i - 2
        oneBackIdx = i - 1

        threeBack = 0
        twoBack = 0
        oneBack = 0

        if threeBackIdx >= 0:
            threeBack = lookup[threeBackIdx] 

        if twoBackIdx >= 0:
            twoBack = lookup[twoBackIdx]

        if oneBackIdx >= 0:
            oneBack = lookup[oneBackIdx] 

        current = threeBack + twoBack + oneBack 
        lookup[i] = current

    return lookup[numSteps]

result = countWays(1)
assert(result == 1)

result = countWays(2)
assert(result == 2)

result = countWays(3)
assert(result == 4)

result = countWays(4)
assert(result == 7)

result = countWays(5)
assert(result == 7 + 4 + 2)


#Using memoization instead
def countWaysMemo(numSteps, lookup = []):

    if numSteps < 0:
        return 0

    if len(lookup) == 0:
        lookup = [-1 for _ in range(numSteps + 1)]
        lookup[0] = 1

    if lookup[numSteps] != -1:
        return lookup[numSteps]

    numWays = countWaysMemo(numSteps - 1, lookup) + countWaysMemo(numSteps - 2, lookup) +  countWaysMemo(numSteps - 3, lookup) 
    lookup[numSteps] = numWays
    return numWays

result = countWaysMemo(1)
assert(result == 1)

result = countWaysMemo(2)
assert(result == 2)

result = countWaysMemo(3)
assert(result == 4)

result = countWaysMemo(4)
assert(result == 7)

result = countWaysMemo(5)
assert(result == 7 + 4 + 2)


def countWaysConstantSpace(numSteps):

    threeBack = 0
    twoBack = 0
    oneBack = 1

    current = 0

    for i in range(numSteps):

        current = threeBack + twoBack + oneBack

        (threeBack, twoBack, oneBack) = (twoBack, oneBack, current)


    return current


result = countWaysConstantSpace(1)
assert(result == 1)

result = countWaysConstantSpace(2)
assert(result == 2)

result = countWaysConstantSpace(3)
assert(result == 4)

result = countWaysConstantSpace(4)
assert(result == 7)

result = countWaysConstantSpace(5)
assert(result == 7 + 4 + 2)