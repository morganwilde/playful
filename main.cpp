#include <iostream>
// Controllers
#include "Controllers/Window.h"
#include "Controllers/CanvasController.h"
// Models
#include "Models/ShapeTriangle.h"
#include "Models/Circle.h"

int main(int argc, char *argv[])
{
    CanvasController canvasController = CanvasController(1200, 600, "A Playful Canvas");
    canvasController.arguments(&argc, argv);
    canvasController.setup();
    canvasController.show();

    return 0;
}
