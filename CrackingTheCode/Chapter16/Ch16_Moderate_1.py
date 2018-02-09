# Number Swapper: Write a function to swap a number in place (that is, without temporary variables).

def swapNumbersCheating(num1, num2):
    return (num2, num1)

def swapNumbers(num1, num2):

    mask = 0b00000001

    for i in range(8):

        bit1 = num1 & mask
        bit2 = num2 & mask

        if bit1 != bit2:
            if bit1 == mask:
                #If the first nums bit is 1, we set it to 0
                num1 = bitwiseNot(mask) & num1
                #Set the second nums bit to 1
                num2 = mask | num2
            else:
                #If the second nums bit is 1, we set it to 0
                num2 = bitwiseNot(mask) & num2
                #Set the first nums bit to 1
                num1 = mask | num1

        mask = mask << 1

    return (num1, num2)

def bitwiseNot(number, nbits=8):
    t = 1 << nbits
    x = t - 1
    return (1 << nbits ) - 1 - number


num1 = 0
num2 = 0
assert((num2, num1) == swapNumbers(num1, num2))

num1 = 1
num2 = 1
(r1, r2) = swapNumbers(num1, num2)
assert(r1 == num2)
assert(r2 == num1)

num1 = 1
num2 = 0
(r1, r2) = swapNumbers(num1, num2)
assert(r1 == num2)
assert(r2 == num1)  


num1 = 123
num2 = 39
(r1, r2) = swapNumbers(num1, num2)
assert(r1 == num2)
assert(r2 == num1)  

num1 = 254
num2 = 250
(r1, r2) = swapNumbers(num1, num2)
assert(r1 == num2)
assert(r2 == num1)  
