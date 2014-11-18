#include "cConfig.h"

cConfig::cConfig()
{
}

int cConfig::menuConfig() const
{
    uiPtr_->showConfig();
    return 0;
}

int cConfig::setUI(UI *uiPtr)
{
    uiPtr_ = uiPtr;
    return 0;
}
