#include "UI.h"

UI::UI() : QMainWindow()
{
    // Setup widget stack with all windows
    winStack_.addWidget(&winMainObj_);
    winStack_.addWidget(&winConfigObj_);

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

// Setters and getters
int UI::setCAddRemove(cAddRemove *ptr)
{
    cAddRemovePtr_ = ptr;
    return 0;
}
cAddRemove * UI::getCAddRemove()
{
    return cAddRemovePtr_;
}

int UI::setCConfig(cConfig *ptr)
{
    cConfigPtr_ = ptr;
    return 0;
}
cConfig * UI::getCConfig()
{
    return cConfigPtr_;
}

QStackedWidget * UI::getStack()
{
    return &winStack_;
}

// Show methods
int UI::showConfig()
{
    winStack_.setCurrentWidget(&winConfigObj_);
    return 0;
}

int UI::showMain()
{
    winStack_.setCurrentWidget(&winMainObj_);
    return 0;
}

