# Bisect Squares: Given two squares on a two-dimensional plane, find a line that would cut these two squares in half. Assume 
# the top and the bottom sides of the square run parallel to the x-axis

class Point:
    #Point is comprised of an x-coord and a y-coord
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Square:
    #Square is comprised of four points
    def __init__(self, topLeft, topRight, botLeft, botRight):
        self.topLeft = topLeft
        self.topRight = topRight
        self.botLeft = botLeft
        self.botRight = botRight

class Line:
    def __init__(self, slope, intercept):
        self.slope = slope
        self.intercept = intercept

def bisectSquares(square1, square2):

    mid1 = getMiddlePoint(square1)
    mid2 = getMiddlePoint(square2)

    slope = (mid2.y - mid1.y) / (mid2.x - mid2.y)

    # y = mx + b
    # b = y - mx
    intercept = mid1.y - slope * mid1.x
    iPoint = Point(0, intercept)


    return Line(slope, iPoint)

def getMiddlePoint(square):
    midX = (square.topLeft.x + square.topRight.x) / 2
    midY = (square.topLeft.y + square.botLeft.y) / 2

    return Point(midX, midY)
