#ifndef SHAPESARRAY_H
#define SHAPESARRAY_H

#include "Shape.h"
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
public:
    ShapesArray();
    ~ShapesArray();
    // Setters
    void setSize(int width, int height);
    void setColor(Color color);
    // Getters
    int getShapeCount();
    Shape **getShapeArray();
    int getCompositeCount();
    ShapesArray **getCompositeArray();
    GLfloat *getVertexArray();
    GLfloat *getColorArray();
    int getVertexCount();
    Color getColor();
    Shape *shapeContaining(Point point);
    // Array managers
    void add(Shape *shape);
    void add(ShapesArray *shapesArray);
    void remove(Shape *shape);
    void remove(ShapesArray *shapesArray);
};

#endif
