#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>
//#include <QPoint>

class Rectangle : public Shape
{
public:
    Rectangle(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, int X , int Y, int W, int H);
    ~Rectangle() override {}


    void draw(QPaintDevice *device) override;
    void move(int x, int y, int vector) override;
    double area() override;
    double perimeter() override;

    void setLocation(int x, int y);
    void setLocation(QPoint pt);
    void setDimensions(double w, double h);
    void setAll(double w, double h, int x, int y);

    double getWidth();
    double getHeight();
    QPoint& getLocation();

private:
	int x; 			  //added x, y 
	int y;
    double width;
    double height;
    QRectF rectangle; //added rectangle
    QPoint location;
};

#endif // RECTANGLE_H
