#include "parser.h"
#include <iostream>
#include <sstream>
Shape_Parser::Shape_Parser()
{

}
Shape_Parser::~Shape_Parser()
{

}
void Shape_Parser::translate(RenderArea *canvas)
{
    qDebug() << "Within Translate\n";

    //Use the shape constructors to build shape given parameters (remember to convert to int first!)
    Shape *shape;
    if(ShapeType == "Line"){

        shape = new Line(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle, -1, -1, QPoint(dimensions[0], dimensions[1]), QPoint(dimensions[2], dimensions[3]));
        canvas->addShape(shape);

        qDebug() << "Parsed Line\n";
    }
    else if(ShapeType == "Polyline")////////////////////////////////////////////////////////////////////////////
    {

        qDebug() << "Parsed Polyline\n";
    }
    else if(ShapeType == "Polygon")////////////////////////////////////////////////////////////////////////////////
    {

        qDebug() << "Parsed Polygon\n";
    }
    else if(ShapeType == "Rectangle")
    {
        shape = new Rectangle(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle,
                              BrushColor, BrushStyle, dimensions[0] , dimensions[1], dimensions[2], dimensions[3]);
        canvas->addShape(shape);

        qDebug() << "Parsed Rectangle\n";
    }
    else if(ShapeType == "Ellipse")////////////////////////////////
    {
        shape = new Ellipse(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle,
                            BrushColor, BrushStyle, dimensions[0] , dimensions[1], dimensions[2], dimensions[3]);
        canvas->addShape(shape);

        qDebug() << "Parsed Ellipse\n";
    }
    else if(ShapeType == "Text")
    {
        shape = new Text(TextQstring, TextColor, TextFontFamily, TextAlignment,
                         TextFontStyle, TextFontWeight, dimensions[2], dimensions[3], QPoint(dimensions[0], dimensions[1]));
        canvas->addShape(shape);

        qDebug() << "Parsed Text\n";
    }
    canvas->update();
}

/*!
 * \brief Read in input from the file and add the newly created shape
 * \param canvas
 * \param ui
 */
