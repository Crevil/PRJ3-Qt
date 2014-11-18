#include "UI.h"

UI::UI()
{
    current_ = &winMainObj_;
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

int UI::setCurrent(QWidget *ptr)
{
    current_ = ptr;
    return 0;
}
QWidget * UI::getCurrent()
{
    return current_;
}
