#Add without plus: Write a function that adds two numbers. You should not use + or any arithmetic operators.

#             000011
#           + 000010

# sum   =     000001
# carry =     000100

# sum   =     000101
# carry =     000000

def add(a,b):

    carry = 0
    while b != 0:

        #Add the whole number at once
        sum = a ^ b
        #Get all the carry bits at once
        carry = (a & b) << 1

        a = sum
        b = carry

    return a


x = add(3,2)
