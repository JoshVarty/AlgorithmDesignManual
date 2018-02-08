# Stack of Boxes: You have a stack of n boxes, with withs wi, heights hi, and depths di. The boxes cannot be rotated and can only be stacked on top of one another if each box in the stack is strictly
# larger than the box above it in width, height and depth. Implement a method to compute the height of the tallest possible stack. The height
# of the stack is the sums of the heights of each box.


# My solution is to generate all the permutations of boxes while performing two optimizations:
#   1. If we can't stack the current box on top of the last box, stop exploring this possibility
#   2. Cache the results of box combinations so once we see them, we don't have to re-explore that subtree

def stackBoxes(boxes, index = 0, lookup = {}):
    #We start by getting the height of the current stack since we know that it's valid
    maxHeight = getHeight(boxes, index - 1)
        
    for i in range(index, len(boxes)):

        if index > 0:
            lastBox = boxes[i - 1]
            current = boxes[i]

            key = getKey(boxes, index)
            if key in lookup:
                #If we've seen the next combination of boxes, we know what the max height of that sub-stack will be
                stackHeight = lookup[key]
                maxHeight = max(stackHeight, maxHeight)
            else:
                #We have to check if we can stack the next block at all
                if isValidStack(lastBox, current):
                    swap(boxes, i, index)

                    stackHeight = stackBoxes(boxes, index + 1)
                    lookup[key] = stackHeight
                    maxHeight = max(stackHeight, maxHeight)
                    swap(boxes, i, index)
        else:
            #We're building a stack of size 1, so it's always valid
            swap(boxes, i, index)
            stackHeight = stackBoxes(boxes, index + 1)
            maxHeight = max(stackHeight, maxHeight)
            swap(boxes, i, index)

    return maxHeight

def isValidStack(box1, box2):
    if box1.height < box2.height or box1.depth < box2.depth or box1.width < box2.width:
        return False

    return True

def getHeight(boxes, maxIndex):
    height = 0
    for i in range(maxIndex):
        height = height + boxes[i].height

    return height

def getKey(boxes, maxIndex):
    key  = ""
    for i in range(maxIndex, len(boxes)):
        key = key + "->" + str(i)

    return key
