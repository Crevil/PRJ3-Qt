#ifndef UI_H
#define UI_H

#include <QWidget>
#include "winMain.h"
#include "winConfig.h"
#include "cAddRemove.h"
#include "cConfig.h"

class UI
{
public:
    UI();
    ~UI();

    int setCAddRemove(cAddRemove *);
    cAddRemove * getCAddRemove();
    int setCConfig(cConfig *);
    cConfig * getCConfig();

    QWidget * getCurrent();
    int setCurrent(QWidget *);

private:
    // Window QWidgets
    winConfig winConfigObj_;
    winMain winMainObj_;

    QWidget * current_;

    // Controller pointers
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
};

#endif // UI_H
