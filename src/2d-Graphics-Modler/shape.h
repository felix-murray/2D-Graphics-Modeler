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

    //! Alternate constructor.
    /*!
      \param TC an integer
    */
    Shape(int TC);

     //! Alternate constructor.
    /*!
      \param PS an integer
      \param PW an integer
      \param PC an integer
      \param PCS an integer
      \param PJS an integer
      \param BC an integer
      \param BS an integer
    */
    Shape(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS);

    //! Mutator function to set type of Shape
    /*!
      \param shape enum for shape type
    */
    void setShape(Shapes shape);

    //! Function to increase the value of shapeID
    /*!
    */
    static void incID();

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
     static int numShapes;  /*!< Total number of shapes drawn. */
     int id;        /*!< ID for the shape, used in comparison operations. */
     QPen pen;      /*!< Pen used in drawing of Shapes. */
     QBrush brush;  /*!< Brush used in drawing of Shapes. */
};

#endif // SHAPE_H
