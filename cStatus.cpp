#include "cStatus.h"
#include "QDebug"

cStatus::cStatus()
{
}

int cStatus::menuStatus() const
{
    Ui::winStatus * uiElements =  uiPtr_->getWinStatus()->getUI();

    QVector<QString> data;
    logPtr_->getLatest(&data);

    if(data.size() != 0)
    {
        uiElements->tTemp->setEnabled(1);
        uiElements->tHumi->setEnabled(1);
        uiElements->tMove->setEnabled(1);
        uiElements->tSprink->setEnabled(1);
        uiElements->tTemp->setText(data.at(0) + " \260C");
        uiElements->tHumi->setText(data.at(1) + " %");
        uiElements->tMove->setText((data.at(2) == "0") ? "Ingen" : "Nogen");
        uiElements->tSprink->setText((data.at(3) == "0") ? "Slukket" : QString::fromUtf8("Tændt"));
    }
    else
    {
        uiElements->tTemp->setEnabled(0);
        uiElements->tHumi->setEnabled(0);
        uiElements->tMove->setEnabled(0);
        uiElements->tSprink->setEnabled(0);
    }

        uiPtr_->showStatus();


    return 0;
}

int cStatus::menuAbort() const
{
    uiPtr_->showMain();

    return 0;
}

int cStatus::setUI(UI &ptr)
{
    uiPtr_ = &ptr;
    return 0;
}

int cStatus::setLog(log &ptr)
{
    logPtr_ = &ptr;
    return 0;
}
