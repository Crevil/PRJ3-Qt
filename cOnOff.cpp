#include "cOnOff.h"

cOnOff::cOnOff()
{
}

int cOnOff::menuOnOff() const
{
    // unitDB_->getUnits();

    QListWidget * myList = uiPtr_->getWinOnOff()->getList();

    for(int i = 1; i < 5; i++)
    {
        QString string = QString::number(i);
        string.prepend("bane ");
        string.append("  [Deaktiv]");
        myList->addItem( string);
    }
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

    int row = myList->currentRow();

   // if(SpiPtr_->activate( row + 1) == 0)
    //{
        QListWidgetItem * item = myList->item(row);

        QString string = QString::number(row +1);
        string.prepend("bane ");
        string.append("  [Aktiv]");
        item->setText(string);
   // }




}

int cOnOff::Off() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();

    int row = myList->currentRow();

      // if(SpiPtr_->deactivate( row + 1) == 0)
   // {
        QListWidgetItem * item = myList->item(row);

        QString string = QString::number(row +1);
        string.prepend("bane ");
        string.append("  [Deaktiv]");
        item->setText(string);
   // }


}

int cOnOff::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}
