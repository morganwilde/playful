#include "Color.h"

Color::Color()
{
    this->setRed(1);
    this->setGreen(0);
    this->setBlue(0);
    this->setAlpha(0);
}
Color::Color(double red, double green, double blue, double alpha)
{
    this->setRed(red);
    this->setGreen(green);
    this->setBlue(blue);
    this->setAlpha(alpha);
}
Color::~Color()
{

}

// Setters
void Color::setRed(double red)
{
    this->red = red;
    this->colorArray[0] = this->getRed();
}
void Color::setGreen(double green)
{
    this->green = green;
    this->colorArray[1] = this->getGreen();
}
void Color::setBlue(double blue)
{
    this->blue = blue;
    this->colorArray[2] = this->getBlue();
}
void Color::setAlpha(double alpha)
{
    this->alpha = alpha;
    this->colorArray[3] = this->getAlpha();
}

// Functional setters
Color Color::withAlpha(double alpha)
{
    setAlpha(alpha);
    return *this;
}
Color Color::withHue(double hue)
{
    setRed(hue);
    setGreen(hue);
    setBlue(hue);
    return *this;
}

// Getters
double Color::getRed() const
{
    return this->red;
}
double Color::getGreen() const
{
    return this->green;
}
double Color::getBlue() const
{
    return this->blue;
}
double Color::getAlpha() const
{
    return this->alpha;
}

// Operators
std::ostream& operator<<(std::ostream &stream, const Color &color)
{
    stream << "Color( " << color.getRed() << " , " << color.getGreen() << " , " << color.getBlue() << " , " << color.getAlpha() << " )";
    return stream;
}

// Class methods
Color Color::redColor()
{
    return Color(1, 0, 0, 1);
}
Color Color::greenColor()
{
    return Color(0, 1, 0, 1);
}
Color Color::blueColor()
{
    return Color(0, 0, 1, 1);
}
Color Color::whiteColor()
{
    return Color(1, 1, 1, 1);
}
Color Color::grayColor()
{
    return Color(0.5, 0.5, 0.5, 1);
}
Color Color::blackColor()
{
    return Color(0, 0, 0, 1);
}