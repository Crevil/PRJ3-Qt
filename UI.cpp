#include "UI.h"
#include <iostream>

UI::UI() : QMainWindow()
{
    // Setup widget stack with all windows
    winStack_.addWidget(&winMainObj_);
    winStack_.addWidget(&winStatusObj_);
    winStack_.addWidget(&winAddRemoveObj_);
    winStack_.addWidget(&winOnOffObj_);
    winStack_.addWidget(&winConfigObj_);
    winStack_.addWidget(&winConfigParObj_);
    winStack_.addWidget(&winLogObj_);

    // Set main as front
    winStack_.setCurrentWidget(&winMainObj_);

    // Fixed size and fullscreen for Devkit8000
    winStack_.setFixedSize(480, 272);
    setFixedSize(480, 272);
    //setWindowFlags(Qt::FramelessWindowHint | Qt::CustomizeWindowHint); // Uncommect to make fullscreen

    // Set central widget in MainWindow
    setCentralWidget(&winStack_);

}

UI::~UI()
{

}

//
// Setters and getters
//
int UI::setCStatus(cStatus &ptr)
{
    cStatusPtr_ = &ptr;
    return 0;
}
cStatus * UI::getCStatus() const
{
    return cStatusPtr_;
}

int UI::setCOnOff(cOnOff &ptr)
{
    cOnOffPtr_ = &ptr;
    return 0;
}
cOnOff * UI::getCOnOff() const
{
    return cOnOffPtr_;
}

winOnOff * UI::getWinOnOff()
{
    return &winOnOffObj_;
}

winLog * UI::getWinLog()
{
    return &winLogObj_;
}

winAddRemove * UI::getWinAddRemove()
{
    return &winAddRemoveObj_;
}

winConfigPar * UI::getWinConfigPar()
{
    return &winConfigParObj_;
}

int UI::setCAddRemove(cAddRemove &ptr)
{
    cAddRemovePtr_ = &ptr;
    return 0;
}
cAddRemove * UI::getCAddRemove() const
{
    return cAddRemovePtr_;
}

int UI::setCConfig(cConfig &ptr)
{
    cConfigPtr_ = &ptr;
    return 0;
}
cConfig * UI::getCConfig() const
{
    return cConfigPtr_;
}

int UI::setCLogView(cLogView &ptr)
{
    cLogViewPtr_ = &ptr;
    return 0;
}
cLogView * UI::getCLogView() const
{
    return cLogViewPtr_;
}


// Utility getters / setters
QStackedWidget * UI::getStack()
{
    return &winStack_;
}

//
// Show methods
//
int UI::showMain()
{
    winStack_.setCurrentWidget(&winMainObj_);
    return 0;
}

int UI::showStatus()
{
    winStack_.setCurrentWidget(&winStatusObj_);
    return 0;
}

int UI::showAddRemove()
{
    winStack_.setCurrentWidget(&winAddRemoveObj_);
    return 0;
}

int UI::showOnOff()
{
    winStack_.setCurrentWidget(&winOnOffObj_);
    return 0;
}

int UI::showConfig()
{
    winStack_.setCurrentWidget(&winConfigObj_);
    return 0;
}

int UI::showParam()
{
    winStack_.setCurrentWidget(&winConfigParObj_);
    return 0;
}

int UI::showLog()
{
    winStack_.setCurrentWidget(&winLogObj_);
    return 0;
}

