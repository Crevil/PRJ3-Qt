#ifndef CSTATUS_H
#define CSTATUS_H

#include "UI.h"
#include "log.h"
#include "ui_winStatus.h"

class cStatus
{
public:
    cStatus();

    int menuStatus() const;
    int setUI(UI & ptr);
    int setLog(log & ptr);
    int menuAbort() const;
private:
    UI * uiPtr_;
    log * logPtr_;
};

#endif // CSTATUS_H
