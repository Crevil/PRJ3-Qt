#include "cOnOff.h"
#include "QDebug"

cOnOff::cOnOff()
{
}

int cOnOff::menuOnOff() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();

    // HENT UNITS
    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
    unitsPtr_->getUnits( uPtr );

    QVector<QVector<QListWidgetItem *> *> * allUnits = new QVector<QVector<QListWidgetItem *> *>;

    QString minus = QString::number(-1);

    for(int i = 0; i < uPtr->size(); i++)
    {
        allUnits->push_front(new QVector<QListWidgetItem *>);

        QVector<QString> vec = uPtr->at(i);

        if(vec.at(2)  != minus )
        {
            QVector<QListWidgetItem *> * uItem = allUnits->at(i);

            uItem->push_front(new QListWidgetItem());

            QString string = vec.at(0);
            QString status = vec.at(3);
            string.append(status);
            string.prepend("Hul ");
            uItem->at(0)->setText(string);
            myList->addItem(string);
        }
    }

    uiPtr_->showOnOff();
    return 0;
}

int cOnOff::menuAbort() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();
    myList->clear();
    uiPtr_->showMain();

    return 0;
}

int cOnOff::On() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();

    int row = myList->currentRow();

    QListWidgetItem * item = myList->item(row);
    QString unitNr = item->text().mid(3, 3);

    int indexNr = unitNr.toInt();

    // SPI KONTROL
    int error = SPI_->activate( indexNr );
        //int error = 0; // DELETE THIS
    if(error == 0)
    {
        // HENT UNITS
        QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
        unitsPtr_->getUnits( uPtr );

        QVector<QString> vec = uPtr->at(indexNr - 1);

        vec.operator[](3) = " [Aktiv]";

        unitsPtr_->saveUnit(vec);

        QString string = vec.at(0);
        string.prepend("Hul ");
        string.append(" [Aktiv]");
        item->setText(string);
    }
    else
         qDebug("activate failed");

    return 0;
}

int cOnOff::Off() const
{
    QListWidget * myList = uiPtr_->getWinOnOff()->getList();

    int row = myList->currentRow();

    QListWidgetItem * item = myList->item(row);
    QString unitNr = item->text().mid(3, 3);

    int indexNr = unitNr.toInt();

    // SPI KONTROL
    int error = SPI_->deactivate( indexNr );
       // int error = 0; // DELETE THIS
    if(error == 0)
    {
        // HENT UNITS
        QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
        unitsPtr_->getUnits( uPtr );

        QVector<QString> vec = uPtr->at(indexNr - 1);

        vec.operator[](3) = " [Deaktiv]";

        unitsPtr_->saveUnit(vec);

        QString string = vec.at(0);
        string.prepend("Hul ");
        string.append(" [Deaktiv]");
        item->setText(string);
    }
    else
        qDebug("deactivate failed");

    return 0;
}

int cOnOff::setUI(UI &ptr, unitDB & unitPtr, SPI_api & spiPtr)
{
    SPI_ = &spiPtr;
    unitsPtr_ = &unitPtr;
    uiPtr_ = &ptr;
    return 0;
}
