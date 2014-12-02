#ifndef WINCONFIG_H
#define WINCONFIG_H

#include <QWidget>
#include <QTableWidget>

// Forward declearation
class UI;

namespace Ui {
class winConfig;
}

class winConfig : public QWidget
{
    Q_OBJECT

public:
    explicit winConfig(QWidget *parent = 0);
    ~winConfig();

    QTableWidget * getTable();

    int row_;
    int column_;

public slots:
    void on_bAbort_clicked();
    void on_tUnits_cellPressed(int row, int column);

private:
    Ui::winConfig *ui;
};

#endif // WINCONFIG_H
