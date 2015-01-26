#include <iostream>
// Controllers
#include "Controllers/Window.h"
#include "Controllers/CanvasController.h"
// Models
#include "Models/ShapeTriangle.h"
#include "Models/Circle.h"
#include "Models/Rectangle.h"

int main(int argc, char *argv[])
{
    CanvasController canvasController = CanvasController(1000, 600, "A Playful Canvas");
    canvasController.arguments(&argc, argv);
    canvasController.setup();

    // Add temporary visual objects
    Circle *circle = new Circle(Point(400, 300), 200);
    circle->setRespondsToMouseButtonDown(true);
    circle->setColor(Color::redColor());
    canvasController.getCanvasArea()->add(circle);

    
    Rectangle *rect = new Rectangle(Point(300, 200), 200, 200);
    rect->setColor(Color::blackColor());
    rect->setRespondsToMouseButtonDown(true);
    circle->add(rect);

    canvasController.saveToStorage("data");
    canvasController.loadFromStorage("data");

    canvasController.show();

    return 0;
}