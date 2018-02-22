# Living People: Given a list of people with their birth and death years, implement a method to compute the year with the most number of 
# people alive. You may assume that all people were born between 1900 and 2000 (inclusive). If a perosn was alive during any portion of 
# the year then they should be included in that year's count. For example, Person (birth=1908, death 1909) is included in the counts for
# both 1908 and 1909.


# O(people) + O(years)

def getMostLivingPeople(listOfPeople):

    deltas = [0 for _ in range(102)]

    #Mark when the person was born and died
    for person in listOfPeople:

        birthDelta = person.birth - 1900
        deathDelta = person.death - 1900

        delta[birthDelta] = delta[birthDelta]  + 1

        #If someone dies on the same year they were born, we want to count them as "living" for the whole year.
        #We need to discount them from the following year instead
        if birthDelta != deathDelta:
            delta[deathDelta] = delta[deathDelta]  - 1
        else:
            delta[deathDelta + 1] = delta[deathDelta + 1]  - 1

    maxPeople = -1
    maxYear = None

    numPeopleAlive = 0

    #Go through the deltas and keep a running total of number of living people
    for idx in range(len(deltas)):
        delta = deltas[idx]
        numPeopleAlive = numPeopleAlive + delta

        if numPeopleAlive > maxPeople:
            maxPeople = numPeopleAlive
            maxYear = idx + 1900

    return maxYear
