#String Rotation: Assume you have a method isSubstring which checks if one word is a substring of another. Given two strings, s1 and s2,
#write code to check if s2 is a rotation of s1 using only one call to isSubstring (eg. "waterbottle" is a rotation of "erbottlewat")

def isRotation(str1, str2):
    if len(str1) != len(str2):
        return False

    doubleString = str1 + str1

    if str2 in doubleString:
        return True
    else:
        return False


assert(isRotation("ab", "ab") == True)
assert(isRotation("ab", "ba") == True)
assert(isRotation("abc", "cab") == True)
assert(isRotation("abc", "cab") == True)
assert(isRotation("abcabc", "bcabca") == True)
assert(isRotation("waterbottle", "erbottlewat") == True)
assert(isRotation("waterbottle", "rbottlewate") == True)
assert(isRotation("josh", "oshj") == True)
assert(isRotation("josh", "josh") == True)
assert(isRotation("waterbottle", "erbottlewat") == True)

assert(isRotation("a", "aa") == False)
assert(isRotation("josh", "aa") == False)
assert(isRotation("josh", "ojsh") == False)
