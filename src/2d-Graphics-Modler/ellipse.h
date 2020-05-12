#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

//!  Class Ellipse
/*!
  Class to construct an Ellipse (circle) on screen.
*/
class Ellipse : public Shape
{
public:
    
    //! Default constructor.
    /*!
      \param device pointer to a QPaintDevice
      \param id id of the shape object
    */
    Ellipse(QPaintDevice* device = nullptr, int id = -1);

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
    Ellipse(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, int X , int Y, int W, int H);

    //! Destructor.
    /*!
    */
    ~Ellipse() override {}

    Ellipse(int num, QColor PC);

    //! Function to move an Ellipse Object.
    /*!
      \param x an integer
      \param y an integer
      \param na an integer
      \return New location
    */
    void move(int x, int y, int na) override;

    //! Function to draw an Ellipse Object.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice* device) override;
    
    //! Function to calculate the area of an Ellipse Object.
    /*!
      \return area
    */
    double area() override;

    //! Function to calculate the perimeter of an Ellipse Object.
    /*!
      \return perimeter
    */
    double perimeter() override;

    //! Accessor function to get the width of an Ellipse Object.
    /*!
      \return width
    */
    double getWidth();

    //! Accessor function to get the height of an Ellipse Object.
    /*!
      \return height
    */
    double getHeight();

    //! Accessor function to get the location of an Ellipse Object.
    /*!
      \return location
    */
    QPoint& getLocation();

    //! Mutator function to set the width and height of an Ellipse Object.
    /*!
      \param w a double
      \param h a double
    */
    void setDimensions(double w, double h);

    //! Mutator function to set the location of an Ellipse Object using x and y coordinates.
    /*!
      \param x an integer
      \param y an integer
    */
    void setLocation(int x, int y);

    //! Mutator function to set the location of an Ellipse Object using QPoint coordinates.
    /*!
      \param pt a Qpoint variable
    */
    void setLocation(QPoint pt);

private:
    // Class Vars
    double width;
    double height;
    QPoint location;
};

#endif // ELLIPSE_H
