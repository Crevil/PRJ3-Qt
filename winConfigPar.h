#ifndef WINCONFIGPAR_H
#define WINCONFIGPAR_H

#include <QWidget>

namespace Ui {
class winConfigPar;
}

class winConfigPar : public QWidget
{
    Q_OBJECT

public:
    explicit winConfigPar(QWidget *parent = 0);
    ~winConfigPar();

public slots:
    void on_bAbort_clicked();
    void on_bSave_clicked();

private:
    Ui::winConfigPar *ui;
};

#endif // WINCONFIGPAR_H
