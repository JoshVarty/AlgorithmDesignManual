# Letters and Numbers: Given an array filled with letters and numbers, find the longest subarray with an equal number of letters and numbers

def longestSubarray(input):

    differences = [0]

    for idx in range(len(input)):
        char = input[idx]

        prevValue = differences[idx]

        if char.isdigit():
            differences.append(prevValue  - 1)
        else:
            differences.append(prevValue  + 1)

    #Now we're looking for the furthest apart equivalent values

    lookup = {0:-1}
    maxPair = (0, 0)
    for idx, delta in enumerate(differences):
        if delta not in lookup:
            lookup[delta] = idx
        else:
            match = lookup[delta]
            distance = idx - match
            longest = maxPair[1] - maxPair[0]
            if distance > longest:
                max[0] = match
                max[1] = idx


    return maxPair

longestSubarray("a0a0000")

