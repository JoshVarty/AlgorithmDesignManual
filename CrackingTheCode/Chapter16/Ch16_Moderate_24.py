# Pairs with Sum: Design an algorithm to find all pairs of integers within an array which sum to a specified value.


def pairsWithSum(numbers, targetSum):

    lookup = {}
    #Count number of each
    for i in numbers:
        if i in lookup:
            lookup[i] = lookup[i] + 1
        else:
            lookup[i] = 1

    pairs = {}
    for i in numbers:
        requiredNum = targetSum - i

        #Check if the required num is in the lookup
        #If the required number is the same as current number, we have to make sure we've got another copy of it to work with
        if (requiredNum != i and i in lookup) or (requiredNum == i and i in lookup and lookup[i] > 1):

            small = min(required, i)
            big = max(requiredNum, i)

            if small not in pairs:
                pairs[small] = (small, big)

            #If we've used the numbers up, we can't use them again. (Unclear from question)
            lookup[i] = lookup[i] - 1
            lookup[requiredNum] = lookup[requiredNum] - 1

    return list(pairs.values())