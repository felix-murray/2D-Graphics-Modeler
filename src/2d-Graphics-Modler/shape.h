/*!
 * \file shape.h
 * \brief a brief description of a file
 */

//! My actual function doesn't really look like this
/*!
 *  Some sample detail which isn't exactly the same as the main
 *  function but the structure is the same
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <QObject>
#include <QPaintDevice>
#include <QPainter>
#include <string>

using namespace Qt;

class Shape : public QPainter
{
public:
    /** \enum type Shapes, used to distinguish between the different shapes
     */
    enum Shapes{defaultObj,     /**< enum value 1 */
                LineObj,        /**< enum value 2 */
                PolylineObj,    /**< enum value 3 */
                PolygonObj,     /**< enum value 4 */
                RectangleObj,   /**< enum value 5 */
                EllipseObj,     /**< enum value 6 */
                TextObj};       /**< enum value 7 */

    //! Default Constructor.
    /*!
      Constructs a default shape
    */
    Shape();
    Shape(int TC);
    Shape(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS);
    //Mutator Functions

    /**
     * Return a copy of the specified standard vector in descending
     * order.  The order of duplicated items is not defined.  Infinite
     * values come before or after all other elements depending on sign.
     *
     * @tparam T type of elements contained in vector
     * @param[in] xs vector to order
     * @return copy of vector in descending order
     * @throw std::domain_error if any of the values are NaN
     */
    void setShape(Shapes shape);

    //! Mutator Function to set brush properties.
    /*!
      \param color
      \param style
    */
    void setBrush(GlobalColor color, BrushStyle style);

    //! Mutator Function to set pen properties.
    /*!
      \param color
    */
    void setPen(GlobalColor color);

    //! Mutator Function to set brush properties.
    /*!
      \param color
      \param style
    */

    //! Mutator Function to set Shape Object ID
    /*!
      \param ID
    */
    void setID(int ID);

    void setDefaultStyle();

    //Accessor Functions

    //! Accessor Function to get a shape
    /*!
      \return shape
    */
    Shapes getShape() const {return shape;}

    //! Accessor Function to get a Shape Object enum type.
    /*!
      \return brush
    */
    const QBrush &getBrush() const {return brush;}

    //! Accessor Function to get Shape Object brush.
    /*!
      \return brush
    */
    const QPen &getPen() const {return pen;}

    //! Accessor Function to get Shape Object ID.
    /*!
      \return id
    */
    int getID() const {return id;}

    //Virtual Functions

    //! Destructor.
    /*!
      Destroys a shape.
    */
    virtual ~Shape(){}

    //! Pure Virtual function to move a Shape object. Used as a default in base class.
    /*!
      \param tX
      \param tY
      \param ptIndex
    */
    virtual void move(const int tX, const int tY, int ptIndex) = 0;

    //! Pure Virtual function to draw a Shape object.
    /*!
      \param device
    */
    virtual void draw(QPaintDevice *device) = 0;

    //! Pure Virtual function to calculate perimeter of a Shape object.
    /*!
      \return area
    */
    virtual double perimeter() = 0;

    //! Pure Virtual function to calculate area of a Shape object.
    /*!
      \return area
    */
    virtual double area() = 0;

 protected:
    //! Accessor Function to return painter object.
    /*!
      \return painter
    */
    QPainter &getQPainter();
    QPainter painter;          /*!< Painter used in drawing of Shapes. */
    Shapes shape;              /*!< enum used to identify type of shape. */

 private:
     int id;        /*!< ID for the shape, used in comparison operations. */
     QPen pen;      /*!< Pen used in drawing of Shapes. */
     QBrush brush;  /*!< Brush used in drawing of Shapes. */
};

#endif // SHAPE_H
