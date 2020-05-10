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

    //Donstructor of the polygon class
    //Parameters: QPaintDevice* dev = nullptr
    //            int id = -1
    //Postcondition: Shape(device, id, Shape::shape) 
    //               vertVect(DEFAULT_NUM_VERTS)
    //               setShape(PolygonObj);
    //               numVerts = 0;
    Polygon(QPaintDevice* dev = nullptr, int id = -1);
    
    //Destructor of the polygon class
    //Perameters: N/A
    //Postcondition: N/A
    ~Polygon() override {}

    //Function that draws the polygon shape
    //Perameters: QPaintDevice *dev
    //Postcondition: painter.begin(device);
    //               painter.setPen(getPen());
    //               painter.setBrush(getBrush());
    //               painter.drawConvexPolygon(vertsArray, numVerts);
    //               painter.drawText(vertsArray[0] ,QString::number(getID()));
    //               painter.end();
    virtual void draw(QPaintDevice *dev) override;

    //Function that moves a specific vertex to a different
    //x and y coordinate.
    //Perameters: int x : the new X-coordinate for the vertex
    //            int y : the new Y-coordinate for the vextex
    //            int vertex : the new 
    //Postcondition: vertVect.set(vertex - 1, temp);
    //               vertsArray[vertex - 1] = temp;
    virtual void move(int x, int y, int vertex) override;
    
    //Function that calculates the area of the polygon.
    //Perameters: N/A
    //Postcondition: return area;
    virtual double area() override;

    //Function that calculates the perimeter of the polygon.
    //Perameters: N/A
    //Postcondition: return perimeter;
    virtual double perimeter() override;

    //Function that sets the number of vertices that the
    //polygon has.
    //Perameters: int numVertices : the new number of vertices in the polygon.
    //Postcondition: numVerts = numVertices
    void setNumVertices(int numVertices);

    //Function that returns the number of vertices to the user.
    //Perameters: N/A
    //Postcondtion: return numVerts;
    int getNumVertices()const;

    //Function that adds a vertex to the polygon.
    //Perameters: const QPoint& vertex : the new vertex to be added to polygon
    //Postcondition: vertVect.push_back(vertex);
    //               vertsArray[numVerts] = vertex;
    //               numVerts++;
    void addVertex(const QPoint& vertex);

    //Function that returns the polygon vector that contains the vertices
    //Parameters: N/A
    //Postcondtion: return vertVect;
    Shape_Vector<QPoint>& getVertices();

private:
    Shape_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_NUM_VERTS];
    int     numVerts;
};

#endif // POLYGON_H
