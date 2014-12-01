#ifndef CADDREMOVE_H
#define CADDREMOVE_H

#pragma once

#include "UI.h"
#include "unitDB.h"
#include <QVector>
#include <QString>
#include <QComboBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
//#include "SPI_api.h"

class cAddRemove
{
public:
    cAddRemove();

    int menuAddRemove() const;
    int menuAbort() const;
    int setUI(UI & ptr, unitDB & ptr2);

    int remove();
    int add();

private:
    UI * uiPtr_;
    unitDB * unitsPtr_;
    //SPI_api * SPI_;
};

#endif // CADDREMOVE_H
