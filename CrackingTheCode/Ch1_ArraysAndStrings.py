
#Is Unique
#Implement an algorithm to determine if a string has all unique character. What if you cannot use additional data structures?

def allUniqeCharacters_set(input):
    unique_chars = set()
    for char in input:
        unique_chars.add(char)

    return len(unique_chars) == len(input)

def allUniqeCharacters_no_set(input):
    sorted_input = sorted(input)

    for idx in range(len(sorted_input) - 1):
        current = sorted_input[idx]
        next = sorted_input[idx + 1]
        if current == next:
            return False

    return True

def allUniqeCharacters_no_set2(input):

    seen_char = [False for _ in range(128)]

    for char in input:
        charVal = ord(char)
        if seen_char[charVal]:
            return False

        seen_char[charVal] = True

    return True




assert(allUniqeCharacters_set("") == True)
assert(allUniqeCharacters_set("josh") == True)
assert(allUniqeCharacters_set("joshJ") == True)
assert(allUniqeCharacters_set("joshj") == False)
assert(allUniqeCharacters_set("jjjj") == False)

assert(allUniqeCharacters_no_set("") == True)
assert(allUniqeCharacters_no_set("josh") == True)
assert(allUniqeCharacters_no_set("joshJ") == True)
assert(allUniqeCharacters_no_set("joshj") == False)
assert(allUniqeCharacters_no_set("jjjj") == False)

assert(allUniqeCharacters_no_set2("") == True)
assert(allUniqeCharacters_no_set2("josh") == True)
assert(allUniqeCharacters_no_set2("joshJ") == True)
assert(allUniqeCharacters_no_set2("joshj") == False)
assert(allUniqeCharacters_no_set2("jjjj") == False)
