#ifndef SHAPE_H_
#define SHAPE_H_

#include <QObject>
#include <QPaintDevice>
#include <QPainter>

using namespace Qt;

class Shape : public QPainter
{
public:
    enum Shapes{defaultObj,
                      LineObj,
                      PolylineObj,
                      PolygonObj,
                      RectangleObj,
                      EllipseObj,
                      TextObj};

    Shape(QPaintDevice *device, int ID, Shapes shape) {device = nullptr, ID = -1, shape = Shapes::defaultObj;}

    //Mutator Functions
    void setShape(Shapes);
    void setBrush(GlobalColor, BrushStyle);
    void setPen(GlobalColor);
    void setPen(GlobalColor, int width, PenStyle, PenCapStyle, PenJoinStyle);
    void setBrush(QBrush brsh);
    void setPen(QPen pn);
    void setID(int ID);
    void setDefaultStyle();

    //Accessor Functions
    Shapes getShape() const {return shape;}
    const QBrush &getBrush() const {return brush;}
    const QPen &getPen() const {return pen;}
    int getID() const {return id;}

    //Virtual Functions
    virtual ~Shape(){}
    virtual void move(const int tX, const int tY, int ptIndex) = 0;
    virtual void draw(QPaintDevice *device) = 0;
    virtual double perimeter() = 0;
    virtual double area() = 0;

 protected:
     QPainter &getQPainter();
     QPainter painter;
     Shapes shape;

 private:
     int id;
     QPen pen;
     QBrush brush;
};

#endif // SHAPE_H
