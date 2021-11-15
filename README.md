# Saddleback College CS 1C Final Project: 2D Graphics Modeler

## Overview
Software for modeling basic 2D graphics objects. The modeler will demonstrate the capabilities of the QT graphics engine by using Qt QPainter low-level graphics rendering library to draw shapes on a QWidget rendering area. A ```Shape``` abstract base class which contains a ```QPainter``` data member via an aggregate relationship handles all rendering; ```Shape``` has pure virtual functions , ```move```, ```perimeter``` & ```area```. This program demononstrates usage of inheritance, composition, exception handlers, virtual functions, and overloaded operators in an object-oriented design program.

Types of Shapes: 
- ```Line```
- ```Polyline```
- ```Polygon```
- ```Rectangle```
- ```Ellipse```
- ```Text```
 
Shape Properties: 
- ```Shape Dimensions```
- ```Pen Color```
- ```Pen Width```
- ```Pen Style```
- ```Pen Cap Style```
- ```Pen Join Style```
- ```Brush Color```
- ```Brush Style```

Text Properties: 
- ```String```
- ```Color```
- ```Alignment```
- ```Point Size```
- ```Font Family```
- ```Font Style```
- ```Font Weight``` 

```Line```, ```Polyline```, ```Polygon```, ```Rectangle```, ```Ellipse```, and ```Text``` Classes override the virtual interface of base class Shape (i.e. interface inheritance). All ```Shape``` Types are implemented as separate derived classes which inherit from ```Shape```. 
