#include "UI.h"

UI::UI(QWidget * parent)
{
    winMainObj_ = new winMain(this);
    winConfigObj_ = new winConfig(this);
    current_ = winMainObj_;
}

UI::~UI()
{
    delete winMainObj_;
    delete winConfigObj_;
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

int UI::setCurrent(QWidget *ptr)
{
    current_ = ptr;
    return 0;
}
QWidget * UI::getCurrent()
{
    return current_;
}

// Show methods
int UI::showConfig()
{
    current_ = winConfigObj_;
    current_->show();
    return 0;
}
