#ifndef PARSER_H
#define PARSER_H


#include "shape.h"
#include "shape_Vector.h"
#include "RenderArea.h"
#include "rectangle.h"
#include "text.h"
#include "line.h"
#include "ellipse.h"
#include "polyline.h"
#include "polygon.h"
#include <string>
#include <fstream>
#include <QString>
#include <QDebug>
#include <QFile>


//!  Class Shape_Parser
/*!
  Class to translate shapes.txt file(s) into shapes on screen.
*/
class Shape_Parser
{
public:

    //! Default constructor.
    /*!
    */
    Shape_Parser();

    //! Destructor.
    /*!
    */
    ~Shape_Parser();

    //! Function to take parsed data and input it into shape constructors.
    /*!
    */
    void translate(RenderArea &);

    //! Function to Read in input from a file and parse it into renderable shapes.
    /*!
    */
    void parseInput(RenderArea &canvas);

    //! Function to set the name of the file to input from.
    /*!
     \param fileName Qstring to represent the name of the file.
    */
    void setFileName(QString fileName);

private:
    int dimensions[10];
    int dimensions_count;
    QString ShapeFileName;
    int ShapeId;
    QString Dimensions;
    QString ShapeType;
    int PenColor;
    int PenWidth;
    int PenStyle;
    int PenCapStyle;
    int PenJoinStyle;
    int BrushColor;
    int BrushStyle;
    QString TextQstring;
    int TextColor;
    int TextAlignment;
    int TextPointSize;
    int TextFontFamily;
    int TextFontStyle;
    int TextFontWeight;
};

#endif // Shape_Parser
