#include "parser.h"
#include <iostream>
#include <sstream>
Shape_Parser::Shape_Parser()
{

}
Shape_Parser::~Shape_Parser(){

}
/*!
 * \brief Gathers the collected data from parseInput() and adds the shape to the canvas
 *
 * translate() function is called by parseInput() to form the current holding data
 * members into a new shape, distinguishing the type of shape by ShapeType.
 * Then it will add the shape to the canvas and update the canvas.
 * \param canvas
 */

void Shape_Parser::translate(RenderArea &canvas)
{
    qDebug() << "Within Translate\n";

    //Use the shape constructors to build shape given parameters (remember to convert to int first!)
    Shape *shape;
    if(ShapeType == "Line")
    {
        shape = new Line(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle, -1, -1, QPoint(dimensions[0], dimensions[1]), QPoint(dimensions[2], dimensions[3]));
        canvas.addShape(shape);

        qDebug() << "Parsed Line\n";
    }

    else if(ShapeType == "Polyline")////////////////////////////////////////////////////////////////////////////
    {
        int numPts = dimensions_count/2;
        QPoint *PV = new QPoint[numPts];
        QPoint *temp;

        int counterPV = 0;
        for(int i = 0; i < dimensions_count; i=i+2)
        {
            temp = new QPoint(dimensions[i], dimensions[i+1]);
            PV[counterPV] = *temp;
            counterPV++;
        }
        shape = new Polyline(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle, -1, -1, numPts, PV);
        canvas.addShape(shape);
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
        canvas.addShape(shape);

        qDebug() << "Parsed Rectangle\n";
    }
    else if(ShapeType == "Square")
    {
        shape = new Rectangle(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle,
                              BrushColor, BrushStyle, dimensions[0] , dimensions[1], dimensions[2], dimensions[3]);
        canvas.addShape(shape);

        qDebug() << "Parsed Square\n";
    }
    else if(ShapeType == "Ellipse")////////////////////////////////
    {
        shape = new Ellipse(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle,
                            BrushColor, BrushStyle, dimensions[0] , dimensions[1], dimensions[2], dimensions[3]);
        canvas.addShape(shape);

        qDebug() << "Parsed Ellipse\n";
    }
    else if(ShapeType == "Circle")////////////////////////////////
    {
        shape = new Ellipse(PenStyle, PenWidth, PenColor, PenCapStyle, PenJoinStyle,
                            BrushColor, BrushStyle, dimensions[0] , dimensions[1], dimensions[2], dimensions[3]);
        canvas.addShape(shape);

        qDebug() << "Parsed Ellipse\n";
    }
    else if(ShapeType == "Text")
    {
        shape = new Text(TextQstring, TextColor, TextFontFamily, TextAlignment,
                         TextFontStyle, TextFontWeight, dimensions[2], dimensions[3], QPoint(dimensions[0], dimensions[1]));
        canvas.addShape(shape);

        qDebug() << "Parsed Text\n";
    }

    canvas.update();
}

/*!
 * \brief Read in input from a file and parse it into renderable shapes
 *
 * This function reads a file and based on the specific "shapes.txt" file
 * and it's specific structure. Using QFile and QTextStream, parseInput()
 * traverses through the file in a line by line fashion, extracts the data
 * and set the private data members of the Shape_Parser class. When a single
 * shape is read (indicated by the QTextStream reading in a blank line ("")),
 * it will call the translate() function which creates a new shape based
 * on the current Shape_Parser class data members and add the new shape.
 * After translate() has executed, the loop will repeat this process until
 * the end of file is reached.
 * \param canvas
 */
