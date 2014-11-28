#ifndef SHAPESARRAY_H
#define SHAPESARRAY_H

#include "Shape.h"
#include "ShapeTriangle.h"
#include <OpenGL/gl.h>

class ShapesArray
{
private:
    // Shapes made out of Points
    int shapeCount;
    Shape **array;
    // Shapes made out of other Shapes
    int compositeCount;
    ShapesArray **compositeArray;
    // Vertices derived from shapes and composites arrays
    int vertexCount;
    // Window size
    int width;
    int height;
    Color color;
    // First responder to mouse button down events
    bool respondsToMouseButtonDown;
public:
    ShapesArray();
    ~ShapesArray();
    // Setters
    void setSize(int width, int height);
    void setColor(Color color);
    void setSespondsToMouseButtonDown(bool responds);
    // Getters
    int getWidth();
    int getHeight();
    int getShapeCount();
    Shape **getShapeArray();
    int getCompositeCount();
    ShapesArray **getCompositeArray();
    GLfloat *getVertexArray();
    GLfloat *getColorArray();
    int getVertexCount();
    Color getColor();
    bool getRespondsToMouseButtonDown();
    // Convenience methods
    ShapeTriangle *shapeContaining(Point point);
    ShapesArray *compositeResponder(ShapeTriangle *triangle);
    // Array managers
    void add(Shape *shape);
    void add(ShapesArray *shapesArray);
    void remove(Shape *shape);
    void remove(ShapesArray *shapesArray);
};

#endif
