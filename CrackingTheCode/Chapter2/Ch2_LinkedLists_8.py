# Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the 
# beginning of the loop.
# DEFINITION
# Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
# as to make a loop in the linked list
# EXAMPLE
# Input:    A -> B -> C -> D -> E -> C (Same as earlier)
# Output: C


from Node import Node


def detectLoop(head):

    slow = head
    fast = head
    collisionPoint = None

    #Find collision point
    while fast != None and fast.next != None:
        
        slow = slow.next
        fast = fast.next.next
        
        if fast == slow:
            collisionPoint = slow
            break


    #If no collision, there's no cycle
    if collisionPoint is None:
        return None

    #Now we start at the front and from the collision, when they are equal, we have the 
    #origin of the cycle
    current = head
    while current != collisionPoint:
        current = current.next
        collisionPoint = collisionPoint.next

    return current


#No Loop
head = Node(1)
head.appendToTail(2)
result = detectLoop(head)
assert(result == None)

#One item loop
head = Node(1)
head.next = head
result = detectLoop(head)
assert(result == head)
    
#Book's example
head = Node(1)
head.appendToTail(2)
C = head.appendToTail(3)
head.appendToTail(4)
E = head.appendToTail(5)
E.next = C
result = detectLoop(head)
assert(result == C)

#Book's example, longer start
head = Node(1)
head.appendToTail(2)
head.appendToTail(9)
head.appendToTail(3)
head.appendToTail(2)
head.appendToTail(1)
head.appendToTail(4)
C = head.appendToTail(3)
head.appendToTail(4)
E = head.appendToTail(5)
E.next = C
result = detectLoop(head)
assert(result == C)
