#ifndef CLOGVIEW_H
#define CLOGVIEW_H

#include "UI.h"

class cLogView
{
public:
    cLogView();

    int menuLog() const;
    int setUI(UI & ptr);
private:
    UI * uiPtr_;
};

#endif // CLOGVIEW_H
