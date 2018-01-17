#Palindrome: Implement a function to check if a linked list is a palindrome.

from Node import Node


def isPalindromeWithStack(head):

    if head is None or head.next is None:
        return True

    stack = []
    fast = head
    slow = head

    while fast is not None and fast.next is not None:
        stack.insert(0, slow.data)
        slow = slow.next
        fast = fast.next.next

    #If it was an odd length list, we skip the middle item
    if fast is not None:
        slow = slow.next

    #Now continue moving slow, making sure all match what we've put in our stack
    while slow is not None:

        top = stack[0]
        if slow.data != top:
            return False

        stack.remove(top)
        slow = slow.next

    return True 


head = Node(1)
result = isPalindromeWithStack(head)
assert(result == True)

head = Node(1)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == True)

head = Node(1)
head.appendToTail(1)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == True)

head = Node(1)
head.appendToTail(5)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == True)

head = Node(1)
head.appendToTail(5)
head.appendToTail(5)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == True)

head = Node(1)
head.appendToTail(5)
head.appendToTail(9)
head.appendToTail(5)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == True)


head = Node(1)
head.appendToTail(2)
result = isPalindromeWithStack(head)
assert(result == False)

head = Node(0)
head.appendToTail(1)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == False)

head = Node(1)
head.appendToTail(5)
head.appendToTail(3)
result = isPalindromeWithStack(head)
assert(result == False)

head = Node(1)
head.appendToTail(5)
head.appendToTail(9)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == False)

head = Node(1)
head.appendToTail(2)
head.appendToTail(9)
head.appendToTail(5)
head.appendToTail(1)
result = isPalindromeWithStack(head)
assert(result == False)
