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

//*** ELLIPSE COMBO BOXES *** ///
    ui->ellipsepen_color_box->addItem("white");
    ui->ellipsepen_color_box->addItem("black");
    ui->ellipsepen_color_box->addItem("red");
    ui->ellipsepen_color_box->addItem("green");
    ui->ellipsepen_color_box->addItem("blue");
    ui->ellipsepen_color_box->addItem("cyan");
    ui->ellipsepen_color_box->addItem("magenta");
    ui->ellipsepen_color_box->addItem("yellow");
    ui->ellipsepen_color_box->addItem("gray");

    ui->ellipsepen_style_box->addItem("Solid Line");
    ui->ellipsepen_style_box->addItem("Dash Line");
    ui->ellipsepen_style_box->addItem("Dot Line");
    ui->ellipsepen_style_box->addItem("Dash Dot Line");
    ui->ellipsepen_style_box->addItem("Dash Dot Dot Line");
    ui->ellipsepen_style_box->addItem("No Pen");

    ui->ellipsepencap_style_box->addItem("Square Cap");
    ui->ellipsepencap_style_box->addItem("Flat Cap");
    ui->ellipsepencap_style_box->addItem("Round Cap");

    ui->ellipsepenjoin_style_box->addItem("BevelJoin");
    ui->ellipsepenjoin_style_box->addItem("MiterJoin");
    ui->ellipsepenjoin_style_box->addItem("RoundJoin");

    ui->ellipsebrush_color_box->addItem("white");
    ui->ellipsebrush_color_box->addItem("black");
    ui->ellipsebrush_color_box->addItem("red");
    ui->ellipsebrush_color_box->addItem("green");
    ui->ellipsebrush_color_box->addItem("blue");
    ui->ellipsebrush_color_box->addItem("cyan");
    ui->ellipsebrush_color_box->addItem("magenta");
    ui->ellipsebrush_color_box->addItem("yellow");
    ui->ellipsebrush_color_box->addItem("gray");

    ui->ellipsebrush_style_box->addItem("Solid Pattern");
    ui->ellipsebrush_style_box->addItem("Horizontal Pattern");
    ui->ellipsebrush_style_box->addItem("Vertical Pattern");
    ui->ellipsebrush_style_box->addItem("No Brush");

//*** LINE COMBO BOXES *** ///
    ui->linepen_color_box->addItem("white");
    ui->linepen_color_box->addItem("black");
    ui->linepen_color_box->addItem("red");
    ui->linepen_color_box->addItem("green");
    ui->linepen_color_box->addItem("blue");
    ui->linepen_color_box->addItem("cyan");
    ui->linepen_color_box->addItem("magenta");
    ui->linepen_color_box->addItem("yellow");
    ui->linepen_color_box->addItem("gray");

    ui->linepen_style_box->addItem("Solid Line");
    ui->linepen_style_box->addItem("Dash Line");
    ui->linepen_style_box->addItem("Dot Line");
    ui->linepen_style_box->addItem("Dash Dot Line");
    ui->linepen_style_box->addItem("Dash Dot Dot Line");
    ui->linepen_style_box->addItem("No Pen");

    ui->linepencap_style_box->addItem("Square Cap");
    ui->linepencap_style_box->addItem("Flat Cap");
    ui->linepencap_style_box->addItem("Round Cap");

    ui->linepenjoin_style_box->addItem("BevelJoin");
    ui->linepenjoin_style_box->addItem("MiterJoin");
    ui->linepenjoin_style_box->addItem("RoundJoin");

// **** TEXT COMBO BOXES **** ///
    ui->text_color_box->addItem("white");
    ui->text_color_box->addItem("black");
    ui->text_color_box->addItem("red");
    ui->text_color_box->addItem("green");
    ui->text_color_box->addItem("blue");
    ui->text_color_box->addItem("cyan");
    ui->text_color_box->addItem("magenta");
    ui->text_color_box->addItem("yellow");
    ui->text_color_box->addItem("gray");

    ui->text_allignment_box->addItem("AlignLeft");
    ui->text_allignment_box->addItem("AlignCenter");
    ui->text_allignment_box->addItem("AlignRight");
    ui->text_allignment_box->addItem("AlignCenter");
    ui->text_allignment_box->addItem("AlignBottom");

    ui->text_fontfamily_box->addItem("ComicSansMS");
    ui->text_fontfamily_box->addItem("Courier");
    ui->text_fontfamily_box->addItem("Helvetica");
    ui->text_fontfamily_box->addItem("Times");

    ui->text_fontstyle_box->addItem("StyleNormal");
    ui->text_fontstyle_box->addItem("StyleItalic");
    ui->text_fontstyle_box->addItem("StyleOblique");

    ui->text_fontweight_box->addItem("Thin");
    ui->text_fontweight_box->addItem("Light");
    ui->text_fontweight_box->addItem("Normal");
    ui->text_fontweight_box->addItem("Bold");

