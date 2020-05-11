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



class Shape_Parser
{
public:
    Shape_Parser();
    ~Shape_Parser();
    void translate(RenderArea *);

    void parseInput(RenderArea *);

protected:
    const char DIVIDER = ' ';

private:
    int dimensions[10]; //////////////////////////can this be a vector of ints?//////
    std::string ShapeFileName;

    int ShapeId;

    std::string Dimensions;
    std::string ShapeType;
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

    void setDefaults();
    //void Shape_Parser();
    void saveInput(Shape_Vector<Shape*> &parsedInput);
    void dimToQPoint();
};

#endif // Shape_Parser
