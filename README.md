# Team Unicorn Group Project CS1C

## Overview
Software for modeling basic 2D graphics objects. The modeler will demonstrate the capabilities of the QT graphics engine. Potential customers will be looking for a 2D graphics rendering library which can be integrated into their own software suite.

You must use inheritance, composition, exception handlers, a virtual function, and at least two overloaded operators. At least one class should use templates. At least one class must contain a pointer (a copy constructor needs to be written and tested). Highlight the above in your code.

Uses Qt QPainter low-level graphics rendering library to draw shapes on a QWidget rendering area, implementing a ```Shape``` abstract base class which contains a QPainter data member via an aggregate relationship. Shape has pure virtual functions , ```move```, ```perimeter``` & ```area```. 

Types of Shapes: Line, Polyline, Polygon, Rectangle, Ellipse, Text. 
Shape Properties: Shape Dimensions, Pen Color, Pen Width, Pen Style, Pen Cap Style, Pen Join Style, Brush Color, Brush Style. 
Text Properties: Text String, Text Color, Text Alignment, Text Point Size, Text Font Family, Text Font Style, Text Font Weight. 

Line, Polyline, Polygon, Rectangle, Ellipse, Text Classes will override the virtual interface of base class Shape (i.e. interface inheritance).

All ```Shape``` Types are implemented as separate derived classes which inherit from ```Shape```. Overload the equality and less than relational operators in base class Shape. These overloaded operators will compare shape object ids. This will support sorting shapes by id.


You must implement the vector class as outlined in the vector.h specification below. Vector will be used to store the 2D graphics objects displayed by the modeler. Your vector class is a close approximation to the STL vector class. Vector supports the following basic operations: constructors for one or more arguments, default constructors, copy constructor, copy assignment, move constructor, move assignment and destructor. Vector also supports a basic iterator member type and member function begin() and end() operations. A partial outline/implementation of the above will be provided to the team.
