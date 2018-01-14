#Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

from Node import Node


def KthToLastElement(head, k):

    current = head
    i = 0
    while i < (k - 1) and current is not None:
        i = i + 1
        current = current.next

    #Guard
    if i != k - 1:
        raise("Smaller than k")

    runner1 = head
    runner2 = current
    while runner2.next is not None:
        runner1 = runner1.next
        runner2 = runner2.next

    return runner1.data

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
head.appendToTail(6)
head.appendToTail(7)
head.appendToTail(8)
assert(KthToLastElement(head, 5) == 4) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
assert(KthToLastElement(head, 1) == 3) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
assert(KthToLastElement(head, 2) == 2) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
assert(KthToLastElement(head, 3) == 1) 