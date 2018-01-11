#Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

def isPermutation1(str1, str2):
    if len(str1) != len(str2):
        return False

    sorted1 = sorted(str1)
    sorted2 = sorted(str2)

    return sorted1 == sorted2


def isPermutation2(str1, str2):
    
    if len(str1) != len(str2):
        return False

    seen_chars = [0 for _ in range(128)]

    for char in str1:
        charVal = ord(char)
        seen_chars[charVal] = seen_chars[charVal] + 1

    for char in str2:
        charVal = ord(char)
        seen_chars[charVal] = seen_chars[charVal] - 1

    for count in seen_chars:
        if count != 0:
            return False

    return True

def isPermutation3(str1, str2):
    if len(str1) != len(str2):
        return False

    seen_chars = [0 for _ in range(128)]

    for char in str1:
        charVal = ord(char)
        seen_chars[charVal] = seen_chars[charVal] + 1

    for char in str2:
        charVal = ord(char)
        if seen_chars[charVal] == 0:
            return False;
        seen_chars[charVal] = seen_chars[charVal] - 1
 
    return True

assert(isPermutation1("", "") == True)
assert(isPermutation1("josh", "josh") == True)
assert(isPermutation1("josh", "oshj") == True)
assert(isPermutation1("josh", "shoj") == True)
assert(isPermutation1("josh", "joshj") == False)
assert(isPermutation1("josh", "josj") == False)
assert(isPermutation1("josh", "") == False)

assert(isPermutation2("", "") == True)
assert(isPermutation2("josh", "josh") == True)
assert(isPermutation2("josh", "oshj") == True)
assert(isPermutation2("josh", "shoj") == True)
assert(isPermutation2("josh", "joshj") == False)
assert(isPermutation2("josh", "josj") == False)
assert(isPermutation2("josh", "") == False)

assert(isPermutation3("", "") == True)
assert(isPermutation3("josh", "josh") == True)
assert(isPermutation3("josh", "oshj") == True)
assert(isPermutation3("josh", "shoj") == True)
assert(isPermutation3("josh", "joshj") == False)
assert(isPermutation3("josh", "josj") == False)
assert(isPermutation3("josh", "") == False)