#Remove Dupes: Write code to remove duplicates from an unsorted linked list.  
#How would you solve this problem if a temporary buffer is not allowed

from Node import Node

def removeDuplicates_Buffer(head):
    seenData = set()
    seenData.add(head.data)

    current = head
    while current.next is not None:
        nextData = current.next.data
        if nextData in seenData:
            current.next = current.next.next
        else:
            seenData.add(nextData)
            current = current.next

    return head.toList()

def removeDuplicates_NoSet(head):
    #For each node, remove all nodes after it that have the same value
    current = head
    while current is not None and current.next is not None:
        currentData = current.data
        removeDataFromList(current, currentData)
        current = current.next

    return head.toList()


def removeDataFromList(current, data):

    while current.next is not None:
        nextData = current.next.data
        if nextData == data:
            current.next = current.next.next
        else:
            current = current.next

#NoRemovals
head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
assert(removeDuplicates_Buffer(head) == [1,2,3,4,5])

#All dupes
head = Node(1)
head.appendToTail(1)
head.appendToTail(1)
head.appendToTail(1)
head.appendToTail(1)
assert(removeDuplicates_Buffer(head) == [1])

#Multiple dupes
head = Node(1)
head.appendToTail(2)
head.appendToTail(1)
head.appendToTail(3)
head.appendToTail(2)
assert(removeDuplicates_Buffer(head) == [1,2,3])

#Dupes at end
head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(4)
assert(removeDuplicates_Buffer(head) == [1,2,3,4])


#NoRemovals
head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(5)
assert(removeDuplicates_NoSet(head) == [1,2,3,4,5])

#All dupes
head = Node(1)
head.appendToTail(1)
head.appendToTail(1)
head.appendToTail(1)
head.appendToTail(1)
assert(removeDuplicates_NoSet(head) == [1])

#Multiple dupes
head = Node(1)
head.appendToTail(2)
head.appendToTail(1)
head.appendToTail(3)
head.appendToTail(2)
assert(removeDuplicates_NoSet(head) == [1,2,3])

#Dupes at end
head = Node(1)
head.appendToTail(2)
head.appendToTail(3)
head.appendToTail(4)
head.appendToTail(4)
assert(removeDuplicates_NoSet(head) == [1,2,3,4])