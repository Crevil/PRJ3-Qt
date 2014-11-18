#ifndef WINMAIN_H
#define WINMAIN_H

#include <QWidget>

// Forward declearation
class UI;

namespace Ui {
class winMain;
}

class winMain : public QWidget
{
    Q_OBJECT

public:
    explicit winMain(QWidget * parent = 0);
    ~winMain();

public slots:
    void on_bAddRemove_clicked();
    void on_bConfig_clicked();

private:
    Ui::winMain *ui_;
};

#endif // WINMAIN_H
