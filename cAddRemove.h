#ifndef CADDREMOVE_H
#define CADDREMOVE_H

#pragma once

#include "UI.h"
#include "unitDB.h"
#include <QVector>
#include <QString>
#include <QListWidget>

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
};

#endif // CADDREMOVE_H
