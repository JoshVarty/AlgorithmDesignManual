# Shuffle: Write a method to shuffle a deck of cards. It must be a perfect shuffle. In other words, each of the 52! permutations of the deck
# has to be equally likely.

# First thought: 
#   Make a new array
#   Randomly choose a card to put into the first slot. (All are equally likely).
#   Continue randomly choosing cards for each slot.
# Cons:
#   Not in place

import random

def shuffleDeck(cards):
    for i in range(len(cards)):
        index = random.randint(0, i)

        cards[index], cards[i] = cards[i], card[index]
    


#                   [0,1,2]                                             Swapping from 0 to 0
#       [0,1,2]                 [1,0,2]                                 Swapping from 0 to 1
#[0,1,2]  [2,1,0]  [0,2,1]   [1,0,2]    [2,0,1]   [1,2,0]               Swapping from 0 to 2