
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

    def appendToTail(self, data):
        end = Node(data)
        current = self

        while current.next is not None:
            current = current.next

        current.next = end

        return end


    def toList(self):
        list = [self.data]
        current = self

        while current.next is not None:
            current = current.next
            list.append(current.data)

        return list