#ifndef UI_H
#define UI_H

#include <QWidget>
#include "winMain.h"
#include "winConfig.h"
#include "cAddRemove.h"
#include "cConfig.h"

// Forward decleration
class cAddRemove;
class cConfig;

class UI : public QWidget
{
    Q_OBJECT

public:
    explicit UI(QWidget * parent = 0);
    ~UI();

    // Setters / getters
    int setCAddRemove(cAddRemove *);
    cAddRemove * getCAddRemove();
    int setCConfig(cConfig *);
    cConfig * getCConfig();
    QWidget * getCurrent();
    int setCurrent(QWidget *);

    // Show methods
    int showConfig();

private:
    // Window QWidgets
    winConfig * winConfigObj_;
    winMain * winMainObj_;

    QWidget * current_;

    // Controller pointers
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
};

#endif // UI_H
