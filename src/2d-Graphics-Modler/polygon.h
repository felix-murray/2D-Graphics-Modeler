#ifndef POLYGON_H
#define POLYGON_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

const int DEFAULT_NUM_VERTS = 8;

//!  Class Polygon
/*!
  Class to construct a Polygon on screen.
*/
class Polygon : public Shape
{
public:

    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id id of the shape object
    */
    Polygon(QPaintDevice* dev = nullptr, int id = -1);
    
    //! Destructor.
    /*!
    */
    ~Polygon() override {}

    //! Pure Virtual function to draws a Polygon Object.
    /*!
      \param dev pointer to a QPaintDevice
    */
    virtual void draw(QPaintDevice *dev) override;

     //! Function to move a Polygon vertext to a different coordinate.
    /*!
      \param x a integer
      \param y a integer
      \param vertext an integer
      \return New location
    */
    virtual void move(int x, int y, int vertex) override;
    
    //! Function to calculate the area of a Line Object.
    /*!
      \return area
    */
    virtual double area() override;

    //! Function to calculate the perimeter of a Line Object.
    /*!
      \return perimeter
    */
    virtual double perimeter() override;

    //! Mutator function to set the number of vertices of a Polygon Object.
    /*!
      \param numVertices integer for number of verticies 
    */
    void setNumVertices(int numVertices);

    //! Accessor function to get the number of vertices of a Polygon Object.
    /*!
      \return numVerts
    */
    int getNumVertices()const;

    //! Function that adds a vertex to the polygon.
    /*!
      \param vertect constant reference to a QPoint
      \return vertVect
    */
    void addVertex(const QPoint& vertex);

     //! Accessor function that returns the Polygon vector that contains the vertices.
    /*!
      \return vertVect
    */
    Shape_Vector<QPoint>& getVertices();

private:
    Shape_Vector<QPoint> vertVect;
    QPoint vertsArray[DEFAULT_NUM_VERTS];
    int     numVerts;
};

#endif // POLYGON_H
