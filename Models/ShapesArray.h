#ifndef SHAPESARRAY_H
#define SHAPESARRAY_H

#include "Shape.h"
#include <OpenGL/gl.h>

class ShapesArray
{
private:
    int shapeCount;
    Shape **array;
    int vertexCount;
    // Window size
    int width;
    int height;
public:
    ShapesArray();
    ~ShapesArray();
    // Setters
    void setSize(int width, int height);
    // Getters
    int getShapeCount();
    Shape **getShapeArray();
    GLfloat *getVertexArray();
    GLfloat *getColorArray();
    int getVertexCount();
    Shape *shapeContaining(Point point);
    // Array managers
    void add(Shape *shape);
};

#endif
