#include "shape.h"
#include "ellipse.h"
#include "math.h"
#include "QDebug"


Ellipse::Ellipse(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, int X , int Y, int W, int H)
        :Shape(PS, PW, PC, PCS, PJS, BC, BS)
{
    location.setX(X);
    location.setY(Y);
    width = W;
    height = H;
}


void Ellipse::move(int x, int y, int na)
{
    QPoint temp(x,y);
    location = temp;
}

void Ellipse::draw(QPaintDevice* device)
{
    painter.begin(device);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
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
return 3 * M_PI * (width + height) - sqrt((3 * width + height) * (width + 3 * height));
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
        qDebug() << "ERROR: Width and height cannot be negative";
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
