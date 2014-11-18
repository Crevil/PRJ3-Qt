#ifndef WINLOG_H
#define WINLOG_H

#include <QWidget>

namespace Ui {
class winLog;
}

class winLog : public QWidget
{
    Q_OBJECT

public:
    explicit winLog(QWidget *parent = 0);
    ~winLog();

public slots:
    void on_bAbort_clicked();
private:
    Ui::winLog *ui;
};

#endif // WINLOG_H
