#include "Point.h"

Point::Point()
{
    this->setX(0);
    this->setY(0);
    this->setZ(0);
}

Point::Point(double x, double y, double z)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

Point::Point(double x, double y)
{
    this->setX(x);
    this->setY(y);
    this->setZ(0);
}

Point::~Point()
{

}

// Setters
void Point::setX(double x)
{
    this->x = x;
}
void Point::setY(double y)
{
    this->y = y;
}
void Point::setZ(double z)
{
    this->z = z;
}
// Getters
double Point::getX() const
{
    return this->x;
}
double Point::getY() const
{
    return this->y;
}
double Point::getZ() const
{
    return this->z;
}
// Operators

bool Point::operator==(const Point &pointForComparison)
{
    bool equal = true;
    if (this->getX() != pointForComparison.getX()) {
        equal = false;
    }
    if (this->getY() != pointForComparison.getY()) {
        equal = false;
    }
    if (this->getZ() != pointForComparison.getZ()) {
        equal = false;
    }
    return equal;
}

bool Point::operator!=(const Point &pointForComparison)
{
    return !(*this == pointForComparison);
}

std::ostream& operator<<(std::ostream &stream, const Point &point)
{
    stream << "Point( " << point.getX() << " , " << point.getY() << " , " << point.getZ() << " )";
    return stream;
}

std::istream& operator>>(std::istream &stream, Point &point)
{
    std::string prefix = "";
    std::string separator = "";
    std::string postfix = "";
    double inX = 0;
    double inY = 0;
    double inZ = 0;

    stream >> prefix;
    if (prefix == "Point(") {
        stream >> inX;
    }
    stream >> separator;
    if (separator == ",") {
        stream >> inY;
    }
    stream >> separator;
    if (separator == ",") {
        stream >> inZ;
    }

    point.setX(inX);
    point.setY(inY);
    point.setZ(inZ);

    return stream;
}
