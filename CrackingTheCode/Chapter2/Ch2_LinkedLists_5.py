#Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse
#order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

#EXAMPLE
#Input: (7 -> 1 -> 6) + (5 -> 9 -> 2).
#Output: (2-> 1 -> 9)

#FOLLOWUP
#Suppose the digits are stored in forward order. Repeat the above problem.


#EXAMPLE
#Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).
#Output: (9-> 1 -> 2)

from Node import Node

def addReverse(head1, head2):

    carry = 0

    current1 = head1
    current2 = head2
    result = None
    currentResultNode = None

    while (current1 is not None or current2 is not None):

        data1 = 0
        data2 = 0

        if current1 is not None:
            data1 = current1.data

        if current2 is not None:
            data2 = current2.data

        sum = carry + data1 + data2
        if sum > 9:
            sum = sum - 10
            carry = 1
        else:
            carry = 0

        currentResult = Node(sum)
        
        if currentResultNode is None:
            #This is the first node, keep track of head
            result = currentResult
            currentResultNode = currentResult
        else:
            currentResultNode.next = currentResult
            currentResultNode = currentResult

        if current1 is not None:
            current1 = current1.next
        if current2 is not None:
            current2 = current2.next

    if carry != 0:
        currentResult = Node(carry)
        currentResultNode.next = currentResult
        currentResultNode = currentResult


    return result

def addForward(head1, head2):

    current1 = head1
    current2 = head2

    numDigits1 = 0
    numDigits2 = 0
    #Count digits in each
    while current1 is not None:
        current1 = current1.next
        numDigits1 = numDigits1 + 1
    
    while current2 is not None:
        current2 = current2.next
        numDigits2 = numDigits2 + 1

    carry, returnedNode = addDigits(head1, head2, numDigits1 - 1, numDigits2 - 1)

    if carry != 1:
        return returnedNode
    else:
        newNode = Node(carry)
        newNode.next = returnedNode
        return newNode
        

def addDigits(current1, current2, numDigits1, numDigits2):

    if numDigits1 == 0 and numDigits2 == 0:
        sum = current1.data + current2.data

        carry = 0
        if sum > 9:
            carry = 1
            sum = sum - 10

        newNode = Node(sum)
        return (carry, newNode)

    data1 = 0
    data2 = 0

    if numDigits1 > numDigits2:
        (carry, returnedNode) = addDigits(current1.next, current2, numDigits1 - 1, numDigits2)
        data2 = current1.data
    elif numDigits1 < numDigits2:
        (carry, returnedNode) = addDigits(current1, current2.next, numDigits1, numDigits2 - 1)
        data1 = current2.data
    else:
        (carry, returnedNode) = addDigits(current1.next, current2.next, numDigits1 - 1, numDigits2 - 1)

        data1 = current1.data
        data2 = current2.data
   
    sum = carry + data1 + data2
    if sum > 9:
        sum = sum - 10
        carry = 1
    else:
        carry = 0

    currentResult = Node(sum)
    currentResult.next = returnedNode
    return (carry, currentResult)
    

#Tests for addReverse()

#Single Digit
head1 = Node(1)
head2 = Node(2)
result = addReverse(head1, head2)
assert(result.toList() == [3]) 

#Multidigit no carry
head1 = Node(1)
head1.appendToTail(2)
head2 = Node(1)
head2.appendToTail(2)
result = addReverse(head1, head2)
assert(result.toList() == [2,4]) 

#Single digit carry 
head1 = Node(9)
head2 = Node(9)
result = addReverse(head1, head2)
assert(result.toList() == [8,1]) 

#Multi digit carry
head1 = Node(9)
head1.appendToTail(2)
head2 = Node(7)
head2.appendToTail(3)
result = addReverse(head1, head2)
assert(result.toList() == [6,6]) 

#Multi digit multi carry
head1 = Node(9)
head1.appendToTail(5)
head2 = Node(1)
head2.appendToTail(4)
result = addReverse(head1, head2)
assert(result.toList() == [0,0,1]) 

#Mixed digits (1 off)
head1 = Node(9)
head2 = Node(7)
head2.appendToTail(3)
result = addReverse(head1, head2)
assert(result.toList() == [6,4]) 

#Mixed digits (5 off)
head1 = Node(5)
head2 = Node(4)
head2.appendToTail(3)
head2.appendToTail(3)
head2.appendToTail(2)
head2.appendToTail(1)
head2.appendToTail(1)
result = addReverse(head1, head2)
assert(result.toList() == [9,3,3,2,1,1]) 





#Tests for addForward()

#Single Digit
head1 = Node(1)
head2 = Node(2)
result = addForward(head1, head2)
assert(result.toList() == [3]) 

#Multidigit no carry
head1 = Node(1)
head1.appendToTail(2)
head2 = Node(1)
head2.appendToTail(2)
result = addForward(head1, head2)
assert(result.toList() == [2,4]) 

#Single digit carry 
head1 = Node(9)
head2 = Node(9)
result = addForward(head1, head2)
assert(result.toList() == [1,8]) 

#Multi digit carry
head1 = Node(9)
head1.appendToTail(2)
head2 = Node(7)
head2.appendToTail(3)
result = addForward(head1, head2)
assert(result.toList() == [1,6,5]) 

#Multi digit multi carry
head1 = Node(5)
head1.appendToTail(9)
head2 = Node(4)
head2.appendToTail(1)
result = addForward(head1, head2)
assert(result.toList() == [1,0,0]) 

#Mixed digits (1 off)
head1 = Node(9)
head2 = Node(7)
head2.appendToTail(3)
result = addForward(head1, head2)
assert(result.toList() == [8,2]) 

#Mixed digits (5 off)
head1 = Node(5)
head2 = Node(4)
head2.appendToTail(3)
head2.appendToTail(3)
head2.appendToTail(2)
head2.appendToTail(1)
head2.appendToTail(1)
result = addForward(head1, head2)
assert(result.toList() == [4,3,3,2,1,6]) 
 
#Both multi digit, mixed digits
head1 = Node(5)
head1.appendToTail(3)
head2 = Node(4)
head2.appendToTail(3)
head2.appendToTail(3)
head2.appendToTail(1)
result = addForward(head1, head2)
assert(result.toList() == [4,3,8,4]) 
