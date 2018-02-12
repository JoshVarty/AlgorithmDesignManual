# Word Frequencies: Design a method to find the frequency of occurrences of any given word in a book. What if we were running this algorithm
# multiple times?

#Either just count (maybe sanitize input a bit)
#Or just build an index of word -> count

def getFrequencyOnce(words, searchTerm):
    seachTerm = searchTerm.strip().lower()

    count = 0
    for word in words:
        if word.strip.lower() == searchTerm:
            count = count + 1


index = None
def getFrequencyMultipleTimes(words, searchTerm):
    seachTerm = searchTerm.strip().lower()

    if index is None:
        index = buildIndex

    if searchTerm in index:
        return index[searchTerm]

    return 0
    

def buildIndex(words):
    index = {}

    for word in words:
        cleanWord = word.strip().lower()
        if cleanWord in index:
            index[cleanWord] = index[cleanWord] + 1
        else:
            index[cleanWord] + 1

    return index



