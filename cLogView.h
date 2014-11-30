#ifndef CLOGVIEW_H
#define CLOGVIEW_H

#pragma once

#include "UI.h"
#include "log.h"
#include <QString>
#include <QVector>
#include <QTableWidget>
#include <QTableWidgetItem>

class cLogView
{
public:
    cLogView();

    int menuLog() const;
    int setUI(UI & ptr, log & log);
private:
    UI * uiPtr_;
    log * logPtr_;
};

#endif // CLOGVIEW_H
