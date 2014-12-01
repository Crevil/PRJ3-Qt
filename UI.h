#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QStackedWidget>
#include <QMainWindow>

// Windows
#include "winMain.h"
#include "winStatus.h"
#include "winOnOff.h"
#include "winAddRemove.h"
#include "winConfig.h"
#include "winConfigPar.h"
#include "winLog.h"

// Controllers
#include "cStatus.h"
#include "cOnOff.h"
#include "cAddRemove.h"
#include "cConfig.h"
#include "cLogView.h"

// Forward decleration
class cStatus;
class cOnOff;
class cAddRemove;
class cConfig;
class cLogView;

class UI : public QMainWindow
{
public:
    UI();
    ~UI();

    // Setters / getters for controllers
    int setCStatus(cStatus &);
    cStatus * getCStatus() const;
    int setCOnOff(cOnOff &);
    cOnOff * getCOnOff() const;
    int setCAddRemove(cAddRemove &);
    cAddRemove * getCAddRemove() const;
    int setCConfig(cConfig &);
    cConfig * getCConfig() const;
    int setCLogView(cLogView &);
    cLogView * getCLogView() const;

    // window getter
    winOnOff * getWinOnOff();
    winLog * getWinLog();
    winAddRemove * getWinAddRemove();
    winConfigPar * getWinConfigPar();

    // Utility setters / getters
    int setCurrent(QWidget *);
    QWidget * getCurrent();
    QStackedWidget * getStack();

    // Show methods
    int showMain();
    int showStatus();
    int showOnOff();
    int showAddRemove();
    int showConfig();
    int showParam();
    int showLog();

private:
    // Stached widget to hold all windows
    QStackedWidget winStack_;

    // Window QWidgets
    winMain winMainObj_;
    winStatus winStatusObj_;
    winOnOff winOnOffObj_;
    winAddRemove winAddRemoveObj_;
    winConfig winConfigObj_;
    winConfigPar winConfigParObj_;
    winLog winLogObj_;

    // Controller pointers
    cStatus * cStatusPtr_;
    cOnOff * cOnOffPtr_;
    cAddRemove * cAddRemovePtr_;
    cConfig * cConfigPtr_;
    cLogView * cLogViewPtr_;

};

#endif // UI_H
