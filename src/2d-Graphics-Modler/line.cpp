#include "line.h"

Line::Line(QPaintDevice *device, int id)
     : Shape(device, id, Shape::LineObj), line_begin(1,1), line_end(1,1)
{
    setShape(LineObj);
}

void Line::move(const int tX, const int tY, int ptIndex)
{
 QPoint temp(tX, tY);
    switch(ptIndex)
    {
        case 1: line_begin = temp;
            break;
        case 2:   line_end = temp;
            break;
        default: {}
    }
}

void Line::draw(QPaintDevice *device)
{
    painter.begin(device);
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawLine(line_begin, line_end);
    painter.end();
}
