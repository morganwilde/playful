#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapesArray.h"
#include "ShapeTriangle.h"

class Rectangle : public ShapesArray
{
private:
	Point origin;
	double width;
	double height;
public:
    Rectangle(Point origin, double width, double height);
    ~Rectangle();
    std::string getShapesArrayType() const;
};

#endif