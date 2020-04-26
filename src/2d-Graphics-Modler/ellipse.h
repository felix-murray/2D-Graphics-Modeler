#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1);
    ~Ellipse() override {}

    void move(int x, int y, int na) override;
    void draw(QPaintDevice* device) override;

    double area() override;
    double perimeter() override;

    double getWidth();
    double getHeight();
    QPoint& getLocation();

    void setDimensions(double w, double h);
    void setLocation(int x, int y);
    void setLocation(QPoint pt);

private:
    double width;
    double height;
    QPoint location;
};

#endif // ELLIPSE_H
