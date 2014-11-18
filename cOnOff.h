#ifndef CONOFF_H
#define CONOFF_H

#include "UI.h"

class cOnOff
{
public:
    cOnOff();

    int menuOnOff() const;
    int setUI(UI & ptr);
private:
    UI * uiPtr_;
};

#endif // CONOFF_H
