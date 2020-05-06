#include "ellipse.h"

Ellipse::Ellipse(QPaintDevice *dev, int id) : Shape(dev, id, ShapeType::Ellipse), location(1,1)
{
    width = 1;
    height = 1;
}

void Ellipse::move(int x, int y, int na)
{
    QPoint temp(x,y);
    location = temp;
}

void Ellipse::draw(QPaintDevice* device)
{
    painter.begin(device);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(location.x(), location.y(), width, height);
    painter.drawText(location,QString::number(getID()));
    painter.end();
}

double Ellipse::area()
{
    return width * height * M_PI;
}

double Ellipse::perimeter()
{
return 3 * M_PI * (width + height) - qSqrt((3 * width + height) * (width + 3 * height));
}

double Ellipse::getWidth()
{
    return width;
}

double Ellipse::getHeight()
{
    return height;
}

QPoint& Ellipse::getLocation()
{
    return location;
}

void Ellipse::setDimensions(double w, double h)
{
    if(w > 0 && h > 0)
    {
        width  = w;
        height = h;
    }
    else
    {
        qDebug() << "Width and height have to be positive";
    }
}

void Ellipse::setLocation(int x, int y)
{
    QPoint temp(x, y);
    location  = temp;
}

void Ellipse::setLocation(QPoint pt)
{
    location = pt;
}
