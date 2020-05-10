#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RenderArea.h"
#include "rectangle.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
           : QMainWindow(parent)
           , ui(new Ui::MainWindow)
{
    renderArea = new RenderArea;
    ui->setupUi(this);
    ui->menustack->setCurrentWidget(ui->start_page);

//*** RECTANGLE COMBO BOXES *** ///
    //rectangle pen color stuff
    ui->rectpen_color_box->addItem("white");
    ui->rectpen_color_box->addItem("black");
    ui->rectpen_color_box->addItem("red");
    ui->rectpen_color_box->addItem("green");
    ui->rectpen_color_box->addItem("blue");
    ui->rectpen_color_box->addItem("cyan");
    ui->rectpen_color_box->addItem("magenta");
    ui->rectpen_color_box->addItem("yellow");
    ui->rectpen_color_box->addItem("gray");

    ui->rectpen_style_box->addItem("Solid Line");
    ui->rectpen_style_box->addItem("Dash Line");
    ui->rectpen_style_box->addItem("Dot Line");
    ui->rectpen_style_box->addItem("Dash Dot Line");
    ui->rectpen_style_box->addItem("Dash Dot Dot Line");
    ui->rectpen_style_box->addItem("No Pen");

    ui->rectpencap_style_box->addItem("Square Cap");
    ui->rectpencap_style_box->addItem("Flat Cap");
    ui->rectpencap_style_box->addItem("Round Cap");

    ui->rectpenjoin_style_box->addItem("BevelJoin");
    ui->rectpenjoin_style_box->addItem("MiterJoin");
    ui->rectpenjoin_style_box->addItem("RoundJoin");

    ui->rectbrush_color_box->addItem("white");
    ui->rectbrush_color_box->addItem("black");
    ui->rectbrush_color_box->addItem("red");
    ui->rectbrush_color_box->addItem("green");
    ui->rectbrush_color_box->addItem("blue");
    ui->rectbrush_color_box->addItem("cyan");
    ui->rectbrush_color_box->addItem("magenta");
    ui->rectbrush_color_box->addItem("yellow");
    ui->rectbrush_color_box->addItem("gray");

    ui->rectbrush_style_box->addItem("Solid Pattern");
    ui->rectbrush_style_box->addItem("Horizontal Pattern");
    ui->rectbrush_style_box->addItem("Vertical Pattern");
    ui->rectbrush_style_box->addItem("No Brush");



}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_cancel_button_clicked()
{
    ui->menustack->addWidget(ui->start_page);
    ui->menustack->setCurrentWidget(ui->start_page);
}

void MainWindow::on_polygon_button_clicked()
{
    ui->menustack->addWidget(ui->add_polygon);
    ui->menustack->setCurrentWidget(ui->add_polygon);

}

void MainWindow::on_cancelpoly_button_clicked()
{
    on_cancel_button_clicked();
}

void MainWindow::on_rectangle_button_clicked()
{

    ui->menustack->addWidget(ui->add_rectangle);
    ui->menustack->setCurrentWidget(ui->add_rectangle);

}

void MainWindow::on_rectangle_build_button_clicked()
{

    int PS = ui->rectpen_style_box->currentIndex();
    int PW = ui->rectpen_width_box->text().toInt();
    int PC = ui->rectpen_color_box->currentIndex();

    int PCS = ui->rectpencap_style_box->currentIndex();
    int PJS = ui->rectpenjoin_style_box->currentIndex();

    int BC = ui->rectbrush_color_box->currentIndex();
    int BS = ui->rectbrush_style_box->currentIndex();

    int X = ui->rect_x->text().toInt();
    int Y = ui->rect_y->text().toInt();
    int W = ui->rect_width->text().toInt();
    int H = ui->rect_height->text().toInt();

    Shape *rectangle = new Rectangle(PS, PW, PC, PCS, PJS, BC, BS, X , Y, W, H);

    ui->Canvas->addShape(rectangle);

    ui->Canvas->update();

}

void MainWindow::on_ellipse_button_clicked()
{
    ui->menustack->addWidget(ui->add_ellipse);
    ui->menustack->setCurrentWidget(ui->add_ellipse);
}
void MainWindow::on_cancelellipse_button_clicked()
{
        on_cancel_button_clicked();
}

void MainWindow::on_line_button_clicked()
{
    ui->menustack->addWidget(ui->add_line);
    ui->menustack->setCurrentWidget(ui->add_line);
}
void MainWindow::on_cancelline_button()
{
    on_cancel_button_clicked();
}

void MainWindow::on_polyline_button_clicked()
{
    ui->menustack->addWidget(ui->add_polyline);
    ui->menustack->setCurrentWidget(ui->add_polyline);
}
void MainWindow::on_cancelpolyline_button_clicked()
{
    on_cancel_button_clicked();
}

void MainWindow::on_text_button_clicked()
{
    ui->menustack->addWidget(ui->add_text);
    ui->menustack->setCurrentWidget(ui->add_text);
}
void MainWindow::on_canceltext_button_clicked()
{
        on_cancel_button_clicked();
}



QComboBox * MainWindow::comboPenColors(QComboBox *combo)
{
    combo->addItem("white");
    combo->addItem("black");
    combo->addItem("red");
    combo->addItem("green");
    combo->addItem("blue");
    combo->addItem("cyan");
    combo->addItem("magenta");
    combo->addItem("yellow");
    combo->addItem("gray");
    return combo;
}

QComboBox * MainWindow::comboPenStyles(QComboBox *combo)
{
    combo->addItem("Solid Line");
    combo->addItem("Dash Line");
    combo->addItem("Dot Line");
    combo->addItem("Dash Dot Line");
    combo->addItem("Dash Dot Dot Line");
    combo->addItem("No Pen");
    return combo;
}

