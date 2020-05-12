#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent)
      : QWidget(parent), ShapeMagazine(10)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(sizeHint());
    numShapesRA = 0;
    //readShapeFile();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPaintDevice* device = this;
    for(int i = 0; i < ShapeMagazine.size(); i++)
        ShapeMagazine[i]->draw(device);
}

const Shape_Vector<Shape *> & RenderArea::getShapes()
{
    return ShapeMagazine;
}

void RenderArea::addShape(Shape* shapeIn)
{
    ShapeMagazine.push_back(shapeIn);
    numShapesRA++;
    //shapeIn->draw(this);
}
void RenderArea::chopShape(int indexRemove)
{
    Shape_Vector<Shape*>::iterator i;
    for(i = ShapeMagazine.begin(); i < ShapeMagazine.end(); ++i)
        if((*i)->getID() == indexRemove)
        {
            ShapeMagazine.erase(i);
            numShapesRA--;
            break;
        }
}
void RenderArea::moveShape(int index, int coord, int x, int y)
{
    for(int i = 0; i < ShapeMagazine.size(); i++)
        if(ShapeMagazine[i]->getID() == index){
            ShapeMagazine[i]->move(x,y,coord); break; }
}
int RenderArea::getSize()
{
    return ShapeMagazine.size();
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000,500);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(1000,500);
}

int RenderArea::getnumShapesRA()
{
    return numShapesRA;
}

Shape::Shapes RenderArea::getShapeType(QString shapeStr)
{
    if(shapeStr == "Line")
        return Shape::Shapes::LineObj;
    else if(shapeStr == "Polyline")
        return Shape::Shapes::PolylineObj;
    else if(shapeStr == "Polygon")
        return Shape::Shapes::PolygonObj;
    else if(shapeStr == "Rectangle")
        return Shape::Shapes::RectangleObj;
    else if(shapeStr == "Ellipse")
        return Shape::Shapes::EllipseObj;
    else if(shapeStr == "Text")
        return Shape::Shapes::TextObj;
    else
        return Shape::Shapes::defaultObj;

}

Qt::GlobalColor RenderArea::getColor(QString colorStr)
{
    if(colorStr == "blue")
        return Qt::blue;
    else if(colorStr == "red")
        return Qt::red;
    else if(colorStr == "green")
        return Qt::green;
    else if(colorStr == "yellow")
        return Qt::yellow;
    else if(colorStr == "black")
        return Qt::black;
    else if(colorStr == "white")
        return Qt::white;
    else if(colorStr == "cyan")
        return Qt::cyan;
    else if(colorStr == "magenta")
        return Qt::magenta;
    else
        return Qt::gray;
}

Qt::PenCapStyle RenderArea::getPenCapStyle(QString capStr)
{

    if(capStr == "SquareCap")
        return Qt::SquareCap;
    else if(capStr == "FlatCap")
        return Qt::FlatCap;
    else
        return Qt::RoundCap;
}

Qt::PenStyle RenderArea::getPenStyle(QString penStr)
{
    if(penStr == "NoPen")
        return Qt::NoPen;
    else if(penStr == "SolidLine")
        return Qt::SolidLine;
    else if(penStr == "DashLine")
        return Qt::DashLine;
    else if(penStr == "DotLine")
        return Qt::DotLine;
    else if(penStr == "DashDotLine")
        return Qt::DashDotLine;
    else
        return Qt::DashDotDotLine;
}

Qt::PenJoinStyle RenderArea::getPenJointStyle(QString penJointStr)
{
    if(penJointStr == "MiterJoin")
        return Qt::MiterJoin;
    else if(penJointStr == "BevelJoin")
        return Qt::BevelJoin;
    else
        return Qt::RoundJoin;
}

Qt::BrushStyle RenderArea::getBrushStyle(QString brushStr)
{
    if(brushStr == "SolidPattern")
        return Qt::SolidPattern;
    else if(brushStr == "HorPattern")
        return Qt::HorPattern;
    else if(brushStr == "VerPattern")
        return Qt::VerPattern;
    else
        return Qt::NoBrush;
}

