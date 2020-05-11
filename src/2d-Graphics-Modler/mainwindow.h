#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include <QObject>
#include <QComboBox>
#include "RenderArea.h"
#include "rectangle.h"
#include "text.h"
#include "line.h"
#include "ellipse.h"
#include "RenderArea.h"
#include "polyline.h"
#include "polygon.h"
#include "RenderArea.h"
#include "rectangle.h"
#include "contact_us.h"
#include "signin.h"
#include "customertest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void getShapeType();
    void getPenColor();
    void getPenStyle();
    void getPenCapStyle();
    void getPenJoinStyle();
    void getBrushColor();
    void getBrushStyle();
    void getAlign();
    void getTextColor();
    void getTextWeight();
    void getTextStyle();
    void getFontFamily();
    void getPenWidth();


private slots:
    void on_polygon_button_clicked();
    void on_cancelpoly_button_clicked();

    void on_rectangle_button_clicked();
    void on_rectangle_build_button_clicked();
    void on_cancel_button_clicked();

    void on_ellipse_button_clicked();
    void on_ellipse_build_button_clicked();
    void on_cancelellipse_button_clicked();

    void on_line_button_clicked();
    void on_line_build_button_clicked();
    void on_cancelline_button();

    void on_polyline_button_clicked();
    void on_pline_build_button_clicked();
    void on_cancelpolyline_button_clicked();

    void on_text_button_clicked();
    void on_text_build_button_clicked();
    void on_canceltext_button_clicked();

    void on_select_button_clicked();

    void on_contact_us_button_clicked();

    void on_login_button_clicked();

    void on_cm_button_clicked();




private:
    Ui::MainWindow *ui;

        RenderArea *renderArea;

        //Shape_Vector<Shape> shapeList;

        QComboBox *shapeComboBox;
        QComboBox *penStyleComboBox;
        QComboBox *penCapComboBox;
        QComboBox *penJoinComboBox;
        QComboBox *brushStyleComboBox;


    int              The_penWidth{4};


};
#endif // MAINWINDOW_H
