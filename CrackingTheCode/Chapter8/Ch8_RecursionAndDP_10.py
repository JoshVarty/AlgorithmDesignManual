# Paint Fill: Implement the "paint fill" function that one might see on many image editing programs. THat is, given a screen (represented
# by a two dimensional array of colors), a point, and a new color, fill in the surrounding area until the color changes from the original
# color.


def paintFill(screen, x, y, newColor, oldColor = None):

    if x < 0 or y < 0 or x > len(screen[0]) - 1 or y > len(screen) - 1:
        return;

    currentColor = screen[y][x]

    if oldColor is None:
        oldColor = currentColor

    if oldColor != currentColor:
        return

    #Color it
    screen[y][x] = newColor

    paintFill(screen, x + 1, y + 1, newColor, oldColor)
    paintFill(screen, x, y + 1, newColor, oldColor)
    paintFill(screen, x - 1, y + 1, newColor, oldColor)
    paintFill(screen, x, y - 1, newColor, oldColor)



 