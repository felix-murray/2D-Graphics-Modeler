#include "rectangle.h"

void Rectangle::draw(QPaintDevice *device)
{
    QRectF rectangle(10.0, 20.0, 80.0, 60.0);
    QPainter painter(device);
    //painter.begin(device);
    painter.drawRect(rectangle);
    //painter.end();
}

void Rectangle::move(int x, int y, int vector)
{
//...
}

double Rectangle::area()
{
//...
}

double Rectangle::perimeter()
{
//...
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

double Rectangle::getWidth()
{
//...
}

double Rectangle::getHeight()
{
//...
}

QPoint& Rectangle::getLocation()
{
//...
}
