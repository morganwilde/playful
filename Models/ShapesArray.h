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
    GLfloat *getVertexArray();
    GLfloat *getColorArray();
    int getVertexCount();
    Color getColor();
    Shape *shapeContaining(Point point);
    // Array managers
    void add(Shape *shape);
    void add(ShapesArray *shapesArray);    
};

#endif
