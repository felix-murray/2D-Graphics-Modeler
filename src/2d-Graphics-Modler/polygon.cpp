#include "polygon.h"

Polygon::Polygon(QPaintDevice* dev, int id)
{
    setID(id);
    setShape(Shapes(3));
    numVerts = 0;
}

void Polygon::setNumVertices(int numVertices)
{
    vertVect.resize(numVertices);
    numVerts = numVertices;
}

int Polygon::getNumVertices()const
{
    return numVerts;
}

void Polygon::addVertex(const QPoint &vertex)
{
    if(numVerts < DEFAULT_NUM_VERTS)
    {
        vertVect.push_back(vertex);
        vertsArray[numVerts] = vertex;
    }
}

Shape_Vector<QPoint>& Polygon::getVertices()
{
    return vertVect;
}
/*
    Shape_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_NUM_VERTS];
    int     numVerts;
*/
