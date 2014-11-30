#ifndef WINADDREMOVE_H
#define WINADDREMOVE_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class winAddRemove;
}

class winAddRemove : public QWidget
{
    Q_OBJECT

public:
    explicit winAddRemove(QWidget *parent = 0);
    ~winAddRemove();

    QListWidget * getList();

public slots:
    void on_bAdd_clicked();
    void on_bRemove_clicked();
    void on_bAbort_clicked();

private:
    Ui::winAddRemove *ui;
};

#endif // WINADDREMOVE_H
