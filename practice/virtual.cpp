#include <iostream>

class Shape
{
public:
    virtual void draw() = 0;
    virtual void print(){std::cout << "Virtual function in Shape" << std::endl;}
    void say(){std::cout << "Normal function in Shape" << std::endl;}
};

class Circle : public Shape
{
public:
    virtual void draw(){std::cout << "Drawing a Circle" << std::endl;}
    virtual void print(){std::cout << "Virtual function in Circle" << std::endl;}
    void say(){std::cout << "Normal function in Circle" << std::endl;}
};

int main()
{
    std::cout << "Calling functions on Circle"<< std::endl;
    Circle circle;
    circle.draw();
    circle.print();
    circle.say();
    std::cout << std::endl;

    std::cout << "Calling functions on Shape * shape = & circle"<< std::endl;
    Shape * shape = & circle;
    shape->draw();
    shape->print();
    shape->say();
    return 0;
}
