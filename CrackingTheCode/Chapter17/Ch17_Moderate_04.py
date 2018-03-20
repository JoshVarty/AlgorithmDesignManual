# Missing Number: An array A contains all the integers from 0 to n, except for one number which is missing. In this problem, we cannot access
# an entire integer in A with a single operation. The elements of A are represented in binary and the only operation we can use is 
# "fetch the jth bit of A[i]", which takes constant time. Write code to find the missing integer. Can you do it in O(n) time?


def missingNumber(numbers, n):
 
    #Just going to work with 32 bit numbers
    numBits = 32

    placeholder = 0
    for i in range(n + 1):

        #XOR the bits and store in the placeholder
        for j in range(numBits):
            x = getBit(i, j)
            y = getBit(placeholder, j)
            result = x ^ y
            placeholder = setBit(placeholder, j, result)

    for number in numbers:

        #XOR the bits and store in the placeholder
        for j in range(numBits):
            x = getBit(number, j)
            y = getBit(placeholder, j)
            result = x ^ y
            placeholder = setBit(placeholder, j, result)

    #Now placeholder will contain only the bits of the missing number
    #eg. ([1,3], 3]) -> 1 ^ 2 ^ 3 ^ 1 ^ 3 = 2   
    return placeholder


def setBit(number, pos, bit):
    mask = 1 << pos
    number = number & ~mask
    if bit == 1:
        number = number | mask
    return number

def getBit(number, pos):
    mask = 1 << pos
    result = number & mask
    result = result >> pos

    return result


result = missingNumber([0,1,3], 3)
assert(result == 2)
