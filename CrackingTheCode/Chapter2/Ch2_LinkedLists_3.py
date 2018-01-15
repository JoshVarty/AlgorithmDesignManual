#Delete (any) Middle Node: Implement an algorithm to delete a node in the middle (ie. any node but the first
#and last node, not necessarily the exact moddle) of a singly linked list, given only access to that node
from Node import Node

def deleteMiddleNode(node):

    current = node
    last = None
    while current.next is not None:
        nextData = current.next.data
        current.data = nextData
        last = current
        current = current.next
    
    #Remove the last node
    last.next = None

head = Node(1)
node = head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
head.appendToTail(6)
head.appendToTail(7)
deleteMiddleNode(node)
assert(head.toList() == [1,3,4,5,6,7]) 

head = Node(1)
head.appendToTail(2)
node = head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
head.appendToTail(6)
head.appendToTail(7)
deleteMiddleNode(node)
assert(head.toList() == [1,2,4,5,6,7]) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
node = head.appendToTail(4)
head.appendToTail(5)
head.appendToTail(6)
head.appendToTail(7)
deleteMiddleNode(node)
assert(head.toList() == [1,2,3,5,6,7]) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
node = head.appendToTail(5)
head.appendToTail(6)
head.appendToTail(7)
deleteMiddleNode(node)
assert(head.toList() == [1,2,3,4,6,7]) 

head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
node = head.appendToTail(6)
head.appendToTail(7)
deleteMiddleNode(node)
assert(head.toList() == [1,2,3,4,5,7]) 