// *********POLY LINE COMBO BOXS ***** ///

    ui->plinepen_color_box->addItem("white");
    ui->plinepen_color_box->addItem("black");
    ui->plinepen_color_box->addItem("red");
    ui->plinepen_color_box->addItem("green");
    ui->plinepen_color_box->addItem("blue");
    ui->plinepen_color_box->addItem("cyan");
    ui->plinepen_color_box->addItem("magenta");
    ui->plinepen_color_box->addItem("yellow");
    ui->plinepen_color_box->addItem("gray");

    ui->plinepen_style_box->addItem("Solid Line");
    ui->plinepen_style_box->addItem("Dash Line");
    ui->plinepen_style_box->addItem("Dot Line");
    ui->plinepen_style_box->addItem("Dash Dot Line");
    ui->plinepen_style_box->addItem("Dash Dot Dot Line");
    ui->plinepen_style_box->addItem("No Pen");

    ui->plinepencap_style_box->addItem("Square Cap");
    ui->plinepencap_style_box->addItem("Flat Cap");
    ui->plinepencap_style_box->addItem("Round Cap");

    ui->plinepenjoin_style_box->addItem("BevelJoin");
    ui->plinepenjoin_style_box->addItem("MiterJoin");
    ui->plinepenjoin_style_box->addItem("RoundJoin");

    qDebug() << "Before Parser" << endl;
//    parser = new Shape_Parser;
//    parser->parseInput(*(ui->Canvas));
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

void MainWindow::on_ellipse_build_button_clicked()
{
    int PS = ui->ellipsepen_style_box->currentIndex();
    int PW = ui->ellipsepen_width_box->text().toInt();
    int PC = ui->ellipsepen_color_box->currentIndex();

    int PCS = ui->ellipsepencap_style_box->currentIndex();
    int PJS = ui->ellipsepenjoin_style_box->currentIndex();

    int BC = ui->ellipsebrush_color_box->currentIndex();
    int BS = ui->ellipsebrush_style_box->currentIndex();

    int X = ui->ellipse_x->text().toInt();
    int Y = ui->ellipse_y->text().toInt();
    int W = ui->ellipse_width->text().toInt();
    int H = ui->ellipse_height->text().toInt();

    Shape *ellipse = new Ellipse(PS, PW, PC, PCS, PJS, BC, BS, X , Y, W, H);

    ui->Canvas->addShape(ellipse);

    ui->Canvas->update();
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

void MainWindow::on_line_build_button_clicked()
{
    int PS = ui->linepen_style_box->currentIndex();
    int PW = ui->linepen_width_box->text().toInt();
    int PC = ui->linepen_color_box->currentIndex();

    int PCS = ui->linepencap_style_box->currentIndex();
    int PJS = ui->linepenjoin_style_box->currentIndex();

    QPoint P1(ui->line_x->text().toInt(), ui->line_y->text().toInt());
    QPoint P2(ui->line_width->text().toInt(), ui->line_height->text().toInt());

    Shape *line = new Line(PS, PW, PC, PCS, PJS, -1, -1, P1, P2);

    ui->Canvas->addShape(line);

    ui->Canvas->update();
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

void MainWindow::on_pline_build_button_clicked()
{
    int PS = ui->plinepen_style_box->currentIndex();
    int PW = ui->plinepen_width_box->text().toInt();
    int PC = ui->plinepen_color_box->currentIndex();

    int PCS = ui->plinepencap_style_box->currentIndex();
    int PJS = ui->plinepenjoin_style_box->currentIndex();

    int NP = ui->plinepen_numpts_box->text().toInt();

    QPoint PV[NP];

    for(int i = 0; i < NP; i++)
    {
        if(i == 0)
        {
            QPoint p1(ui->pline_x1->text().toInt(), ui->pline_y1->text().toInt());
            PV[i] =p1;
        }
        if(i == 1)
        {
            QPoint p2(ui->pline_x2->text().toInt(), ui->pline_y2->text().toInt());
            PV[i] = p2;
        }
        if(i == 2)
        {
            QPoint p3(ui->pline_x3->text().toInt(), ui->pline_y3->text().toInt());
            PV[i] = p3;
        }
        if(i == 3)
        {
            QPoint p4(ui->pline_x4->text().toInt(), ui->pline_y4->text().toInt());
            PV[i] = p4;
        }
        if(i == 4)
        {
            QPoint p5(ui->pline_x5->text().toInt(), ui->pline_y5->text().toInt());
            PV[i] = p5;
        }
    }

    Shape *polyline = new Polyline(PS, PW, PC, PCS, PJS, -1, -1, NP, PV);


    ui->Canvas->addShape(polyline);

    ui->Canvas->update();
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

void MainWindow::on_text_build_button_clicked()
{
    QString text = ui->text_box->toPlainText();
    int color = ui->text_color_box->currentIndex();
    int font = ui->text_fontfamily_box->currentIndex();
    int align = ui->text_allignment_box->currentIndex();
    int style = ui->text_fontstyle_box->currentIndex();
    int weight = ui->text_fontweight_box->currentIndex();

    int boxW = ui->text_box_width->text().toInt();
    int boxH = ui->text_box_height->text().toInt();

    QPoint P(ui->text_x->text().toInt(), ui->text_y->text().toInt());

    Shape *line = new Text(text, color, font, align, style, weight, boxW, boxH, P);

    ui->Canvas->addShape(line);

    ui->Canvas->update();
}

void MainWindow::on_canceltext_button_clicked()
{
        on_cancel_button_clicked();
}

void MainWindow::on_select_button_clicked()
{
    ui->menustack->addWidget(ui->selection_page);
    ui->menustack->setCurrentWidget(ui->selection_page);
}
