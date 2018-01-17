# Given two linked lists, determine if the two lists intersect. Return the intersecting node. Note that 
#intersection is defined based on reference, not value. That is, if the kth node of the first linked list 
#is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.

from Node import Node


def findIntersection(head1, head2):

    #Count how long each chain is
    length1 = 0
    current1 = head1
    while current1 is not None:
        length1 = length1 + 1
        current1 = current1.next

    length2 = 0
    current2 = head2
    while current2 is not None:
        length2 = length2 + 1
        current2 = current2.next

    #Optimization, if the last nodes aren't identical, there's no way there was an intersection.
    if current2 != current1:
        return None

    #Align the chains so they are the same length.
    #An intersection cannot be greater than the length of the other list.
    current1 = head1
    while length1 > length2:
        current1 = current1.next
        length1 = length1 - 1

    current2 = head2
    while length2 > length1:
        current2 = current2.next
        length2 = length2 - 1

    #Because it'll be reference intersection, wherever it intersects will have the same length in each list
    while current1 is not None and current2 is not None:
        if current1 == current2:
            return current2

        current1 = current1.next
        current2 = current2.next

    #This shouldn't be possible. If they had the same last node, then we should have found an intersection.
    return None


#Length 1 intersection
head1 = Node(1)
head2 = head1
result = findIntersection(head1, head2)
assert(result == head2)

#Length 1 no intersection
head1 = Node(1)
head2 = Node(1)
result = findIntersection(head1, head2)
assert(result == None)

#Length 3 all intersection
head1 = Node(1)
head1.appendToTail(1)
head1.appendToTail(1)
head2 = head1
result = findIntersection(head1, head2)
assert(result == head2)

#Length 3 one intersection
head1 = Node(1)
head1.appendToTail(2)
intersection = head1.appendToTail(3)
head2 = intersection
result = findIntersection(head1, head2)
assert(result == intersection)

#Length 2 no intersection
head1 = Node(1)
head1.appendToTail(2)
head2 = Node(1)
head2.appendToTail(2)
result = findIntersection(head1, head2)
assert(result == None)