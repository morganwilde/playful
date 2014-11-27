#ifndef SHAPETRIANGLE_H
#define SHAPETRIANGLE_H

#include "Shape.h"

class ShapeTriangle : public Shape
{
private:
    Point a1; // Origin
    Point a2;
    Point a3;
    double matrix[9];
    double determinant2D;
    double determinant3D;
    // Convenience methods
    void init(Point a1, Point a2, Point a3);
public:
    ShapeTriangle();
    ShapeTriangle(Point origin, double width, double height);
    ShapeTriangle(Point a1, Point a2, Point a3);
    ~ShapeTriangle();
    // Setters
    void setPointA1(Point a1);
    void setPointA2(Point a2);
    void setPointA3(Point a3);
    void setMatrix();
    void setDeterminant2D();
    void setDeterminant3D();
    // Getters
    Point getPointA1() const;
    Point getPointA2() const;
    Point getPointA3() const;
    double *getMatrix();
    double getDeterminant2D();
    double getDeterminant3D();
};

#endif
