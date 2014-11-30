#include "cAddRemove.h"
#include <iostream>

cAddRemove::cAddRemove()
{

}


int cAddRemove::menuAddRemove() const
{
    uiPtr_->showAddRemove();
    return 0;
}

int cAddRemove::setUI(UI & ptr)
{
    uiPtr_ = &ptr;
    return 0;
}

int cAddRemove::menuAbort() const
{
    uiPtr_->showMain();
}
