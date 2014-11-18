#include "cStatus.h"

cStatus::cStatus()
{
}

int cStatus::menuStatus() const
{
    uiPtr_->showStatus();
    return 0;
}

int cStatus::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
