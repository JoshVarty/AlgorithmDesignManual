# Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks

class QueueWithStacks:
    #FIFO

    def __init__(self):
        #LIFO
        self.stackToPush = []
        self.stackToPop = []

    def push(value):
        self.stackToPush.append(value)
        
    def pop():

        if len(stacktoPop) == 0 and len(stackToPop) == 0:
            raise("No items to pop")
        elif len(stackToPop) == 0:

            while len(stackToPush) > 0:
                #Take all the items from the push stack and put them into the pop stack
                #This reverses them.
                item = stackToPush[-1]
                del stackToPush[-1]

                stackToPop.append(item)

            #Switch stacks
            (stackToPush, stackToPop) = (stackToPop, stackToPush)

        item = stackToPop[-1]
        del stackToPop[-1]
        return item



