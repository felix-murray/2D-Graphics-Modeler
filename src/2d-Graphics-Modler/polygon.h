#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

const int DEFAULT_NUM_VERTS = 8;
class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* dev = nullptr, int id = -1);
    ~Polygon() override {}

    virtual void draw(QPaintDevice *dev) override;
    virtual void move(int x, int y, int vertex) override;
    virtual double area() override;
    virtual double perimeter() override;

    void setNumVertices(int numVertices);
    int getNumVertices()const;
    void addVertex(const QPoint& vertex);
    Shape_Vector<QPoint>& getVertices();

private:
    Shape_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_NUM_VERTS];
    int     numVerts;
};

#endif // POLYGON_H
