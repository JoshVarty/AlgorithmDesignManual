# Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
# an additional temporary stack, but you may not copy the elements into any other data structure (such as an
# array). The stack supports the following operations: push, pop, peek, isEmpty.


def sortStack(stack):

    sortedStack = []

    while len(stack) > 0:
        #Take the item off the stack
        currentItem = stack[-1]
        del stack[-1]

        numItemsMoved = 0
        #Move all the smaller items to the original stack
        while len(sortedStack) > 0 and sortedStack[-1] < currentItem:
            item = sortedStack[-1]
            del sortedStack[-1]
            stack.append(item)
            numItemsMoved = numItemsMoved + 1

        #Put the current item in its right place
        sortedStack.append(currentItem)

        #Move all those smaller items back onto the sorted stack
        while numItemsMoved > 0:
            item = stack[-1]
            del stack[-1]
            sortedStack.append(item)

            numItemsMoved = numItemsMoved - 1

    return sortedStack


#Note: I'm considering the right hand side of the list to be the "top" of the stack
stack = [1]
sortedStack = sortStack(stack)
assert(sortedStack == [1])

stack = [1,2]
sortedStack = sortStack(stack)
assert(sortedStack == [2,1])

stack = [2,1]
sortedStack = sortStack(stack)
assert(sortedStack == [2,1])

stack = [3,2,1]
sortedStack = sortStack(stack)
assert(sortedStack == [3,2,1])

stack = [1,3,2]
sortedStack = sortStack(stack)
assert(sortedStack == [3,2,1])

stack = [1,9,3,2,4,8,5,7,6]
sortedStack = sortStack(stack)
assert(sortedStack == [9,8,7,6,5,4,3,2,1])

stack = [1,1,3,5,1,4]
sortedStack = sortStack(stack)
assert(sortedStack == [5,4,3,1,1,1])
