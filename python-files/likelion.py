class Figure:
    def __init__(self, dots, height, width):
        self.dots = dots
        self.height = height
        self.width = width

    def calcArea(self):
        pass


class Line(Figure):
    def calcArea(self):
        if self.dots != 2:
            print('This is not a line.')
            return -1
        return 0


class Triangle(Figure):
    def calcArea(self):
        if self.dots != 3:
            print('This is not a triangle.')
            return -1
        return self.height * self.width / 2


class Rectangle(Figure):
    def calcArea(self):
        if self.dots != 4:
            print('This is not a rectangle.')
            return -1
        return self.height * self.width


line = Line(2, 4, 0)
tri = Triangle(3, 4, 2)
rect = Rectangle(4, 4, 2)

print('line의 점의 개수 : {0}, line의 넓이 : {1}'.format(line.dots, line.calcArea()))
print('triangle의 점의 개수 : {0}, triangle의 넓이 : {1}'.format(
    tri.dots, tri.calcArea()))
print('rectangle의 점의 개수 : {0}, rectangle의 넓이 : {1}'.format(
    rect.dots, rect.calcArea()))
