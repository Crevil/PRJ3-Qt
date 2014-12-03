#include "cAddRemove.h"
#include <iostream>

cAddRemove::cAddRemove()
{

}


int cAddRemove::menuAddRemove() const
{
    QTableWidget * myTable = uiPtr_->getWinAddRemove()->getTable();

    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
    unitsPtr_->getUnits( uPtr );



    QVector<QVector<QTableWidgetItem *> *> * allUnits = new QVector<QVector<QTableWidgetItem *> *>;

    QString zero = QString::number(0);
    QString minus = QString::number(-1);

    int count = 0;
    for(int i = 0; i < uPtr->size(); i++)
    {
        allUnits->push_front(new QVector<QTableWidgetItem *>);

        QVector<QString> vec = uPtr->at(i);

        if(vec.at(2)  != minus )
        {

            for(int t = 0; t < 3; t++)
            {

                QVector<QTableWidgetItem *> * uItem = allUnits->at(i);

                uItem->push_front(new QTableWidgetItem());
                QString string = vec.at(t);

                if(t == 2)
                    string.append(" %");

                if(t == 1)
                    string.append(" C");

                // doesnt work ( °C )

                uItem->at(0)->setText(string);

                myTable->setItem(count, t, uItem->at(0));
            }

            count++;
        }
    }
    uiPtr_->showAddRemove();
    return 0;
}

int cAddRemove::setUI(UI & ptr, unitDB & unitPtr, SPI_api & spiPtr)
{
    SPI_ = &spiPtr;
    unitsPtr_ = &unitPtr;
    uiPtr_ = &ptr;
    return 0;
}

int cAddRemove::menuAbort() const
{
    QTableWidget * myTable = uiPtr_->getWinAddRemove()->getTable();
    myTable->clear();
    uiPtr_->showMain();

    return 0;
}

int cAddRemove::remove()
{
    QTableWidget * myTable = uiPtr_->getWinAddRemove()->getTable();

    int row = myTable->currentRow();

    for(int i = 0; i < 3; i++)
    {
        QTableWidgetItem * item = myTable->item(row, i);
        delete item;
    }

    return 0;
}

int cAddRemove::add()
{
    QComboBox* banePtr = uiPtr_->getWinAddRemovePar()->getBane();
    QSpinBox * tempPtr = uiPtr_->getWinAddRemovePar()->getTemp();
    QSpinBox * humiPtr = uiPtr_->getWinAddRemovePar()->getHumi();

    QString string = banePtr->currentText();

    // VERIFY
//    int verify = SPI_->verify( string.toInt());
//    if( verify != 0)
//    {
//        qDebug("VERIFY ERROR");
//        uiPtr_->showAddRemove();
//        return 0;
//    }

    int temp = tempPtr->value();
    int humi = humiPtr->value();

    QString sTemp = QString::number(temp);
    QString sHumi = QString::number(humi);


    // CONFIGURATING UNIT
//    int config = SPI_->config(string.toInt(), (float)temp, (float)humi);
//        if( config != 0)
//        {
//            qDebug("CONFIG ERROR");
//            uiPtr_->showAddRemove();
//            return 0;
//        }

    // HENT UNITS
    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
    unitsPtr_->getUnits( uPtr );

    int row = string.toInt();
    QVector<QString> vec = uPtr->at(row-1);

    vec.operator[](1) = sTemp;
    vec.operator[](2)= sHumi;

    unitsPtr_->saveUnit(vec);

    this->menuAddRemove();
    return 0;
}

