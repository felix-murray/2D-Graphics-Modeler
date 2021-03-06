#ifndef RenderArea_H
#define RenderArea_H



#include <QFile>
#include <QTextStream>
#include "shape.h"
#include "shape_Vector.h"
#include <QPaintEvent>
#include <QWidget>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>

class RenderArea : public QWidget
{
    public:
        RenderArea(QWidget *parent = nullptr);

        void paintEvent(QPaintEvent *event) override; //Paint event ovverride
        QSize sizeHint() const override;
        QSize minimumSizeHint() const override;

        const Shape_Vector<Shape*>& getShapes();

        void addShape(Shape* shapeIn);

        int getSize();
        int getnumShapesRA();

        void chopShape(int indexRemove);//Shape remove
        void moveShape(int indexMove, int coordMove, int x, int y); //Move shape

   //     void writeShapeFile(); //Writing to shape File

   private:
        const QImage renderArea;
        Shape_Vector<Shape*> ShapeMagazine;
        int numShapesRA;

        void readShapeFile();

        QString getStringColor(QColor color);
        QString getStringPenCap(Qt::PenCapStyle penCapStyle);
        QString getStringPenStyle(Qt::PenStyle penStyle);
        QString getStringPenJointStyle(Qt::PenJoinStyle penJointStyle);
        QString getStringBrush(Qt::BrushStyle brush);
        QString getStringFlag(Qt::AlignmentFlag  flag);
        QString getStringFontStyle(QFont::Style fontStyle);
        QString getStringFontWeight(int fontWeight);

        Shape::Shapes  getShapeType(QString shape);
        Qt::GlobalColor   getColor(QString color);
        Qt::PenCapStyle   getPenCapStyle(QString cap);
        Qt::PenStyle      getPenStyle(QString pen);
        Qt::PenJoinStyle  getPenJointStyle(QString penJoint);
        Qt::BrushStyle    getBrushStyle(QString brushStyle);
        Qt::AlignmentFlag getFlag(QString flag);
        QFont::Style      getFontStyle(QString fontStyle);
        QFont::Weight     getFontWeight(QString fontWeight);
};


#endif // RenderArea_H
