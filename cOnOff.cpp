#include "cOnOff.h"

cOnOff::cOnOff()
{
}

int cOnOff::menuOnOff() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();
    QStringList stringList;
    stringList << "bane 1" << "deaktiv" ;
    myList->addItems(stringList);
    uiPtr_->showOnOff();
    return 0;
}

int cOnOff::menuAbort() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();
    myList->clear();
    uiPtr_->showMain();
}

int cOnOff::On() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();
    QListWidgetItem * item = myList->currentItem();
}

int cOnOff::Off() const
{

}

int cOnOff::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
