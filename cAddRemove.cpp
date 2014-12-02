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
    QComboBox* banePtr = uiPtr_->getWinConfigPar()->getBane();
    QSpinBox * tempPtr = uiPtr_->getWinConfigPar()->getTemp();
    QSpinBox * humiPtr = uiPtr_->getWinConfigPar()->getHumi();

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

    // CONFIGURATING UNIT
//    int config = SPI_->config(string.toInt(), (float)temp, (float)humi);
//        if( config != 0)
//        {
//            qDebug("CONFIG ERROR");
//            uiPtr_->showAddRemove();
//            return 0;
//        }




    QVector<QString> vec;

    vec.push_front(string);
    vec.push_back(QString::number(temp));
    vec.push_back(QString::number(humi));
    unitsPtr_->saveUnit(vec);

    //*************** DISPLAYING UPDATED TABLE *************//

//    QTableWidget * myTable = uiPtr_->getWinAddRemove()->getTable();

//    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
//    unitsPtr_->getUnits( uPtr );

//    // kontroltal
//    QString zero = QString::number(0);
//    int count = 0;
//    QVector<QVector<QTableWidgetItem *> *> * allUnits = new QVector<QVector<QTableWidgetItem *> *>;

//    for(int i = 0; i < uPtr->size(); i++)
//    {
//        allUnits->push_front(new QVector<QTableWidgetItem *>);

//        QVector<QString> vec = uPtr->at(i);

//        if(vec.at(1) != zero && vec.at(2)  != zero )
//        {
//            count ++;
//            for(int t = 0; t < 3; t++)
//            {

//                QVector<QTableWidgetItem *> * uItem = allUnits->at(i);
//                uItem->push_front(new QTableWidgetItem());
//                QString string = vec.at(t);

//                if(t == 2)
//                    string.append(" %");

//                if(t == 1)
//                    string.append(" C");

//                // doesnt work ( °C )

//                uItem->at(0)->setText(string);

//                myTable->setItem(count, t, uItem->at(0));
//            }
//        }
//    }

//    uiPtr_->showAddRemove();
//    return 0;

    this->menuAddRemove();
    return 0;
}

