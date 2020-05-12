#ifndef TEXT_H
#define TEXT_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

//!  Class Text
/*!
  Class to construct a Text on screen.
*/
class Text : public Shape
{
public:
     Text(QPaintDevice* dev = nullptr, int id = -1);
     
    //! Alternate constructor.
    /*!
      \param text QString to represent text
      \param TC an integer
      \param font an integer
      \param align an integer
      \param style an integer
      \param weight an integer
      \param boxW an integer
      \param boxH an integer
      \param Loc QPoint for location
    */
     Text(QString text, int TC, int font, int align, int style, int weight, int boxW, int boxH, QPoint Loc);

    //! Alternate constructor.
    /*!
      \param T QString to represent text
      \param TC a string
      \param F a string
      \param align a string
      \param S a string
      \param W a string
      \param boxW an integer
      \param boxH an integer
      \param Loc QPoint for location
    */
     Text(QString T, std::string TC, std::string F, std::string align, std::string S, std::string W, int boxW, int boxH, QPoint Loc);

    //! Destructor.
    /*!
    */
    ~Text() override {}

    //! Function to draw a Text Object.
    /*!
      \param device a pointer to a QPaintDevice
    */
    void draw(QPaintDevice *dev) override;

    //! Function to move a Text Object.
    /*!
      \param x an integer
      \param y an integer
      \param vertext an integer
      \return New location
    */
    void move(int x, int y, int vertext) override;
    
    //! Function to calculate the area of a Line Object.
    /*!
      \return area
    */
    double area() override;

    //! Function to calculate the perimeter of a Line Object.
    /*!
      \return perimeter
    */
    double perimeter() override;

    //! Mutator function to set the text of a Text Object.
    /*!
      \param newText QString to set text to
    */
    void setText(QString newText);

    //! Mutator function to set the box width of a Text Object.
    /*!
      \param newBoxWidth integer to set width to
    */
    void setBoxWidth(int newBoxWidth);

    //! Mutator function to set the box height of a Text Object.
    /*!
      \param newBoxHeight integer to set height to
    */
    void setBoxHeight(int newBoxHeight);

    //! Mutator function to set the flag of a Text Object.
    /*!
    */
    void setFlag(Qt::AlignmentFlag flagParam);

    //! Mutator function to set the location of a Text Object using x and y coordinates.
    /*!
      \param x an integer
      \param y an integer
    */
    void setLocation(int x, int y);

    //! Mutator function to set the location of a Text Object using x and y coordinates.
    /*!
      \param pt Qpoint to set location to
    */
    void setLocation(QPoint pt);

    //! Mutator function to set the dimensions of a Text object.
    /*!
      \param w integer for width
      \param h integer for height
    */
    void setDimensions(int w, int h);

    //! Accessor function to get the font of a Text Object. 
    /*!
      \return font
    */
    QFont& getFont();

    //! Accessor function to get the flag of a Text Object.
    /*!
      \return flag
    */
    Qt::AlignmentFlag getFlag();

    //! Accessor function to get the text of a Text object.
    /*!
      \return text
    */
    QString getText();

private:
    QString text;
    QFont font;
    Qt::AlignmentFlag flag;
    int boxWidth;
    int boxHeight;
    QPoint location;
};
#endif // TEXT_H
