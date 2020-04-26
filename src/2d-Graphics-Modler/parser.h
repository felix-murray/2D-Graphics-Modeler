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
    Shape_Parser();
    Shape_Parser(QString);
    ~Shape_Parser(){inputFile.close();}

    void set_file(QString);
    void parseInput(Shape_Vector<Shape*> &parsedInput);

private:
    Shape_Vector<QString> dimensions;
    QString ShapeFileName;
    QFile   inputFile;
    int ShapeId;
    QString Dimensions;
    QString ShapeType;
    QString PenColor;
    int PenWidth;
    QString PenStyle;
    QString PenCapStyle;
    QString PenJoinStyle;
    QString BrushColor;
    QString BrushStyle;
    QString TextQString;
    QString TextColor;
    QString TextAlignment;
    int TextPointSize;
    QString TextFontFamily;
    QString TextFontStyle;
    QString TextFontWeight;

    void setDefaults();
    void fileOpen();
    void fileClose();
    void Shape_ParserQString();
    void saveInput(Shape_Vector<Shape*> &parsedInput);
};

#endif // Shape_Parser
