#ifndef CSTATUS_H
#define CSTATUS_H

#include "UI.h"

class cStatus
{
public:
    cStatus();

    int menuStatus() const;
    int setUI(UI & ptr);
private:
    UI * uiPtr_;
};

#endif // CSTATUS_H
