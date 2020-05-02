#include <cmath>
#include "polygon.h"

Polygon::Polygon(QPaintDevice* dev, int id)
{
    setDefaultStyle();
    setID(id);
    setShape(Shapes(3));
    numVerts = 0;
}

void Polygon::draw(QPaintDevice *dev)
{
//...
}

void Polygon::move(int x, int y, int vertex)
{
    if(vertex < numVerts)
    {
        //sets the x and y coordinates of the vertex in the vertex vector.
        vertVect[vertex].setX(x);
        vertVect[vertex].setY(y);

        //sets the c and y coordinates of the vertex in the vertex array.
        vertsArray[vertex].setX(x);
        vertsArray[vertex].setY(y);
    }
}

double Polygon::area()
{
    int xMid;
    int yMid;
    int xMid2;
    int yMid2;
    int xCenter;
    int yCenter;
    double area;
    double apothem;
    double perimeter = this->perimeter();

    if(numVerts%2 == 0) //if even, finds the midpoint of the first side
    {
        xMid = ((vertVect[0].x() + vertVect[1].x()) / 2);
        yMid = ((vertVect[0].y() + vertVect[1].y()) / 2);
    }
    else //if odd, gets the x and y coordinates of the first vertex
    {
        xMid = vertVect[0].x();
        yMid = vertVect[0].y();
    }

    //Finds the x and y coordinates of the midpoint of opposite side of the polygon from the first midpoint.
    xMid2 = ((vertVect[numVerts - 2].x() + vertVect[numVerts - 1].x()) / 2);
    yMid2 = ((vertVect[numVerts - 2].y() + vertVect[numVerts - 1].y()) / 2);

    //Calculates the x and y coordinates of the center of the polygon using the two midpoints.
    xCenter = ((xMid + xMid2) / 2);
    yCenter = ((yMid + yMid2) / 2);

    //calculates the apothem of the polygon.
    apothem = sqrt(pow((xMid - xCenter), 2) + pow((yMid - yCenter), 2));

    if(apothem < 0)
    {
        apothem = apothem + (apothem * -2);    //makes sure that the apothem is a positive number.
    }

    area = (apothem * perimeter) / 2;           //calculates area using the apothem and perimeter of  the polygon.

    return area;
}

double Polygon::perimeter()
{
    double perimPolygon = 0.0;
    double distance = 0.0;

    for(int loop = 0; loop < numVerts; loop++) //calculates the distance of each side using the distance formula.
    {
        if(loop < numVerts - 1) //measures all sides of the polygon except the last side one by one
        {
            distance = sqrt(pow((vertVect[numVerts + 1].x() - vertVect[numVerts].x()), 2) + pow((vertVect[numVerts + 1].y() - vertVect[numVerts].y()), 2));
        }
        else //measures the distance between the last vertex and the first vertex of the polygon
        {
            distance = sqrt(pow((vertVect[0].x() - vertVect[numVerts].x()), 2) + pow((vertVect[0].y() - vertVect[numVerts].y()), 2));
        }
        perimPolygon = perimPolygon + distance; //adds the value of each side to the total perimeter size.
    }
    return perimPolygon;
}

void Polygon::setNumVertices(int numVertices)
{
    numVerts = numVertices; //sets numVerts to equal numVertices
}

int Polygon::getNumVertices()
{
    return numVerts; //returns the number of vertices in the polygon
}

void Polygon::addVertex(const QPoint& vertex)
{
    if(numVerts < DEFAULT_NUM_VERTS)    //as long as the number of vertices in the polygon does not exceed
    {                                   //the default number of vertices then the function will add the vertex
        vertVect.push_back(vertex);     //to the vecter of vertices and the array of vertices and increment
        vertsArray[numVerts] = vertex;  //numverts by 1.
        numVerts++;
    }
}

Shape_Vector<QPoint>& Polygon::getVertices()
{
    return vertVect;    //returns the vector that holds all of the vertices.
}
