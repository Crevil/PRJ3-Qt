#ifndef WINCONFIGPAR_H
#define WINCONFIGPAR_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>

namespace Ui {
class winConfigPar;
}

class winConfigPar : public QWidget
{
    Q_OBJECT

public:
    explicit winConfigPar(QWidget *parent = 0);
    ~winConfigPar();

    QSpinBox * getTemp();
    QSpinBox * getHumi();

public slots:
    void on_bAbort_clicked();
    void on_bSave_clicked();

private:
    Ui::winConfigPar *ui;
};

#endif // WINCONFIGPAR_H
