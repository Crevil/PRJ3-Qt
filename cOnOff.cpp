#include "cOnOff.h"

cOnOff::cOnOff()
{
}

int cOnOff::menuOnOff() const
{
    uiPtr_->showOnOff();
    return 0;
}

int cOnOff::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
