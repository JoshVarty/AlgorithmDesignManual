# LRU Cache: Design and build a "least recently used" cache, which evicts the least recetnyl used item. The cache should map from keys to 
# values (allowing you to insert and retrieve a value associated with a particular key) and be initialized with a max size. When it is full
# it should evict the least recently used item.


# My strategy: Use a increasing counter to represent when an item was last touched.
# When we need to find the oldest item, we have to process all items in the list to find it and remove it.


class LRU:

    def __init__(self, maxSize):
        self.maxSize = maxSize

        self.currentAge = 0
        self.items = {}


    def insert(self, key, value):

        if len(items) >= self.maxSize:
            oldest = 99999999 #Or some int max
            oldestKey = None

            for key, (age, value)  in self.items:
                if age < oldest:
                    oldest = age
                    oldestKey = key

            #Remove the oldest item
            del self.items[oldestKey]
            
        self.items[key] = (self.currentAge, value)
        self.incrementAge() 

    def retrieve(self, key):

        (age, value) = self.items[key]
        self.items[key] = (self.currentAge, value)
        incrementAge()

        return value

    def incrementAge(self):
        self.currentAge = self.currentAge + 1
        #Ideally if this overflowed we'd re-age all of our items starting from 0