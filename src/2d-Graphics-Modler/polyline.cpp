#include "polyline.h"



void Polyline::addPoint(const QPoint& pt)
{
    pts.push_back(pt);
    numPts++;
}

void Polyline::draw(QPaintDevice *device)
{
    painter.begin(device);
    for(int i = 0; i < numPts; i++)
        pointsAr[i] = pointsAr[i];
    painter.setPen(getPen());
    painter.setBrush(getBrush());
    painter.drawPolyline(pointsAr, numPts);
    painter.drawText(pointsAr[0],QString::number(getID()));
    painter.end();
}

void Polyline::move(int x, int y, int vertex)
{
    QPoint temp(x , y);
        pointsAr[vertex - 1] = temp;
        pts.set(vertex - 1, temp);

}
