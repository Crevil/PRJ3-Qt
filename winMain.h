#ifndef WINMAIN_H
#define WINMAIN_H

#include <QWidget>

namespace Ui {
class winMain;
}

class winMain : public QWidget
{
    Q_OBJECT

public:
    explicit winMain(QWidget *parent = 0);
    ~winMain();

    Ui::winMain * getUi() const;

public slots:
    void on_bAddRemove_clicked();
    void on_bConfig_clicked();


private:
    Ui::winMain *ui_;

};

#endif // WINMAIN_H
