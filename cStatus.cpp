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
 qDebug("got data, maybe");
    uiElements->tTemp->setText(data.at(0));
            qDebug("1");
    uiElements->tHumi->setText(data.at(1));
            qDebug("2");
    uiElements->tMove->setText((data.at(2) == "0") ? "Ingen" : "Nogen");
                               qDebug("3");
    uiElements->tSprink->setText((data.at(3) == "0") ? "Slukket" : "Tændt");
                                 qDebug("1");

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
