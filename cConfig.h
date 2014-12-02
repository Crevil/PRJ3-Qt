#ifndef CCONFIG_H
#define CCONFIG_H

#include "UI.h"

class cConfig
{
public:
    cConfig();

    int menuConfig() const;
    int setUI(UI & uiptr, unitDB & unitPtr, SPI_api & spiPtr);

    int config();

private:
    UI * uiPtr_;
    unitDB * unitsPtr_;
    SPI_api * SPI_;
};

#endif // CCONFIG_H
