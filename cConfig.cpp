#include "cConfig.h"

cConfig::cConfig()
{
}

int cConfig::menuConfig() const
{
    QTableWidget * myTable = uiPtr_->getWinConfig()->getTable();

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
    uiPtr_->showConfig();
    return 0;
}

int cConfig::setUI(UI & uiPtr, unitDB & unitPtr, SPI_api & spiPtr)
{
    SPI_ = &spiPtr;
    unitsPtr_ = &unitPtr;
    uiPtr_ = &uiPtr;
    return 0;
}

int cConfig::config()
{
    QSpinBox * tempPtr = uiPtr_->getWinConfigPar()->getTemp();
    QSpinBox * humiPtr = uiPtr_->getWinConfigPar()->getHumi();

    int row = uiPtr_->getWinConfig()->row_;
    row++;

    int temp = tempPtr->value();
    int humi = humiPtr->value();

    QString sTemp = QString::number(temp);
    QString sHumi = QString::number(humi);

    // FINDING UNIT AT THAT ROW
    QTableWidget * myTable = uiPtr_->getWinConfig()->getTable();

    QTableWidgetItem * unitNr = myTable->itemAt(row, 0);
    QTableWidgetItem * unitTemp = myTable->itemAt(row, 1);
    QTableWidgetItem * unitHumi = myTable->itemAt(row, 2);

    unitTemp->setText(sTemp);
    unitHumi->setText(sHumi);

    //myTable->editItem();

    // CONFIGURATING UNIT
//    int config = SPI_->config(string.toInt(), (float)temp, (float)humi);
//        if( config != 0)
//        {
//            qDebug("CONFIG ERROR");
//            uiPtr_->showAddRemove();
//            return 0;
//        }

    QVector<QString> vec;

    vec.push_front(QString::number(row + 1));
    vec.push_back(QString::number(temp));
    vec.push_back(QString::number(humi));
    unitsPtr_->saveUnit(vec);

    this->menuConfig();
}
