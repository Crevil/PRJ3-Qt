#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>
#include "winMain.h"
#include "winConfig.h"
#include "cAddRemove.h"
#include "cConfig.h"

// Forward decleration
class cAddRemove;
class cConfig;

class UI : public QMainWindow
{
public:
    UI();
    ~UI();

    // Setters / getters
    int setCAddRemove(cAddRemove *);
    cAddRemove * getCAddRemove();
    int setCConfig(cConfig *);
    cConfig * getCConfig();
    QWidget * getCurrent();
    int setCurrent(QWidget *);
    QStackedWidget * getStack();

    // Show methods
    int showConfig();
    int showMain();

private:
    // Stached widget to hold all windows
    QStackedWidget winStack_;

    // Window QWidgets
    winConfig winConfigObj_;
    winMain winMainObj_;

    // Controller pointers
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
};

#endif // UI_H
