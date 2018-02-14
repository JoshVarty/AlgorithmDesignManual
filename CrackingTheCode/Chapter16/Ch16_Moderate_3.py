# Intersection: Given two straight line segments (represented as a start point and an end point), comput the point of intersection, if any.


def intersection(point1Start, point1End, point2Start, point2End):

    #We want our points to be ordered from left to right
    if point1Start.x > point1End.x:
        (point1Start, point1End) = (point1End, point1Start)

    if point2Start.x > point2End.x:
        (point2Start, point2End) = (point2End, point2Start)

    if point1Start.x > point2Start.x:
        (point1Start, point2Start) = (point2Start,point1Start)
        (point1End, point2End) = (point2End,point1End)

    line1 = getLine(point1Start, point1End)
    line2 = getLine(point2Start, point2End)

    #If the lines are parallel, they need the same intercept and the start of the second line needs to be
    #between the start and end of the first line
    if line1.slope == line2.slope:
        if line1.intercept == line2.intercept and isBetween(start1, start2, end1):
            return start2

        return None

    #Find where X's are equal
    # m1x+b1 = m2x+b2
    # x = (b2-b1)/(m1-m2)
    x = (line2.intercept - line1.intercept)/(line1.slope - line2.slope)

    #Find y
    #y = mx + b
    y = line1.slope * x + line1.intercept

    onLine1 = isBetween(point1Start.x, x, point1End.x) and isBetween(point1Start.y, y, point1End.y)
    onLine2 = isBetween(point2Start.x, x, point2End.x) and isBetween(point2Start.y, y, point2End.y)

    if onLine1 and onLine2:
        return True

    return None

def isBetween(low, middle, high):
    return low <= middle and middle <= high

def getLine(start, end):

    slope = (end.y - start.y) / (end.x - start.x)

    #y = mx + b
    #b = y - mx
    intercept = start.y - slope * start.x
    
    line = {
        #Might be nice to have these later
        start: start, 
        end: end,
        slope: slope,
        intercept: intercept
        }

    return line
    