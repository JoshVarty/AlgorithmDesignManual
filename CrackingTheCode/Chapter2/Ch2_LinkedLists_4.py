#Partition: Write code to partition a linked list around a value x, such that all nodes less than x come before
#all nodes greater than or equal to x. If x is contained within the list, the values of x only need to be
#after the elements less than x. The partition element x can appear anywhere in the "right partition"; it does 
#not need to appear between the left and right partitions.

#EXAMPLE

#Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
#Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
from Node import Node


def partitionLinkedList(head, value):

    smallListHead = None
    smallListCurrent = None
    bigListHead = None
    bigListCurrent = None

    current = head
    while current is not None:
        temp = current.next
        current.next = None

        if current.data < value:
            if smallListCurrent is None:
                smallListHead = current
                smallListCurrent = current
            else:
                smallListCurrent.next = current
                smallListCurrent = current
        else:
            if bigListCurrent is None:
                bigListHead = current
                bigListCurrent = current
            else:
                bigListCurrent.next = current
                bigListCurrent = current

        current = temp
        
    smallListCurrent.next = bigListHead
    return smallListHead


head = Node(3)
head.appendToTail(5)
head.appendToTail(8)
head.appendToTail(5)
head.appendToTail(10)
head.appendToTail(2)
head.appendToTail(1)
newHead = partitionLinkedList(head, 5)
x = head.toList()
assert(newHead.toList() == [3,2,1,5,8,5,10]) 

head = Node(3)
head.appendToTail(5)
head.appendToTail(8)
head.appendToTail(5)
head.appendToTail(10)
head.appendToTail(2)
head.appendToTail(1)
newHead = partitionLinkedList(head, 3)
x = head.toList()
assert(newHead.toList() == [2,1,3,5,8,5,10]) 

head = Node(3)
head.appendToTail(5)
head.appendToTail(8)
head.appendToTail(5)
head.appendToTail(10)
head.appendToTail(2)
head.appendToTail(1)
newHead = partitionLinkedList(head, 8)
x = head.toList()
assert(newHead.toList() == [3,5,5,2,1,8,10]) 

