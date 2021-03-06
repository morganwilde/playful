#include "ShapeTriangle.h"

void ShapeTriangle::init(Point a1, Point a2, Point a3)
{
    /* Designated initialiser */

    // Set anchor points
    this->setPointA1(a1);
    this->setPointA2(a2);
    this->setPointA3(a3);

    // Add them to the point array
    pushToPointArray(getPointA1());
    pushToPointArray(getPointA2());
    pushToPointArray(getPointA3());
}

ShapeTriangle::ShapeTriangle()
{
    // Convenience constructor
    Shape::Shape();
}

ShapeTriangle::ShapeTriangle(Point a1, Point a2, Point a3)
{
    // Designated constructor
    Shape::Shape();
    init(a1, a2, a3);
}

ShapeTriangle::ShapeTriangle(Point origin, double width, double height)
{
    // Convenience constructor
    Shape::Shape();
    Point top = Point(origin.getX(), origin.getY() + height, origin.getZ());
    Point right = Point(origin.getX() + width, origin.getY(), origin.getZ());
    init(origin, top, right);
}

ShapeTriangle::~ShapeTriangle()
{

}

// Setters
void ShapeTriangle::setPointA1(Point a1)
{
    this->a1 = a1;
    setMatrix();
}
void ShapeTriangle::setPointA2(Point a2)
{
    this->a2 = a2;
    setMatrix();
}
void ShapeTriangle::setPointA3(Point a3)
{
    this->a3 = a3;
    setMatrix();
}
void ShapeTriangle::setMatrix()
{
    matrix[0] = getPointA1().getX() - getPointA3().getX();
    matrix[1] = getPointA2().getX() - getPointA3().getX();
    matrix[2] = 0; // TODO: implement
    matrix[3] = getPointA1().getY() - getPointA3().getY();
    matrix[4] = getPointA2().getY() - getPointA3().getY();
    matrix[5] = 0; // TODO: implement
    matrix[6] = 0; // TODO: implement
    matrix[7] = 0; // TODO: implement
    matrix[8] = 0; // TODO: implement
    setDeterminant2D();
    setDeterminant3D();
}
void ShapeTriangle::setDeterminant2D()
{
    this->determinant2D = (matrix[0] * matrix[4]) - (matrix[1] * matrix[3]);
}
void ShapeTriangle::setDeterminant3D()
{
    this->determinant3D = 0; // TODO: implement
}
// Getters
Point ShapeTriangle::getPointA1() const
{
    return this->a1;
}
Point ShapeTriangle::getPointA2() const
{
    return this->a2;
}
Point ShapeTriangle::getPointA3() const
{
    return this->a3;
}
double *ShapeTriangle::getMatrix()
{
    return this->matrix;
}
double ShapeTriangle::getDeterminant2D()
{
    return this->determinant2D;
}
double ShapeTriangle::getDeterminant3D()
{
    return this->determinant3D;
}
// Methods
bool ShapeTriangle::pointContained(Point point)
{
    // Calculate barycentric coordinates
    const double lambda1 = (
            (getPointA2().getY() - getPointA3().getY()) *
            (point.getX() - getPointA3().getX())
        + 
            (getPointA3().getX() - getPointA2().getX()) *
            (point.getY() - getPointA3().getY())
        ) / getDeterminant2D();
    const double lambda2 = (
            (getPointA3().getY() - getPointA1().getY()) *
            (point.getX() - getPointA3().getX())
        +
            (getPointA1().getX() - getPointA3().getX()) *
            (point.getY() - getPointA3().getY())
        ) / getDeterminant2D();
    const double lambda3 = 1 - lambda1 - lambda2;

    // For a point to be inside a triangle, all lambdas must be >= 0
    return (lambda1 >= 0) && (lambda2 >= 0) && (lambda3 >= 0);
}
void ShapeTriangle::translateBy(double x, double y)
{
    popFromPointArray();
    popFromPointArray();
    popFromPointArray();

    //std::cout << getPointA1() << std::endl;
    setPointA1(Point(getPointA1().getX() + x, getPointA1().getY() + y, getPointA1().getZ()));
    setPointA2(Point(getPointA2().getX() + x, getPointA2().getY() + y, getPointA2().getZ()));
    setPointA3(Point(getPointA3().getX() + x, getPointA3().getY() + y, getPointA3().getZ()));
    //std::cout << getPointA1() << std::endl;

    pushToPointArray(getPointA1());
    pushToPointArray(getPointA2());
    pushToPointArray(getPointA3());
}
