#ifndef WINLOG_H
#define WINLOG_H

#include <QWidget>
#include <QTableWidget>

namespace Ui {
class winLog;
}

class winLog : public QWidget
{
    Q_OBJECT

public:
    explicit winLog(QWidget *parent = 0);
    ~winLog();

    QTableWidget * getTable();

public slots:
    void on_bAbort_clicked();
private:
    Ui::winLog *ui;
};

#endif // WINLOG_H
