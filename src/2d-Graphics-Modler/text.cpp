#include "text.h"

Text::Text(QPaintDevice *dev, int id)
     :Shape(dev, id, Shapes::TextObj), location(0,0)
{
    text = "Default text Please Ignore.";
}


void Text::draw(QPaintDevice *dev)
{
    QPainter painter(dev);
    painter.setFont(font);
    painter.setPen(getPen());
    painter.drawText(location.x(), location.y(), boxWidth, boxHeight, flag, text);
    painter.end();
}

void Text::move(const int x, const int y, int junk)
{
    QPoint temp(x, y);
    location = temp;
}

double Text::area()
{
    return boxWidth * boxHeight;
}

double Text::perimeter()
{
    return (2*boxWidth) + (2*boxHeight);
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
