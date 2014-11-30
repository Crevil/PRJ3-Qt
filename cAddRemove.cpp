#include "cAddRemove.h"
#include <iostream>

cAddRemove::cAddRemove()
{

}


int cAddRemove::menuAddRemove() const
{
    QListWidget * myList = uiPtr_->getWinAddRemove()->getList();

    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString > >;

    unitsPtr_->getUnits( uPtr );

    for(int i = 0; i < uPtr->size(); ++i)
    {
        QString string = uPtr->at(i).at(0);
        myList->addItem( string );
    }

    uiPtr_->showAddRemove();
    return 0;
}

int cAddRemove::setUI(UI & ptr, unitDB & unitPtr)
{
    unitsPtr_ = &unitPtr;
    uiPtr_ = &ptr;
    return 0;
}

int cAddRemove::menuAbort() const
{
    QListWidget * myList = uiPtr_->getWinAddRemove()->getList();
    myList->clear();
    uiPtr_->showMain();
}

int cAddRemove::remove()
{
    QListWidget * myList = uiPtr_->getWinAddRemove()->getList();

    int row = myList->currentRow();

    QListWidgetItem * item = myList->item(row);
    delete item;
}

int cAddRemove::add()
{
    QListWidget * myList = uiPtr_->getWinAddRemove()->getList();


}
