#include "cConfig.h"

cConfig::cConfig()
{
}

int cConfig::menuConfig() const
{
    uiPtr_->showConfig();
    return 0;
}

int cConfig::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
