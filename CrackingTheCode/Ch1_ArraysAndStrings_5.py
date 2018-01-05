#One Away: There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character.
#Given two strings, write a function to check if they are one edit (or zero edits) away.

import math

def oneAway(str1, str2):

    if len(str1) == len(str2):
        return oneReplace(str1, str2)
    elif len(str1) + 1 == len(str2):
        return oneRemove(str2, str1)
    elif len(str1) == len(str2) + 1:
        return oneRemove(str1, str2)
    else:
        return False

def oneReplace(str1, str2):
    numDifferences = 0

    for idx in range(len(str1)):
        if str1[idx] != str2[idx]:
            numDifferences = numDifferences + 1
            if numDifferences > 1:
                return False

    return True

def oneRemove(long, short):

    numDifferences = 0
    index1 = 0
    index2 = 0

    while index1 < len(long) and index2 < len(short):
        if long[index1] != short[index2]:
            numDifferences = numDifferences + 1
            index1 = index1 + 1
            if numDifferences > 1:
                return False
        else:
            index1 = index1 + 1
            index2 = index2 + 1

    return True

assert(oneAway("", "") == True)
assert(oneAway("j", "") == True)
assert(oneAway("", "j") == True)
assert(oneAway("josh", "josh") == True)
assert(oneAway("josh", "posh") == True)
assert(oneAway("pale", "ple") == True)
assert(oneAway("pales", "pale") == True)
assert(oneAway("pale", "bale") == True)

assert(oneAway("", "ab") == False)
assert(oneAway("", "abc") == False)
assert(oneAway("pale", "bake") == False)
assert(oneAway("josh", "jasp") == False)
