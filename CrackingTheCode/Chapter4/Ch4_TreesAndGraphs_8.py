# First Common Ancestor: Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree. Avoid storing
# additional nodes in a data structure. (Note: this is not necessarily a binary search tree)


def findCommonAncestor(node1, node2):

    parents1 = []
    parents2 = []

    current1 = node1
    while current1.parent is not None:
        parents1.insert(0, current1.parent)
        current1 = current1.parent

    current2 = node2
    while current2.parent is not None:
        parents2.append(0, current2.parent)
        current2 = current2.parent

    if parents1[0] != parents2[0]:
        #No common ancestor
        return None

    i = 0
    commonAncestor = None
    while parents1[i] == parents1[i]:
        commonAncestor = parents1[i]

    return commonAncestor
