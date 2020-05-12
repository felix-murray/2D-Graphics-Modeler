#include "line.h"

Line::Line(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, QPoint P1, QPoint P2)
     : Shape(PS, PW, PC, PCS, PJS, BC, BS)
{
    line_begin = P1;
    line_end = P2;
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
    painter.drawText(line_begin,QString::number(getID()));
    painter.end();
}

double Line::perimeter()
{
    return 0;
}

double Line::area()
{
    return 0;
}
