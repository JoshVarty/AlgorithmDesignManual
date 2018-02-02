# Parens: Implement an algorithm to print all valid (i.e. properly opened and closed) combinations of n pairs of parentheses.


def addParen(list, leftRemaining, rightRemaining, result, index):

    if (leftRemaining < 0 or rightRemaining < leftRemaining):
        return

    if leftRemaining == 0 and rightRemaining == 0:
        list.append(''.join(result))
    else:
        result[index] = '(' 
        addParen(list, leftRemaining - 1, rightRemaining, result, index + 1)
        
        result[index] = ')' 
        addParen(list, leftRemaining, rightRemaining - 1, result, index + 1)

def generateParens(numParens):

    buffer = ["" for _ in range(numParens * 2)]
    result = []
    addParen(result, numParens, numParens, buffer, 0)
    return result


result = generateParens(1)
assert(len(result) == 1)
assert("()" in result)

result = generateParens(2)
assert(len(result) == 2)
assert("()()" in result)
assert("(())" in result)

result = generateParens(3)
assert(len(result) == 5)
assert("()()()" in result)
assert("(()())" in result)
assert("(())()" in result)
assert("()(())" in result)
assert("((()))" in result)

