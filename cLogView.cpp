#include "cLogView.h"
#include <iostream>

cLogView::cLogView()
{
}

int cLogView::menuLog() const
{
    QTableWidget * myTable = uiPtr_->getWinLog()->getTable();

    QVector<QVector<QString> > *  myVector = new QVector<QVector<QString> >;

    logPtr_->getLog( myVector );

    QVector<QVector<QTableWidgetItem *> *> * allItem = new QVector<QVector<QTableWidgetItem *> *>;

    for(int i = 0; i < myVector->size(); i++)
    {
        QVector<QString> vec = myVector->at(i);
        allItem->push_front(new QVector<QTableWidgetItem *>);

        for(int t = 0; t < 4; t++)
        {
            QVector<QTableWidgetItem *> * item = allItem->at(i);
            item->push_front(new QTableWidgetItem());
            QString string = vec.at(t);

            if(t == 1)
                string.append(" %");

            if(t == 0)
                string.append(" \260C");

            // doesnt work ( °C )

            item->at(0)->setText(string);

            myTable->setItem(i, t, item->at(0));
        }

    }

    uiPtr_->showLog();
    return 0;
}

int cLogView::setUI(UI &ptr, log &log)
{
    uiPtr_ = &ptr;
    logPtr_ = &log;
    return 0;
}
