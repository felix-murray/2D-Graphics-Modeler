#include "text.h"

void Text::draw(QPaintDevice *dev)
{
    QPainter painter(dev);
    painter.setFont(font);
    painter.drawText(location.x(), location.y(), text);
}

void Text::move(const int x, const int y, int junk)
{
    QPoint temp(x, y);
    location = temp;
}

double Text::area()
{
    double boxArea = boxWidth * boxHeight;
    return boxArea;
}

double Text::perimeter()
{
    double boxPerimeter = (2*boxWidth) + (2*boxHeight);
    return boxPerimeter;
}

void Text::setText(QString newText)
{
    text = newText;
}

void Text::setBoxWidth(int newBoxWidth)
{
    boxWidth = newBoxWidth;
}

void Text::setBoxHeight(int newBoxHeight)
{
    boxHeight = newBoxHeight;
}

void Text::setFlag(Qt::AlignmentFlag flagParam)
{
    flag = flagParam;
}

void Text::setLocation(int x, int y)
{
    location.setX(x);
    location.setY(y);
}

void Text::setLocation(QPoint pt)
{
    location = pt;
}

void Text::setDimensions(int w, int h)
{
    boxWidth = w;
    boxHeight = h;
}

QFont& Text::getFont()
{
    return font;
}

Qt::AlignmentFlag Text::getFlag()
{
    return flag;
}

QString Text::getText()
{
    return text;
}
