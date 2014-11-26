#ifndef CONOFF_H
#define CONOFF_H

#include "UI.h"
#include <QString>
#include <QListWidgetItem>
#include <QStringList>

class cOnOff
{
public:
    cOnOff();

    int menuOnOff() const;
    int menuAbort() const;
    int On() const;
    int Off() const;
    int setUI(UI & ptr);
private:
    UI * uiPtr_;
};

#endif // CONOFF_H
