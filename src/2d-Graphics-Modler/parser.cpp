#include "parser.h"

void Shape_Parser::translate(int ShapeId,
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
                             std::string TextFontWeight)
{
    //Use the shape constructors to build shape given parameters (remember to convert to int first!)

    if(ShapeType == "Line"){
        //constructor
        qDebug() << "Parsed Line\n";
    }else if(ShapeType == "Polyline"){
        //constructor
        qDebug() << "Parsed Polyline\n";
    }else if(ShapeType == "Polygon"){
        //constructor
        qDebug() << "Parsed Polygon\n";
    }else if(ShapeType == "Rectangle"){
        //constructor
        qDebug() << "Parsed Rectangle\n";
    }else if(ShapeType == "Ellipse"){
        //constructor
        qDebug() << "Parsed Ellipse\n";
    }else if(ShapeType == "Text"){
        //constructor
        qDebug() << "Parsed Text\n";
    }
}

void Shape_Parser::parseInput(Shape_Vector<Shape*> &parsedInput)
{
    inputFile.open("Shapes.txt");

    std::string tmp;
    int count = 0;
    do{
        count++;
        if(count > 5000){
            qDebug() << "Error!\n";
            break;
        }
        // Begin Parsing:

        //NOTES FOR LINA

        //1. Remove colons from if statements (they are going to be ignored)
        //2. Use cin.ignore to only get info you need (e.g. ignore colon for if statements)
        //3. Ask JAY, NOT FELIX for help, because Felix wants to be left alone (and it's his birthday)


        inputFile >> tmp;
        if(tmp == "ShapeId:"){
            //use stoi
            //ShapeId = tmp;
        }else if(tmp == "ShapeType:"){
            ShapeType = tmp;
        }else if (tmp == "Dimensions"){
            //REFERENCE shape_input_file_specs.txt TO UNDERSTAND DIMENSIONS

            //...
        }else if(tmp == "PenColor:"){
            //...
        }else if(tmp == "PenWidth:"){
            //...
        }else if(tmp == "PenStyle:"){
            //...
        }else if(tmp == "PenCapStyle:"){
            //...
        }else if(tmp == "PenJoinStyle:"){
            //...
        }else if(tmp == "BrushColor:"){
            //...
        }else if(tmp == "BrushStyle:"){
            BrushStyle = tmp;
        }else if(tmp == "TextQString"){
            //...
        }else if(tmp == "TextColor:"){
            //...
        }else if(tmp == "TextAlignment:"){
            //...
        }else if(tmp == "TextPointSize:"){
            //...
        }else if(tmp == "TextFontFamily:"){
            //...
        }else if(tmp == "TextFontStyle:"){
            //...
        }else if(tmp == "TextFontWeight:"){
            //...
        }else if(tmp == "--END-SHAPE--"){
            //translate
            setDefaults();	// Reset evreything in parse class to defaults to eliminate cross-contamination.
        }
    }while(tmp != "--END-FILE--");
    inputFile.close();
}


void Shape_Parser::setDefaults()
{

}
