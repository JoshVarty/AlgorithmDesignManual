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









