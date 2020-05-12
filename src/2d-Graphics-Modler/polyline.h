#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

const int DEFAULT_NUM_PTS = 8;

//!  Class Polyline
/*!
  Class to construct a Polyline on screen.
*/
class Polyline : public Shape
{
public: 
    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param PW an integer
    */
     Polyline(QPaintDevice* device = nullptr, int id = -1);
     
    //! Alternate constructor.
    /*!
      \param PS an integer
      \param PW an integer
      \param PC an integer
      \param PCS an integer
      \param PJS an integer
      \param BC an integer
      \param BS an integer
      \param NP an integer
      \param PV a pointer to a QPoint
    */
     Polyline(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, int NP, QPoint* PV);
    
    //! Destructor.
    /*!
    */
    ~Polyline()  override {}

    //! Function to add a single point.
    /*!
      \param pt a reference to a QPoint
    */
    void addPoint(const QPoint& pt);

    //! Function to add the total number of points.
    /*!
      \param num an integer
    */
    void addNumPoints(int num) {numPts = num;}

    //! Pure Virtual Function to draw a Polyline Object.
    /*!
      \param device a pointer to a QPaintDevice
    */
    virtual void draw(QPaintDevice *device) override;

    //! Function to move a Polyline Object.
    /*!
      \param x an integer
      \param y an integer
      \param vertex an integer
      \return New location
    */
    void move(int x, int y, int vertex) override;

    //! Function to calculate the area of a Line Object.
    /*!
      \return 0
    */
    double perimeter() override {return 0;}

    //! Function to calculate the area of a Line Object.
    /*!
      \return 0
    */
    double area() override {return 0;}

    //! Accessor function to get the number of points in a Polyline Object. 
    /*!
      \return numPts
    */
    int getNumPoints() {return numPts;}

private:
    //Shape_Vector<QPoint> pts;
    int numPts;
    QPoint pointsAr[DEFAULT_NUM_PTS];
};


#endif // POLYLINE_H
