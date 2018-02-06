# Given an infinite number of quarters, dimes, nickels and pennies, write code to calculate the number of ways of representing n cents.

def numWaysToMakeChange(target, denominations, index = 0, lookup = None):

    if lookup is None:
        lookup =  [[0  for _ in range(len(denominations))] for _ in range(target + 1)]

    #If we've seen this combination before, just return it.
    if lookup[target][index] > 0:
        return lookup[target][index] 

    if index >= len(denominations) - 1:
        return 1

    coin = denominations[index]
    numWays = 0

    i = 0
    while i * coin <= target:

        targetRemaining = target - (i * coin)
        numWays = numWays + numWaysToMakeChange(targetRemaining, denominations, index + 1, lookup)

        i = i + 1

    lookup[target][index] = numWays
    return numWays
