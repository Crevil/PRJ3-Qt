#ifndef CADDREMOVE_H
#define CADDREMOVE_H

#include "UI.h"

class cAddRemove
{
public:
    cAddRemove();

    int menuAddRemove() const;
    int setUI(UI * uiPtr);

private:
    UI * uiPtr_;
};

#endif // CADDREMOVE_H
