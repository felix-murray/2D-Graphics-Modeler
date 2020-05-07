#include "rectangle.h"

Rectangle::Rectangle(QPaintDevice *device, int id)
          :Shape(device, id, Shapes::RectangleObj),location(0,0)
{
    width = 1;
    height = 1;
}

//drawing the rectangle on the drawing area
void Rectangle::draw(QPaintDevice *device)
{

    painter.begin(device);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawRect(location.x(), location.y(), width, height);
    //painter.drawText(location, QString::number(getID()));
    painter.end();


}

//move the rectangle
void Rectangle::move(int x, int y, int vector)
{

    QPoint temp(x , y);
    location = temp;

}

//return the area of the rectangle
double Rectangle::area()
{
    return width * height;
}

//return the perimeter of the rectangle
double Rectangle::perimeter()
{
    return 2*(width + height);
}

void Rectangle::setLocation(int x, int y)
{
    QPoint temp(x , y);
    location = temp;
}

void Rectangle::setLocation(QPoint pt)
{
	location = pt;
}
void Rectangle::setDimensions(double w, double h)
{
    // DONT BE STUPID AND PUT A NEGATIVE NUMBER !!!!!!

	width = w;
	height = h;
}

void Rectangle::setAll(double w, double h, int x, int y)
{
    setDimensions(w, h);
    setLocation(x, y);
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
