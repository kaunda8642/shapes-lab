// shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>

// Abstract base class
class Shape {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual std::string getName() = 0;  // Added to identify the shape by name
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getArea() {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() {
        return 2 * 3.14159 * radius;
    }

    std::string getName() {
        return "Circle";
    }
};

// Rectangle class
class Rectangle : public Shape {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    std::string getName() {
        return "Rectangle";
    }
};


class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}  

    std::string getName() {
        return "Square";
    }
};

class RightTriangle : public Shape {
protected:
    double base;
    double height;

public:
    RightTriangle(double b, double h) {
        base = b;
        height = h;
    }

    double getArea() {
        return 0.5 * base * height;
    }

    double getPerimeter() {
        double hypotenuse = sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }

    std::string getName() {
        return "Right Triangle";
    }
};


class IsoscelesRightTriangle : public RightTriangle {
public:
    IsoscelesRightTriangle(double leg) : RightTriangle(leg, leg) {}

    std::string getName() {
        return "Isosceles Right Triangle";
    }
};


void printAreaToScreen(Shape* s) {
    std::cout << "The area of the " << s->getName() << " is: " << s->getArea() << std::endl;
}

int main() {
    
    Circle c(1.0);
    assert(c.getArea() > 3.14 && c.getArea() < 3.15);
    assert(c.getPerimeter() > 6.28 && c.getPerimeter() < 6.29);
    printAreaToScreen(&c);

    
    Rectangle r(3.0, 4.0);
    assert(r.getArea() == 12.0);
    assert(r.getPerimeter() == 14.0);
    printAreaToScreen(&r);

    
    Square s(4.0);
    assert(s.getArea() == 16.0);
    assert(s.getPerimeter() == 16.0);
    printAreaToScreen(&s);

    
    RightTriangle t(3.0, 4.0);
    assert(t.getArea() == 6.0);
    assert(t.getPerimeter() > 11.99 && t.getPerimeter() < 12.01);
    printAreaToScreen(&t);

    
    IsoscelesRightTriangle it(4.0);
    assert(it.getArea() == 8.0);
    assert(it.getPerimeter() > 11.99 && it.getPerimeter() < 12.01);  // hypotenuse is 4 * sqrt(2)
    printAreaToScreen(&it);

    std::cout << "All tests passed.\n";
    return 0;
}

