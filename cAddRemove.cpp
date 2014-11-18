#include "cAddRemove.h"
#include <iostream>

cAddRemove::cAddRemove()
{

}

int cAddRemove::setUI(UI * ptr)
{
    uiPtr_ = ptr;
    return 0;
}

int cAddRemove::menuAddRemove() const
{
    std::cout << "menuAddRemove() called!" << std::endl;
    uiPtr_->showConfig();

    return 0;
}
