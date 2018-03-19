# Random Set: Write a method to randomly generate a set of m integers from an array size of n. Each element must have an equal probablity of 
# being chosen.

import random

def randomSet(input, m):

    #Load up m elements into array
    m_elements = []
    for i in m:
        m_elements[i] = input[i]

    #For each of the remaining elements, see if we should swap them into the subset
    for i in range(m, len(input)):
        k = random.randint(0, i)
        if k < m:
            m_elements[k] = input[i]

    return m_elements