#ifndef PARSER_H
#define PARSER_H


#include "shape.h"
#include "shape_Vector.h"
#include <fstream>
#include <QString>
#include <QDebug>
#include <QFile>
#include <iostream>


class Shape_Parser
{
public:
    void translate(int ShapeId,
                   std::string Dimensions,
                   std::string ShapeType,
                   std::string PenColor,
                   int PenWidth,
                   std::string PenStyle,
                   std::string PenCapStyle,
                   std::string PenJoinStyle,
                   std::string BrushColor,
                   std::string BrushStyle,
                   std::string TextQstring,
                   std::string TextColor,
                   std::string TextAlignment,
                   int TextPointSize,
                   std::string TextFontFamily,
                   std::string TextFontStyle,
                   std::string TextFontWeight);

    void parseInput(Shape_Vector<Shape*> &parsedInput);

protected:
    const char DIVIDER = ' ';

private:
    Shape_Vector<std::string> dimensions;
    std::string ShapeFileName;
    std::ifstream inputFile;
    int ShapeId;

    std::string Dimensions;
    std::string ShapeType;
    std::string PenColor;
    int PenWidth;
    std::string PenStyle;
    std::string PenCapStyle;
    std::string PenJoinStyle;
    std::string BrushColor;
    std::string BrushStyle;
    std::string TextQstring;
    std::string TextColor;
    std::string TextAlignment;
    int TextPointSize;
    std::string TextFontFamily;
    std::string TextFontStyle;
    std::string TextFontWeight;

    void setDefaults();
    //void Shape_Parser();
    void saveInput(Shape_Vector<Shape*> &parsedInput);
};

#endif // Shape_Parser