Qt::AlignmentFlag RenderArea::getFlag(QString flagStr)
{
    if(flagStr == "AlignLeft")
        return Qt::AlignLeft;
    else if(flagStr == "AlignRight")
        return Qt::AlignRight;
    else if(flagStr == "AlignTop")
        return Qt::AlignTop;
    else if(flagStr == "AlignBottom")
        return Qt::AlignBottom;
    else
        return Qt::AlignCenter;
}

QFont::Style RenderArea::getFontStyle(QString fontStyleStr)
{
    if(fontStyleStr == "StyleNormal")
        return QFont::StyleNormal;
    else if(fontStyleStr == "StyleItalic")
        return QFont::StyleItalic;
    else
        return QFont::StyleOblique;
}

QFont::Weight RenderArea::getFontWeight(QString fontWeightStr)
{
    if(fontWeightStr == "Thin")
        return QFont::Thin;
    else if(fontWeightStr == "Light")
        return QFont::Light;
    else if(fontWeightStr == "Normal")
        return QFont::Normal;
    else
        return QFont::Bold;
}

QString RenderArea::getStringColor(QColor color)
{
    if(color == Qt::blue)
        return "blue";
    else if(color == Qt::red)
        return "red";
    else if(color == Qt::green)
        return "green";
    else if(color == Qt::yellow)
        return "yellow";
    else if(color == Qt::black)
        return "black";
    else if(color == Qt::white)
        return "white";
    else if(color == Qt::cyan)
        return "cyan";
    else if(color == Qt::magenta)
        return "magenta";
    else
        return "gray";
}


QString RenderArea::getStringPenCap(Qt::PenCapStyle penStyle)
{
    if(penStyle == Qt::FlatCap)
        return "FlatCap";
    else if(penStyle == Qt::SquareCap)
        return "SquareCap";
    else
        return "RoundCap";
}

QString   RenderArea::getStringPenStyle(Qt::PenStyle penStyle)
{
    if(penStyle == Qt::NoPen)
        return "NoPen";
    else if(penStyle == Qt::SolidLine)
        return "SolidLine";
    else if(penStyle == Qt::DashLine)
        return "DashLine";
    else if(penStyle == Qt::DotLine)
        return "DotLine";
    else if(penStyle == Qt::DashDotLine)
        return "DashDotLine";
    else
        return "DashDotDotLine";
}

QString RenderArea::getStringPenJointStyle(Qt::PenJoinStyle penJointStyle)
{
    if(penJointStyle == Qt::MiterJoin)
        return "MiterJoin";
    else if(penJointStyle == Qt::BevelJoin)
        return "BevelJoin";
    else
        return "RoundJoin";
}

QString RenderArea::getStringBrush(Qt::BrushStyle brush)
{
    if(brush == Qt::SolidPattern)
        return "SolidPattern";
    else if(brush == Qt::HorPattern)
        return "HorPattern";
    else if(brush == Qt::VerPattern)
        return "VerPattern";
    else
        return "NoBrush";
}

QString RenderArea::getStringFlag(Qt::AlignmentFlag  flag)
{
    if(flag == Qt::AlignLeft )
        return "AlignLeft";
    else if(flag == Qt::AlignRight)
        return "AlignRight";
    else if(flag == Qt::AlignTop)
        return "AlignTop";
    else if(flag == Qt::AlignBottom)
        return "AlignBottom";
    else
        return "AlignCenter";
}

 QString RenderArea::getStringFontStyle(QFont::Style fontStyle)
{
    if(fontStyle == QFont::StyleNormal)
        return "StyleNormal";
    else if(fontStyle == QFont::StyleItalic)
        return "StyleItalic";
    else
        return "StyleOblique";
}

QString RenderArea::getStringFontWeight(int fontWeight)
{
    if(fontWeight == 0)
        return "Thin";
    else if(fontWeight == 25)
        return "Light";
    else if(fontWeight == 50)
        return "Normal";
    else
        return "Bold";
}

























