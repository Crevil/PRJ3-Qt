#ifndef WINONOFF_H
#define WINONOFF_H

#include <QWidget>

namespace Ui {
class winOnOff;
}

class winOnOff : public QWidget
{
    Q_OBJECT

public:
    explicit winOnOff(QWidget *parent = 0);
    ~winOnOff();

public slots:
    void on_bOn_clicked();
    void on_bOff_clicked();
    void on_bAbort_clicked();

private:
    Ui::winOnOff *ui;
};

#endif // WINONOFF_H