void Shape_Parser::parseInput(RenderArea *canvas)
{
    qDebug() << "Within Parser\n";

    std::string input;
    int temp;
    int dimensions_count = 0;

    std::ifstream inputFile;
    inputFile.open("shapes.txt");

    //Run through the file and create shapes

    getline(inputFile, input);
    getline(inputFile, input);
    qDebug() << "Before Parsing Loop\n";

    while(!inputFile.eof())
    //while(getline(inputFile, input))
    {
        // Begin Parsing:

        if(input.find("ShapeId:") != std::string::npos)
        {
            //use stoi
            input = input.substr(9);
            ShapeId = stoi(input);

        }

        else if(input.find("ShapeType:") != std::string::npos)
        {
            //use stoi
            input = input.substr(11);
            ShapeType = input;

        }

        else if (input.find("ShapeDimensions:") != std::string::npos)
        {
            Dimensions = input.substr(17);
            std::stringstream ss(Dimensions);
            std::string temp;
            while(getline(ss, temp, ','))/////////////////////////////////might be the issue///////////////////////////
            {
                dimensions[dimensions_count] = stoi(temp);
                dimensions_count++;
            }
            dimensions_count = 0;
        }
        else if(input.find("PenColor:") != std::string::npos)
        {
            input = input.substr(10);
            //input = "white";

            if(input == "white")
                temp = 0;
            else if (input == "black")
                temp = 1;
            else if (input == "red")
                temp = 2;
            else if (input == "green")
                temp = 3;
            else if (input == "blue")
                temp = 4;
            else if (input == "cyan")
                temp = 5;
            else if (input == "magenta")
                temp = 6;
            else if(input == "yellow")
                temp = 7;
            else if(input == "gray")
                temp = 8;

            PenColor = temp;
        }
        else if(input.find("PenWidth:") != std::string::npos)
        {
            input = input.substr(10);
            PenWidth = stoi(input);
        }
        else if(input.find("PenStyle:") != std::string::npos)
        {
            input = input.substr(10);

            if(input == "SolidLine")
                temp = 0;
            else if (input == "DashLine")
                temp = 1;
            else if (input == "DotLine")
                temp = 2;
            else if (input == "DashDotLine")
                temp = 3;
            else if (input == "DashDotDotLine")
                temp = 4;
            else if (input == "NoPen")
                temp = 5;

            PenStyle = temp;
        }
        else if(input.find("PenCapStyle:") != std::string::npos)
        {
            input = input.substr(13);

            if(input == "SquareCap")
                temp = 0;
            else if (input == "FlatCap")
                temp = 1;
            else if (input == "RoundCap")
                temp = 2;
            else
                temp = 0;

            PenCapStyle = temp;
        }
        else if(input.find("PenJoinStyle:") != std::string::npos)
        {
            input = input.substr(14);

            if(input == "BevelJoin")
                temp = 0;
            else if (input == "MiterJoin")
                temp = 1;
            else if (input == "RoundJoin")
                temp = 2;
            else
                temp = 0;

            PenJoinStyle = temp;
        }
        else if(input.find("BrushColor:") != std::string::npos)
        {
            input = input.substr(12);

            if(input == "white")
                temp = 0;
            else if (input == "black")
                temp = 1;
            else if (input == "red")
                temp = 2;
            else if (input == "green")
                temp = 3;
            else if (input == "blue")
                temp = 4;
            else if (input == "cyan")
                temp = 5;
            else if (input == "magenta")
                temp = 6;
            else if(input == "yellow")
                temp = 7;
            else if(input == "gray")
                temp = 8;

            BrushColor = temp;
        }
        else if(input.find("BrushStyle:") != std::string::npos)
        {
            input = input.substr(12);

            if(input == "SolidPattern")
                temp = 0;
            else if (input == "HorPattern")
                temp = 1;
            else if (input == "VerPattern")
                temp = 2;
            else if (input == "NoBrush")
                temp = 3;

            BrushStyle = temp;
        }
        else if(input.find("TextString:") != std::string::npos)
        {
            input = input.substr(12);
            TextQstring = TextQstring.fromStdString(input);
        }
        else if(input.find("TextColor:") != std::string::npos)
        {
            input = input.substr(11);

            if(input == "white")
                temp = 0;
            else if (input == "black")
                temp = 1;
            else if (input == "red")
                temp = 2;
            else if (input == "green")
                temp = 3;
            else if (input == "blue")
                temp = 4;
            else if (input == "cyan")
                temp = 5;
            else if (input == "magenta")
                temp = 6;
            else if(input == "yellow")
                temp = 7;
            else if(input == "gray")
                temp = 8;

            TextColor = temp;
        }
        else if(input.find("TextAlignment:") != std::string::npos)
        {
            input = input.substr(15);

            if(input == "AlignLeft")
                temp = 0;
            else if (input == "AlignCenter")
                temp = 1;
            else if (input == "AlignRight")
                temp = 2;
            else if (input == "AlignTop")
                temp = 3;
            else if (input == "AlignBottom")
                temp = 4;
            else if (input == "AlignLeft")
                temp = 5;

            TextAlignment = temp;
        }
        else if(input.find("TextPointSize:") != std::string::npos)
        {
            input = input.substr(15);
            TextPointSize = stoi(input);
        }
        else if(input.find("TextFontFamily:") != std::string::npos)
        {
            input = input.substr(16);

            if(input == "Comic Sans MS")
                temp = 0;
            else if (input == "Courier")
                temp = 1;
            else if (input == "Helvetica")
                temp = 2;
            else if (input == "Times")
                temp = 3;

            TextFontFamily = temp;
        }
        else if(input.find("TextFontStyle:") != std::string::npos)
        {
            input = input.substr(15);

            if(input == "SquareCap")////////////////////////////Same as PenCapStyle??/////////////////
                temp = 0;
            else if (input == "FlatCap")
                temp = 1;
            else if (input == "RoundCap")
                temp = 2;
            else
                temp = 0;

            TextFontStyle = temp;
        }
        else if(input.find("TextFontWeight:") != std::string::npos)
        {
            input = input.substr(16);

            if(input == "Normal")//////////////////////////////////////////////////////////
                temp = 0;
            else
                temp = 0;

            TextFontWeight = temp;
            translate(canvas);
        }
        else if(input == "")
        {

            translate(canvas);
            //setDefaults();	// Reset evreything in parse class to defaults to eliminate cross-contamination.
        }
    getline(inputFile, input);
    }

    inputFile.close();
}

