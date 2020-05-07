#include "shape.h"

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
