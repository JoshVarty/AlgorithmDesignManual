#Three in One: Describe how you could use a single array to implement three stacks.


#Solution: Divide the array up into thirds and use each third as a stack. Just watch out for the bounds.

class ThreeStacksOneArray:

    def __init__(size):
        self.length = size
        self.array = [0 for _ in range(size)]

        #Each stack gets 1/3 of the array to work with
        s1Pointer = int(self.length *  0 / 3)
        s2Pointer = int(self.length *  1 / 3)
        s3Pointer = int(self.length *  2 / 3)


    def pushStack1(value):
        if self.s1Pointer >= int(self.length * 1 / 3):
            raise("Too many items in first stack")

        self.array[self.s1Pointer] = value
        self.s1Pointer = self.s1Pointer + 1

    def popStack1():
        if self.s1Pointer < int(self.length * 0 / 3):
            raise("No items left in first stack")

        item = self.array[self.s1Pointer]
        self.array[self.s1Pointer] = 0 # Delete the item. Optional.
        return item

    
    def pushStack2(value):
        if self.s2Pointer >= int(self.length * 2 / 3):
            raise("Too many items in second stack")

        self.array[self.s2Pointer] = value
        self.s2Pointer = self.s2Pointer + 1

    def popStack2():
        if self.s2Pointer < int(self.length * 1 / 3):
            raise("No items left in first stack")

        item = self.array[self.s2Pointer]
        self.array[self.s2Pointer] = 0 # Delete the item. Optional.
        return item
    

    def pushStack3(value):
       if self.s3Pointer >= int(self.length * 3 / 3):
            raise("Too many items in third stack")

       self.array[self.s3Pointer] = value
       self.s3Pointer = self.s3Pointer + 1

    def popStack3():
        if self.s3Pointer < int(self.length * 2 / 3):
            raise("No items left in first stack")

        item = self.array[self.s3Pointer]
        self.array[self.s3Pointer] = 0 # Delete the item. Optional.
        return item

