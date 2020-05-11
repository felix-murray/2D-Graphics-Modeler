#ifndef CUSTOMERTEST_H
#define CUSTOMERTEST_H

#include <QDialog>

namespace Ui {
class customertest;
}

class customertest : public QDialog
{
    Q_OBJECT

public:
    explicit customertest(QWidget *parent = nullptr);
    ~customertest();

private:
    Ui::customertest *ui;
};

#endif // CUSTOMERTEST_H
