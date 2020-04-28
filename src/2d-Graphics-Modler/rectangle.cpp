#include "rectangle.h"

//drawing the rectangle on the drawing area
void Rectangle::draw(QPaintDevice *device)
{
    //initialized the width, height, and rectangle
    width = 80;
    height = 60;
    rectangle = {10.0, 20.0, width, height};
    //drew the rectangle on the drawing area
    QPainter painter(device);
    //painter.begin(device);
    painter.drawRect(rectangle);
    //painter.end();
}

//move the rectangle
void Rectangle::move(int x, int y, int vector)
{
    //rectangle = {double (x), double(y), width, height};
    //QPainter painter(device);
    //painter.translate(rectangle);
}

//return the area of the rectangle
double Rectangle::area()
{
    double area;
    area = width * height;
    return area;
}

//return the perimeter of the rectangle
double Rectangle::perimeter()
{
    double perimeter;
    perimeter = 2*(width + height);
    return perimeter;
}

void Rectangle::setLocation(int x, int y)
{
//...
}

void Rectangle::setLocation(QPoint pt)
{
//...
}
void Rectangle::setDimensions(double w, double h)
{
//...
}

void Rectangle::setAll(double w, double h, int x, int y)
{
//...
}

//return width of the rectangle
double Rectangle::getWidth()
{
    return width;
}

//return height of the rectangle
double Rectangle::getHeight()
{
    return height;
}

QPoint& Rectangle::getLocation()
{
//...
}
