#Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome
#is a word that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need 
#to be limited to just dictionary words.

def isPalindromPermutation(input):
    input = input.replace(" ", "").lower()
    charCount = [0 for _ in range(128)]

    for char in input:
        charVal = ord(char)
        charCount[charVal] = charCount[charVal] + 1


    #if the input is odd, we're allowed one char with an odd count (It can go in the middle)
    allowedOdds = 0
    if len(input) % 2 != 0:
        allowedOdds = 1

    for count in charCount:

        #If the charCount is odd, check if we're still allowed this character
        if count % 2 != 0:
            if allowedOdds <= 0:
                return False
            allowedOdds = allowedOdds - 1

    return True

assert(isPalindromPermutation("Tact Coa") == True)
assert(isPalindromPermutation("acto cat") == True)
assert(isPalindromPermutation("") == True)
assert(isPalindromPermutation("a") == True)
assert(isPalindromPermutation("aab") == True)

assert(isPalindromPermutation("cab") == False)
assert(isPalindromPermutation("ab") == False)
assert(isPalindromPermutation("a  josh") == False)
assert(isPalindromPermutation("varty") == False)
assert(isPalindromPermutation("varty") == False)
