#ifndef WINSTATUS_H
#define WINSTATUS_H

#include <QWidget>

namespace Ui {
class winStatus;
}

class winStatus : public QWidget
{
    Q_OBJECT

public:
    explicit winStatus(QWidget *parent = 0);
    ~winStatus();

public slots:
    void on_bAbort_clicked();

private:
    Ui::winStatus *ui;
};

#endif // WINSTATUS_H
