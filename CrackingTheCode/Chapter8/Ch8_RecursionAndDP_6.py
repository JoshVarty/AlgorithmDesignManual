# Towers of Hanoi: In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of different sizes which can slide onto any
# tower. The puzzel starts with the disks sorted in ascending order of size from top to bottom (i.e. each disk sits on top of an even larger
# one). You have the following constraints:
# 
# 1. Only one disk can be moved at a time.
# 2. A disk is slid off the top of one tower onto another tower.
# 3. A disk cannot be placed on top of a smaller disk.

# Write a program to move the disks from the first tower to the last tower using stacks 


def moveDisks(numDisks, start, ending, buffer):

    if numDisks <= 0:
        return
    
    #move top n - 1 disks from start to buffer, using destination as a buffer
    moveDisks(n - 1, start, buffer, ending)

    #Move the top item from start to end
    lastItem = start[0]
    del start[0]
    ending.insert(0, lastItem)

    #move the top n - 1 disks from buffer to destination, using the start as the buffer
    moveDisks(n - 1, buffer, ending, start)