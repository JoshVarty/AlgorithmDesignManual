# Stack of plates: Imagine a literal stack of plates. If the stack gets too high, it might topple. Therefore, in
# real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data
# structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a 
# new stack  once the pervious one exceeds capacity. SetOfStacks.push() and SetOfStacks.poop should behave
# identically to a single stack. (that is pop() should return the same values as if there was a single stack)
# FOLLOWUP
# Implement a function popAt(index) which perform a pop operation on a specific sub-stack.

class SetOfStacks:

    def __init__(threshold):
        #Initialize the set of stacks
        self.stacks = []
        self.currentStackIndex = -1
        self.threshold = threshold

    def push(value):
        if len(self.stacks) == 0:
            newStack = []
            self.stacks.append(newStack)
            self.currentStack = 0

        currentStack = self.stacks[self.currentStackIndex]
        if len(currentStack) >= threshold:
            #If we've run out of room, add a newStack
            newStack = []
            self.stacks.append(newStack)
            self.currentStackIndex = self.currentStackIndex + 1
            currentStack = newStack

        currentStack.append(value)

    def pop():
        #If there's no stacks, there's nothing to pop
        if len(self.stacks) == 0:
            raise("Nothing to pop")

        currentStack = self.stacks[self.currentStackIndex]

        #We have to loop, because someone could have used 
        #popAt to remove all the items from previous stacks.
        while len(currentStack) == 0:
            del self.stacks[-1]
            self.currentStackIndex = self.currentStackIndex - 1

            #Need to check if we removed the last stack again
            if len(self.stacks) == 0:
                raise("Nothing to pop")

            currentStack = self.stacks[self.currentStackIndex]

        #Retrieve/Remove the last item and return it.
        value = currentStack[-1]
        del currentStack[-1]
        return value


    def popAt(stackIndex):
        if stackIndex > self.currentStack:
            raise("No such stack")

        chosenStack = self.stacks[stackIndex]
        if len(choseStack) == 0:
            raise("No items on this stack")

        #Retrieve/Remove the last item and return it.
        value = chosenStack[-1]
        del chosenStack[-1]
        return value
