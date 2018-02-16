# Factorial Zeros: Write an algorithm which computers the number of trailing zeros in n factorial.

#We need to count the number of 10s, 5s and 2s. 
#However:
#   - There are always more 2's than 5's.
#   - 10s are divisible by 5
#   - Some numbers decompose into 5's (25 = 5 * 5, so it should count for two zeros)

#Therefore we can just count the number of numbers divisible by five and decompose them further into multiples of 5.
def numZerosInFactorial(input):

    numZeros = 0
    for i in range(input):

        count = 0
        while i % 5 == 0:
            count = count + 1
            i = i / 5

        numZeros = numZeros + 1

    return numZeros
