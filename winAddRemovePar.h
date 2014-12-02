#ifndef WINADDREMOVEPAR_H
#define WINADDREMOVEPAR_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class winAddRemovePar;
}

class winAddRemovePar : public QWidget
{
    Q_OBJECT

public:
    explicit winAddRemovePar(QWidget *parent = 0);
    ~winAddRemovePar();

    QComboBox * getBane();
    QSpinBox * getTemp();
    QSpinBox * getHumi();

public slots:
    void on_bAbort_clicked();
    void on_bSave_clicked();

private:
    Ui::winAddRemovePar *ui;
};

#endif // WINADDREMOVEPAR_H
