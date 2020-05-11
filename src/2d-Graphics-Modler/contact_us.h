#ifndef CONTACT_US_H
#define CONTACT_US_H

#include <QDialog>

namespace Ui {
class contact_us;
}

class contact_us : public QDialog
{
    Q_OBJECT

public:
    explicit contact_us(QWidget *parent = nullptr);
    ~contact_us();

private:
    Ui::contact_us *ui;
};

#endif // CONTACT_US_H
