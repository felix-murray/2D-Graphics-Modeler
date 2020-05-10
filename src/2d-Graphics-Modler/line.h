#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

class Line : public Shape
{
public:
    Line(QPaintDevice *device, int id);
    virtual ~Line() {};

    void setPoints(QPoint &x, QPoint &y) {line_begin = x; line_end = y;};

    void move(const int tX, const int tY, int ptIndex) override;
    void draw(QPaintDevice *device) override;
    //double perimeter() override;
    //double area() override;

private:
    QPoint line_begin;
    QPoint line_end;
};


#endif // LINE_H