void Shape_Parser::setDefaults()
{
=======
//void Shape_Parser::parseInput(RenderArea* canvas)
//{
//    inputFile.open("shapes.txt");
//    std::string input;
//    int temp;
//    int dimensions_count = 0;

//    //Run through the file and create shapes
//    inputFile >> input;
//    while(inputFile)
//    {
//        // Begin Parsing:

//        if(input == "ShapeId:"){
//            //use stoi
//            inputFile >> input;
//            ShapeId = stoi(input);
//        }else if(input == "ShapeType:"){
//            inputFile >> input;
//            ShapeType = input;
//        }else if (input == "ShapeDimensions:"){
//            Dimensions = input;
//            bool breakWhile = false;
//            while(!breakWhile)/////////////////////////////////might be the issue///////////////////////////
//            {
//                inputFile >> input;
//                if(input[input.length()-1] != ',')
//                    breakWhile = true;
//                dimensions[dimensions_count] = stoi(input);
//                dimensions_count++;
//            }
//            dimensions_count = 0;

//        }else if(input == "PenColor:"){
//            inputFile >> input;
//            //input = "white";

//            if(input == "white")
//                temp = 0;
//            else if (input == "black")
//                temp = 1;
//            else if (input == "red")
//                temp = 2;
//            else if (input == "green")
//                temp = 3;
//            else if (input == "blue")
//                temp = 4;
//            else if (input == "cyan")
//                temp = 5;
//            else if (input == "magenta")
//                temp = 6;
//            else if(input == "yellow")
//                temp = 7;
//            else if(input == "gray")
//                temp = 8;

//            PenColor = temp;
//        }else if(input == "PenWidth:"){
//            inputFile >> input;
//            PenWidth = stoi(input);
//        }else if(input == "PenStyle:"){
//            inputFile >> input;

//            if(input == "SolidLine")
//                temp = 0;
//            else if (input == "DashLine")
//                temp = 1;
//            else if (input == "DotLine")
//                temp = 2;
//            else if (input == "DashDotLine")
//                temp = 3;
//            else if (input == "DashDotDotLine")
//                temp = 4;
//            else if (input == "NoPen")
//                temp = 5;

//            PenStyle = temp;
//        }else if(input == "PenCapStyle:"){
//            inputFile >> input;

//            if(input == "SquareCap")
//                temp = 0;
//            else if (input == "FlatCap")
//                temp = 1;
//            else if (input == "RoundCap")
//                temp = 2;
//            else
//                temp = 0;

//            PenCapStyle = temp;
//        }else if(input == "PenJoinStyle:"){
//            inputFile >> input;

//            if(input == "BevelJoin")
//                temp = 0;
//            else if (input == "MiterJoin")
//                temp = 1;
//            else if (input == "RoundJoin")
//                temp = 2;
//            else
//                temp = 0;

//            PenJoinStyle = temp;
//        }else if(input == "BrushColor:"){
//            inputFile >> input;

//            if(input == "white")
//                temp = 0;
//            else if (input == "black")
//                temp = 1;
//            else if (input == "red")
//                temp = 2;
//            else if (input == "green")
//                temp = 3;
//            else if (input == "blue")
//                temp = 4;
//            else if (input == "cyan")
//                temp = 5;
//            else if (input == "magenta")
//                temp = 6;
//            else if(input == "yellow")
//                temp = 7;
//            else if(input == "gray")
//                temp = 8;

//            BrushColor = temp;
//        }else if(input == "BrushStyle:"){
//            inputFile >> input;

//            if(input == "SolidPattern")
//                temp = 0;
//            else if (input == "HorPattern")
//                temp = 1;
//            else if (input == "VerPattern")
//                temp = 2;
//            else if (input == "NoBrush")
//                temp = 3;

//            BrushStyle = temp;
//        }else if(input == "TextString"){
//            inputFile >> input;
//            TextQstring = TextQstring.fromStdString(input);
//        }else if(input == "TextColor:"){
//            inputFile >> input;

//            if(input == "white")
//                temp = 0;
//            else if (input == "black")
//                temp = 1;
//            else if (input == "red")
//                temp = 2;
//            else if (input == "green")
//                temp = 3;
//            else if (input == "blue")
//                temp = 4;
//            else if (input == "cyan")
//                temp = 5;
//            else if (input == "magenta")
//                temp = 6;
//            else if(input == "yellow")
//                temp = 7;
//            else if(input == "gray")
//                temp = 8;

//            TextColor = temp;
//        }else if(input == "TextAlignment:"){
//            inputFile >> input;

//            if(input == "AlignLeft")
//                temp = 0;
//            else if (input == "AlignCenter")
//                temp = 1;
//            else if (input == "AlignRight")
//                temp = 2;
//            else if (input == "AlignTop")
//                temp = 3;
//            else if (input == "AlignBottom")
//                temp = 4;
//            else if (input == "AlignLeft")
//                temp = 5;

//            TextAlignment = temp;
//        }else if(input == "TextPointSize:"){
//            inputFile >> input;
//            TextPointSize = stoi(input);
//        }else if(input == "TextFontFamily:"){
//            inputFile >> input;

//            if(input == "Comic Sans MS")
//                temp = 0;
//            else if (input == "Courier")
//                temp = 1;
//            else if (input == "Helvetica")
//                temp = 2;
//            else if (input == "Times")
//                temp = 3;

//            TextFontFamily = temp;
//        }else if(input == "TextFontStyle:"){
//            inputFile >> input;

//            if(input == "SquareCap")////////////////////////////Same as PenCapStyle??/////////////////
//                temp = 0;
//            else if (input == "FlatCap")
//                temp = 1;
//            else if (input == "RoundCap")
//                temp = 2;
//            else
//                temp = 0;

//            TextFontStyle = temp;
//        }else if(input == "TextFontWeight:"){
//            inputFile >> input;

//            if(input == "Normal")//////////////////////////////////////////////////////////
//                temp = 0;
//            else
//                temp = 0;

//            TextFontWeight = temp;
//        }else if(input == "\n"){
//            translate(canvas);
//            setDefaults();	// Reset evreything in parse class to defaults to eliminate cross-contamination.
//        }

//    }

//    inputFile.close();
//}
void Shape_Parser::setDefaults()
{
    for(int i = 0; i < 10; i++)
    {
        dimensions[i] = 0;
    }
}
void Shape_Parser::dimToQPoint()
{
//    //dimensions = [20, 90, 30, 40];
//    int index;
//    if(ShapeType == "Line")
//    {
//        QPoint *P1 = new QPoint(dimensions[0], dimensions[1]);
//        QPoint *P2 = new QPoint(dimensions[2], dimensions[3]);
//    }
//    else if(ShapeType == "PolyLine")
//    {
//        for(int i = 0; i < 10; i++)
//        {
//            QPoint *P1 = new QPoint(dimensions[0], dimensions[1]);
//            QPoint *P2 = new QPoint(dimensions[2], dimensions[3]);
//        }
//    }
//    else if(ShapeType == "PolyLine")
//    {
//        for(int i = 0; i < 10; i++)
//        {
//            QPoint *P1 = new QPoint(dimensions[0], dimensions[1]);
//            QPoint *P2 = new QPoint(dimensions[2], dimensions[3]);
//        }
//    }
//    else if(ShapeType == "PolyLine")
//    {
//        for(int i = 0; i < 10; i++)
//        {
//            QPoint *P1 = new QPoint(dimensions[0], dimensions[1]);
//            QPoint *P2 = new QPoint(dimensions[2], dimensions[3]);
//        }
//    }
//    //Dimensions = "900, 90, 910, 20, 970, 40, 980, 80"

}
