#include "cStatus.h"

cStatus::cStatus()
{
}

int cStatus::menuStatus() const
{
    Ui::winStatus * uiElements =  uiPtr_->getWinStatus()->getUI();

    QVector<QString> data;
    logPtr_->getLatest(data);

    uiElements->tTemp->setText(data.operator [](0));
    uiElements->tHumi->setText(data.operator [](1));
    uiElements->tMove->setText((data.operator [](2) == "0") ? "Ingen" : "Nogen");
    uiElements->tSprink->setText((data.operator [](3) == "0") ? "Slukket" : "Tændt");

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
