# Count of 2s: Write a method to count the number of 2s that appear in all the numbers between 0 and n (inclusive).

# EXAMPLE
# Input: 25
# Output: 9 (2, 12, 20, 21, 22, 23, 24 and 25)

#25-(20-1) = 6
#(20 - 1)

import math

def count2sInRangeAtDigit(number, digit):

    powerOf10 = int(math.pow(10, digit))
    nextPowerOf10 = int(math.pow(10, digit + 1) )
    right = number % powerOf10

    roundDown = number - number % nextPowerOf10
    roundUp = roundDown + nextPowerOf10

    digit = int((number / powerOf10)) % 10
    if digit < 2:
        return roundDown / 10
    elif digit > 2:
        return roundUp / 10
    else:
        return roundDown / 10 + right + 1

def count2sInRange(number):
    count = 0
    for digit in range(len(str(number))):
        count = count2sInRangeAtDigit(number, digit)

    return count

count2sInRange(25)
count2sInRange(61523)