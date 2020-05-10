#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

// Class Definition for Class Ellipse
class Ellipse : public Shape
{
public:
    
    // Constructor using QPaintDevice
    Ellipse(QPaintDevice* device = nullptr, int id = -1);

    // Default destructor
    ~Ellipse() override {}
    Ellipse(int num, QColor PC);

    // Class functions
    void move(int x, int y, int na) override;
    void draw(QPaintDevice* device) override;
    
    // Functions to calculate area and perimeter
    double area() override;
    double perimeter() override;

    // Getter Functions
    double getWidth();
    double getHeight();
    QPoint& getLocation();

    // Setter Functions
    void setDimensions(double w, double h);
    void setLocation(int x, int y);
    void setLocation(QPoint pt);

private:
    // Class Vars
    double width;
    double height;
    QPoint location;
};

#endif // ELLIPSE_H
