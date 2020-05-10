#ifndef POLYLINE_H
#define POLYLINE_H

#include "shape.h"
#include "shape_Vector.h"
#include <QObject>
#include <QPaintDevice>
#include <QPainter>

const int DEFAULT_NUM_PTS = 8; // was 8 originally

class Polyline : public Shape
{
public:
     Polyline(QPaintDevice* device = nullptr, int id = -1);
     Polyline(int PS, int PW, int PC, int PCS, int PJS, int BC, int BS, int NP, QPoint* PV);
    ~Polyline()  override {}

    void addPoint(const QPoint& pt);
    void addNumPoints(int num) {numPts = num;}

    virtual void draw(QPaintDevice *device) override;
    void move(int x, int y, int vertex) override;
    double perimeter() override {return 0;}
    double area() override {return 0;}

    Shape_Vector<QPoint>& getPoints() {return pts;}
    int getNumPoints() {return numPts;}

private:
    Shape_Vector<QPoint> pts;
    int numPts;
    QPoint pointsAr[DEFAULT_NUM_PTS];
};


#endif // POLYLINE_H
