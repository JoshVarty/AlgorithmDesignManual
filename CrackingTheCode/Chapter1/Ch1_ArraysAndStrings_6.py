#String Compression: Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabbccccaaa would become
#a2b1c5a3. If the compressed string would not become smaller than the original string, your method should return the original string. You
#can assume the string has only uppercase and lowercase letters (A-z)

def stringCompression(input):

    if input == "":
        return ""

    currentChar = input[0]
    currentCount = 1
    newString = ""

    for char in input[1:]:
        if char == currentChar:
            currentCount = currentCount + 1
        else:
            newString = newString + currentChar +  str(currentCount)
            currentChar = char
            currentCount = 1

    
    newString = newString + currentChar +  str(currentCount)
    
    if len(newString) < len(input):
        return newString
    else:
        return input


assert(stringCompression("aaa") == "a3")
assert(stringCompression("aabb") == "aabb")
assert(stringCompression("aabbb") == "a2b3")
assert(stringCompression("a") == "a")
assert(stringCompression("asdf") == "asdf")
assert(stringCompression("aassddff") == "aassddff")
assert(stringCompression("aabcccccaaa") == "a2b1c5a3")



