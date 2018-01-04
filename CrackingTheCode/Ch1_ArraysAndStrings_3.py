#URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional aharacters, and that you are given the "true" length of the string.
#Implement in place.
#EXAMPLE
#Input:     "My John Smith    ", 13
#Output:    "Mr%20John%20Smith"


def Urlify(inputArray):
    inputArray = list(inputArray)
    length = len(inputArray)

    lastChar = -1

    #Find last char
    for idx in reversed(range(len(inputArray))):
        if inputArray[idx] != ' ':
            lastChar = idx
            break

    idx = len(inputArray) - 1
    while lastChar >= 0:
        charToMove = inputArray[lastChar]

        if charToMove == ' ':
            inputArray[idx] = '0'
            inputArray[idx - 1] = '2'
            inputArray[idx - 2] = '%'
            idx = idx - 3;
        else:
            inputArray[idx] = charToMove
            idx = idx - 1

        lastChar = lastChar - 1

    result = ''.join(inputArray) 
    return result

assert(Urlify("My John Smith    ") == "My%20John%20Smith")
assert(Urlify("My Josh  ") == "My%20Josh")



