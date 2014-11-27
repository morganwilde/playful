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
    ShapeTriangle *triangle1 = new ShapeTriangle(Point(0, 400, 0), 800, 100);
    ShapeTriangle *triangle2 = new ShapeTriangle(Point(100, 200), Point(400, 200), Point(200, 500));
    Rectangle *rect1 = new Rectangle(Point(0, 0, 0), 200, 200);
    Rectangle *line = new Rectangle(Point(400, 0, 0), 20, 600);
    Circle *circle = new Circle(Point(400, 300), 200, 100);

    // Add color
    triangle1->color = Color(1, 0, 0, 1);
    triangle2->color = Color(0.5, 0, 0, 1);
    rect1->setColor(Color(0, 1, 0, 1));
    line->setColor(Color(0, 0, 1, 1));
    circle->setColor(Color(0.5, 0.5, 0.5, 1));

    /*
    window.shapesArray.add(triangle1);
    window.shapesArray.add(triangle2);
    window.shapesArray.add(rect1);
    window.shapesArray.add(line);
    */

    window.glutDisplayLoop();
    //window.glutDisplayFrame();
    //window.glutDisplayFrame();

    return 0;
}
