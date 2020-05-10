#include "shape.h"

Shape::Shape(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS)
{
    switch(PS)
    {
        case 0:  pen.setStyle(SolidLine);
        break;
        case 1:  pen.setStyle(DashLine);
        break;
        case 2:  pen.setStyle(DotLine);
        break;
        case 3:  pen.setStyle(DashDotLine);
        break;
        case 4:  pen.setStyle(DashDotDotLine);
        break;
        default: pen.setStyle(NoPen);
        break;

    }

    pen.setWidth(PW);

    switch(PC)
    {
        case 0:  pen.setColor(white);
        break;
        case 1:  pen.setColor(black);
        break;
        case 2:  pen.setColor(red);
        break;
        case 3:  pen.setColor(green);
        break;
        case 4:  pen.setColor(blue);
        break;
        case 5:  pen.setColor(cyan);
        break;
        case 6:  pen.setColor(magenta);
        break;
        case 7:  pen.setColor(yellow);
        break;
        default: pen.setColor(gray);
        break;
    }

    switch(PCS)
    {
        case 0: pen.setCapStyle(SquareCap);
        break;
        case 1: pen.setCapStyle(FlatCap);
        break;
        case 2: pen.setCapStyle(RoundCap);
        break;
        default: pen.setCapStyle(SquareCap);
        break;
    }

    switch(PJS)
    {
        case 0: pen.setJoinStyle(BevelJoin);
        break;
        case 1: pen.setJoinStyle(MiterJoin);
        break;
        case 2: pen.setJoinStyle(RoundJoin);
        break;
        default: pen.setJoinStyle(BevelJoin);
        break;

    }

    switch(BC)
    {
        case 0:  brush.setColor(white);
        break;
        case 1:  brush.setColor(black);
        break;
        case 2:  brush.setColor(red);
        break;
        case 3:  brush.setColor(green);
        break;
        case 4:  brush.setColor(blue);
        break;
        case 5:  brush.setColor(cyan);
        break;
        case 6:  brush.setColor(magenta);
        break;
        case 7:  brush.setColor(yellow);
        break;
        default: brush.setColor(gray);
        break;
    }

    switch(BS)
    {
        case 0: brush.setStyle(SolidPattern);
        break;
        case 1: brush.setStyle(HorPattern);
        break;
        case 2: brush.setStyle(VerPattern);
        break;
        default: brush.setStyle(NoBrush);
        break;
    }
}


void Shape::setShape(Shapes st)
{
    this->shape=st;
}

void Shape::setBrush(Qt::GlobalColor gc, Qt::BrushStyle bs)
{
    brush=QBrush(gc, bs);
}

void Shape::setPen(Qt::GlobalColor gc)
{
    pen=QPen(gc);
}

void Shape::setPen(Qt::GlobalColor gc, int width, Qt::PenStyle ps, Qt::PenCapStyle pcs, Qt::PenJoinStyle pjs)
{
    pen=QPen(gc, width, ps, pcs, pjs);
}

void Shape::setDefaultStyle()
{
    pen=Qt::SolidLine;
    brush=Qt::NoBrush;
    painter.setPen(Qt::SolidLine);
    painter.setBrush(Qt::NoBrush);
}

QPainter &Shape::getQPainter()
{
    return painter;
}
