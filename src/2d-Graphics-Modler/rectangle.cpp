#include "rectangle.h"

//drawing the rectangle on the drawing area
void Rectangle::draw(QPaintDevice *device)
{
    //initialized the width, height, and rectangle
	x = 10;
	y = 20;
    width = 80;
    height = 60;
    location = {x, y};
    rectangle.setRect(x, y, width, height);
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
	location = {x, y};
}

void Rectangle::setLocation(QPoint pt)
{
	location = pt;
}
void Rectangle::setDimensions(double w, double h)
{
	width = w;
	height = h;
}

void Rectangle::setAll(double w, double h, int x, int y)
{
	width = w;
	height = h;
	this->x = x;
	this->y = y;
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
	return location;
}
