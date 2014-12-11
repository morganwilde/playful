#include <iostream>
// Controllers
#include "Controllers/Window.h"
// Models
#include "Models/ShapeTriangle.h"
#include "Models/Rectangle.h"
#include "Models/Circle.h"

int main(int argc, char *argv[])
{
    Window &window = Window::getSingleton(800, 600, "Title");
    window.glutInitWrapper(&argc, argv);

    // Add shapes
    Rectangle *rect1 = new Rectangle(Point(220, 0, 0), 200, 200);
    Rectangle *rect2 = new Rectangle(Point(220, 0, 0), 200, 200);
    Rectangle *rect3 = new Rectangle(Point(220, 0, 0), 200, 200);
    Rectangle *rect4 = new Rectangle(Point(10, 10, 0), 200, 200);
    Circle *circle = new Circle(Point(400, 300), 200, 20);
    Circle *control1 = new Circle(Point(10, 10), 10);
    Circle *control2 = new Circle(Point(210, 10), 10);
    Circle *control3 = new Circle(Point(10, 210), 10);
    Circle *control4 = new Circle(Point(210, 210), 10);

    // Event responders
    circle->setRespondsToMouseButtonDown(true);
    rect1->setRespondsToMouseButtonDown(true);
    rect2->setRespondsToMouseButtonDown(true);
    rect3->setRespondsToMouseButtonDown(true);
    rect4->setRespondsToMouseButtonDown(true);

    // Add color
    rect1->setColor(Color(0, 1, 0, 1));
    Color blue = Color(0, 174/255.0, 239/255.0, 0.15);
    control1->setColor(blue);
    control2->setColor(blue);
    control3->setColor(blue);
    control4->setColor(blue);
    // Control points
    rect2->setColor(Color(0, 0.8, 0, 1));
    rect3->setColor(Color(0, 0.6, 0, 1));
    rect4->setColor(Color(137/255.0, 137/255.0, 137/255.0, 1));
    circle->setColor(Color(0.5, 0.5, 0.5, 1));
    
    // Add to hierarchy
    window.shapesArray.add(rect1);
    window.shapesArray.add(rect4);
    window.shapesArray.add(control1);
    window.shapesArray.add(control2);
    window.shapesArray.add(control3);
    window.shapesArray.add(control4);
    // Control points
    window.shapesArray.add(rect2);
    window.shapesArray.add(rect3);
    window.shapesArray.add(circle);

    window.glutDisplayLoop();

    return 0;
}
