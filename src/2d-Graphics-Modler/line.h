#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>


//!  Class Line
/*!
  Class to construct a Line on screen.
*/
class Line : public Shape
{
public:
    Line(QPaintDevice *device, int id);
    
    //! Alternate constructor.
    /*!
      \param PS an integer
      \param PW an integer
      \param PC an integer
      \param PCS an integer
      \param PJS an integer
      \param BC an integer
      \param BS an integer
      \param X an integer
      \param Y an integer
      \param W an integer
      \param H an integer
    */
    Line(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, QPoint P1, QPoint P2);
    
    //! Destructor.
    /*!
    */
    virtual ~Line() {};

    //! Mutator function to set the points of a Line Object.
    /*!
      \param x integer for x point
      \param y integer for y point
    */
    void setPoints(QPoint &x, QPoint &y) {line_begin = x; line_end = y;};

    //! Function to move a Line Object.
    /*!
      \param tX a constant integer
      \param tY a constant integer
      \param ptIndex an integer
      \return New location
    */
    void move(const int tX, const int tY, int ptIndex) override;
    
    //! Function to draw a Line Object.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice *device) override;
    
    //! Function to calculate the perimeter of a Line Object.
    /*!
      \return 0
    */
    double perimeter() override;

    //! Function to calculate the area of a Line Object.
    /*!
      \return 0
    */
    double area() override;

private:
    QPoint line_begin;
    QPoint line_end;
};


#endif // LINE_H