void Shape_Parser::parseInput(RenderArea &canvas)
{
    qDebug() << "Within Parser\n";
    int temp;
    dimensions_count = 0;

    QString line;

    QFile inputFile(ShapeFileName);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Could not open the file\n";
    else
    {
        qDebug() << "File is opened\n";

        QTextStream file(&inputFile);
        line = file.readLine(); //Reads in the very first blank line in the file
        line = file.readLine(); //Reads in the first substantial line of text ("ShapeId: __")

        while(!file.atEnd())
        {
            // Begin Parsing:
            qDebug() << "Within Parser Loop\n";

            if(line.startsWith("ShapeId:"))
            {
                line = line.mid(9);
                ShapeId = line.toInt();
                line = file.readLine();
            if(line.startsWith("ShapeType:"))
            {
                line = line.mid(11);
                ShapeType = line;
                line = file.readLine();
            if (line.startsWith("ShapeDimensions:"))
            {
                Dimensions = line.mid(17);
                QStringList list1 = Dimensions.split(',', QString::SkipEmptyParts);
                for(QString s: list1)
                {
                    dimensions[dimensions_count] = s.toInt();
                    dimensions_count++;
                }

                line = file.readLine();
            }
            if(line.startsWith("PenColor:"))
            {
                line = line.mid(10);

                if(line == "white")
                    temp = 0;
                else if (line == "black")
                    temp = 1;
                else if (line == "red")
                    temp = 2;
                else if (line == "green")
                    temp = 3;
                else if (line == "blue")
                    temp = 4;
                else if (line == "cyan")
                    temp = 5;
                else if (line == "magenta")
                    temp = 6;
                else if(line == "yellow")
                    temp = 7;
                else if(line == "gray")
                    temp = 8;

                PenColor = temp;
                line = file.readLine();
            }
            if(line.startsWith("PenWidth:"))
            {
                line = line.mid(10);
                PenWidth = line.toInt();
                line = file.readLine();
            }
            if(line.startsWith("PenStyle:"))
            {
                line = line.mid(10);

                if(line == "SolidLine")
                    temp = 0;
                else if (line == "DashLine")
                    temp = 1;
                else if (line == "DotLine")
                    temp = 2;
                else if (line == "DashDotLine")
                    temp = 3;
                else if (line == "DashDotDotLine")
                    temp = 4;
                else if (line == "NoPen")
                    temp = 5;
                PenStyle = temp;
                line = file.readLine();
            }
            if(line.startsWith("PenCapStyle:"))
            {
                line = line.mid(13);

                if(line == "SquareCap")
                    temp = 0;
                else if (line == "FlatCap")
                    temp = 1;
                else if (line == "RoundCap")
                    temp = 2;
                else
                    temp = 0;

                PenCapStyle = temp;
                line = file.readLine();
            }
            if(line.startsWith("PenJoinStyle:"))
            {
                line = line.mid(14);

                if(line == "BevelJoin")
                    temp = 0;
                else if (line == "MiterJoin")
                    temp = 1;
                else if (line == "RoundJoin")
                    temp = 2;
                else
                    temp = 0;

                PenJoinStyle = temp;
                line = file.readLine();
            }
            if(line.startsWith("BrushColor:"))
            {
                line = line.mid(12);

                if(line == "white")
                    temp = 0;
                else if (line == "black")
                    temp = 1;
                else if (line == "red")
                    temp = 2;
                else if (line == "green")
                    temp = 3;
                else if (line == "blue")
                    temp = 4;
                else if (line == "cyan")
                    temp = 5;
                else if (line == "magenta")
                    temp = 6;
                else if(line == "yellow")
                    temp = 7;
                else if(line == "gray")
                    temp = 8;

                BrushColor = temp;
                line = file.readLine();
            }
            if(line.startsWith("BrushStyle:"))
            {
                line = line.mid(12);

                if(line == "SolidPattern")
                    temp = 0;
                else if (line == "HorPattern")
                    temp = 1;
                else if (line == "VerPattern")
                    temp = 2;
                else if (line == "NoBrush")
                    temp = 3;

                BrushStyle = temp;
                line = file.readLine();
            }
            if(line.startsWith("TextString:"))
            {
                line = line.mid(12);
                TextQstring = line;
                line = file.readLine();
            }
            if(line.startsWith("TextColor:"))
            {
                line = line.mid(11);

                if(line == "white")
                    temp = 0;
                else if (line == "black")
                    temp = 1;
                else if (line == "red")
                    temp = 2;
                else if (line == "green")
                    temp = 3;
                else if (line == "blue")
                    temp = 4;
                else if (line == "cyan")
                    temp = 5;
                else if (line == "magenta")
                    temp = 6;
                else if(line == "yellow")
                    temp = 7;
                else if(line == "gray")
                    temp = 8;

                TextColor = temp;
                line = file.readLine();
            }
            if(line.startsWith("TextAlignment:"))
            {
                line = line.mid(15);

                if(line == "AlignLeft")
                    temp = 0;
                else if (line == "AlignCenter")
                    temp = 1;
                else if (line == "AlignRight")
                    temp = 2;
                else if (line == "AlignTop")
                    temp = 3;
                else if (line == "AlignBottom")
                    temp = 4;
                else if (line == "AlignLeft")
                    temp = 5;

                TextAlignment = temp;
                line = file.readLine();
            }
            if(line.startsWith("TextPointSize:"))
            {
                line = line.mid(15);
                TextPointSize = line.toInt();
                line = file.readLine();
            }
            if(line.startsWith("TextFontFamily:"))
            {
                line = line.mid(16);

                if(line == "Comic Sans MS")
                    temp = 0;
                else if (line == "Courier")
                    temp = 1;
                else if (line == "Helvetica")
                    temp = 2;
                else if (line == "Times")
                    temp = 3;

                TextFontFamily = temp;
                line = file.readLine();
            }
            if(line.startsWith("TextFontStyle:"))
            {
                line = line.mid(15);

                if(line == "SquareCap")////////////////////////////Same as PenCapStyle??/////////////////
                    temp = 0;
                else if (line == "FlatCap")
                    temp = 1;
                else if (line == "RoundCap")
                    temp = 2;
                else
                    temp = 0;

                TextFontStyle = temp;
                line = file.readLine();
            }
            if(line.startsWith("TextFontWeight:"))
            {
                line = line.mid(16);

                if(line == "Normal")//////////////////////////////////////////////////////////
                    temp = 0;
                else
                    temp = 0;

                TextFontWeight = temp;
                line = file.readLine();
            }
            if(line == "")
            {
                translate(canvas);
                line = file.readLine();
            }
            }
            }
            for(int i = 0; i < dimensions_count; i++)
            {
                dimensions[i] = 0;
            }
            dimensions_count = 0;
        }

    }
    inputFile.close();
}
void Shape_Parser::setFileName(QString fileName)
{
    ShapeFileName = fileName;
}
