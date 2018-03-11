# Rand7 from Rand5: Implement a method rand7() given rand5(). That is, given a method that generates random numbers between 
# 0 and 4 (inclusive), write a method that generates a random number between 0 and 6 (inclusive).

from random import randint

# 0 0x00000000
# 1 0x00000001
# 2 0x00000010
# 3 0x00000011
# 4 0x00000100

#8->   3 0's    2 1's
#7->   3 0's    2 1's
#6->   4 0's    1 1's


#Target
# 0 0x00000000
# 1 0x00000001
# 2 0x00000010
# 3 0x00000011
# 4 0x00000100
# 5 0x00000101
# 6 0x00000110


#8->   4 0's    3 1's
#7->   4 0's    3 1's
#6->   4 0's    3 1's

#My Solution: 
#   1. Generate the numbers 0->3 (00, 01, 10, 11) for the last two bits and the first two bits
#   2. If the number is > 6, loop

#This gives us an even distribution of numbers from 0000 -> 1111


def rand7():

    while True:
        lsb = rand4() 
        msb = rand4() << 2

        result = lsb + msb
        if result <= 6:
            return result

def rand4():
    #I want an even distribution of two bits (00, 01, 10, 11)
    while True:
        currentNumber = rand5()
        if currentNumber != 4:
            return currentNumber


def rand5():
    return (randint(0, 4))

