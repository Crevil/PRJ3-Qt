#ifndef CONOFF_H
#define CONOFF_H

#include "UI.h"
#include "unitDB.h"
#include <QString>
#include <QListWidgetItem>
#include <QStringList>
#include "SPI_api.h"

class cOnOff
{
public:
    cOnOff();

    int menuOnOff() const;
    int menuAbort() const;
    int On() const;
    int Off() const;
    int setUI(UI & ptr, unitDB & unitPtr, SPI_api & spiPtr);
private:
    UI * uiPtr_;
    unitDB * unitsPtr_;
    SPI_api * SPI_;
};

#endif // CONOFF_H
