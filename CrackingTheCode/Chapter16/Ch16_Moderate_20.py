# T9: On old cell phones, users typed on a numeric keypad and the phone would provide a list of words that matched these numbers. Each digit 
# mapped to a set of 0-4 letters. Implement an algorithm to return a list of matching words, given a sequence of digits. You are provided
# a list of valid words (provided in any data structure you'd like). The mapping is shown in the diagram below:

# 1 -> None
# 2 -> abc
# 3 -> def
# 4 -> ghi
# 5 -> jkl
# 6 -> mno
# 7 -> pqrs
# 8 -> tuv
# 9 -> wxyz

# Example
# Input:    8733
# Output:   tree, used

def generateWords(input, charMap):
    words = getValidWords(input, 0, "", charMap)
    return words


def getValidWords(input, index, prefix, charMap):

    if index >= len(input):
        return []

    words = []
    chars = charMap[input[index]]

    for char in chars:
        newPrefix = prefix + char

        if isValidWord(newPrefix):
            words.append(newPrefix)

        if isValidPrefix(newPrefix):
            validWords = getValidWords(input, index + 1, newPrefix, charMap)
            words.extend(validWords)

    return words

def isValidPrefix(prefix):
    #A trie will tell us whether the prefix is valid
    pass

def isValidWord(prefix):
    #A trie will tell us if this prefix maps to a completed word
    pass

