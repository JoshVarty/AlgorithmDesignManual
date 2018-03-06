# Pattern Matching: You are given two strings, pattern and value. The pattern consists of just the letters a and b, describing a pattern
# within a string. For example, the string catcatgocatgo matches the mattern aabab (where cat is a and go is b). It also matthces matches 
# patterns like a, ab and and b.
# Write a method to determine if value matches pattern.


def matchesPattern(input, pattern):

    if len(input) == 0 or len(pattern) == 0:
        return False

    mainChar = pattern[0]
    altChar = 'a'
    if mainChar == 'a':
        altChar = 'b'

    size = len(input)

    countOfMain = countChar(input, mainChar)
    countOfAlt = len(pattern) - countOfMain
    firstAlt = pattern.index(altChar)
    maxMainSize = size / countOfMain

    for i in range(maxMainSize + 1):

        remainingLength = size - mainSize * countOfMain
        if countOfAlt == 0 or remainingLength % countOfAlt == 0:
            altIndex = firstAlt * mainSize
            altSize = remainingLength / countOfAlt
            if countOfAlt == 0:
                altSize = 0

            if matches(pattern, input, mainSize, altSize, altIndex):
                return True


    return False



def matches(pattern, value, mainSize, altSize, firstAlt):
    pass

def countChar(input, char):
    count = 0
    for i in input:
        if i == char:
            count = count + 1

    return count
