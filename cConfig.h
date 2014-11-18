#ifndef CCONFIG_H
#define CCONFIG_H

#include "UI.h"

class cConfig
{
public:
    cConfig();

    int menuConfig() const;
    int setUI(UI * uiPtr);
private:
    UI * uiPtr_;
};

#endif // CCONFIG_H
