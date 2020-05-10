#include "text.h"


 Text::Text(QString T, int TC, int F, int align, int S, int W, int boxW, int boxH, QPoint Loc)
      :Shape(TC)
 {
    text = T;

    switch(F)
    {
        case 0: font.setFamily("Comic Sans MS");
        break;
        case 1: font.setFamily("Courier");
        break;
        case 2: font.setFamily("Helvetica");
        break;
        default: font.setFamily("Times");
        break;
    }

    switch(align)
    {
        case 0: flag = AlignLeft;
        break;
        case 1: flag = AlignCenter;
        break;
        case 2: flag = AlignRight;
        break;
        case 3: flag = AlignTop;
        break;
         case 4: flag = AlignBottom;
        break;
        default: flag = AlignLeft;
        break;
    }

    switch(S)
    {
        case 0:
        break;
        case 1: font.setItalic(1);
        break;
        case 2: font.setBold(1);
        break;
        default:
        break;
    }

    switch(W)
    {
        case 0: font.setWeight(0);
        break;
        case 1: font.setWeight(25);
        break;
        case 2: font.setWeight(50);
        break;
        case 3: font.setWeight(75);
        break;
        default: font.setWeight(50);
        break;
    }

    boxWidth = boxW;
    boxHeight = boxH;

    location = Loc;
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
