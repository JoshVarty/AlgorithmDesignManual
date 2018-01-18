#Stack Min: How would you design a stack which, in addition to push and pop, has a function which returns 
#the minimum element? Push, pop and min should all operate in O(1) time.

#My solution: Let's have two stacks:
#-Regular stack
#-Min stack
# The MinStack will hold all the minimums as we know them. When we pop off our regular stack, we also pop off 
# the min stack, and we recover what the minimum was when the stack had one less item in it


class StackWithMin:

    def __init__():
        self.stack = []
        self.minStack = []
        pass

    def getMin():
        if len(self.minStack > 0 ):
            return self.minStack[len(self.minStack) - 1]

        raise("Stack is empty")

    def push(value):

        #Keep track of current minimum
        if len(self.minStack) == 0:
            self.minStack.append(value)
        elif self.minStack[len(self.minStack) - 1] > value:
            self.minStack.append(value)
        else:
            self.minStack.append(self.minStack[len(self.minStack) - 1])

        self.stack.append(value)

    def pop():
        #Pop item and remove it from stack
        lastItem = self.stack[len(self.stack) - 1]
        del self.stack[len(self.stack) - 1]

        #Remove last min from minStack
        del self.minStack[len(self.minStack) - 1]

        return lastItem



        







