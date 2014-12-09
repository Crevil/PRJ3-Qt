#include "cConfig.h"

cConfig::cConfig()
{
}

int cConfig::menuConfig() const
{
    QTableWidget * myTable = uiPtr_->getWinConfig()->getTable();
    myTable->clearContents();

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
                    string.append(" \260C");

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

    QTableWidget * myTable = uiPtr_->getWinConfig()->getTable();

    int row = myTable->currentRow();

    int temp = tempPtr->value();
    int humi = humiPtr->value();

    QString sTemp = QString::number(temp);
    QString sHumi = QString::number(humi);

    // FINDING UNIT AT THAT ROW
    QTableWidgetItem * unitNr = myTable->item(row, 0);
    QTableWidgetItem * unitTemp = myTable->item(row, 1);
    QTableWidgetItem * unitHumi = myTable->item(row, 2);

    unitTemp->setText(sTemp);
    unitHumi->setText(sHumi);


    // CONFIGURATING UNIT
    int config = SPI_->config(unitNr->text().toInt(), (float)temp, (float)humi);
        if( config != 0)
        {
            qDebug("CONFIG ERROR");
            uiPtr_->showConfig();
            return 0;
        }


    int index = unitNr->text().toInt();

    // HENT UNITS
    QVector<QVector<QString > > * uPtr = new QVector<QVector<QString> >;
    unitsPtr_->getUnits( uPtr );

    QVector<QString> vec = uPtr->at(index - 1);

    vec.operator[](1) = sTemp;
    vec.operator[](2)= sHumi;

    unitsPtr_->saveUnit(vec);

    this->menuConfig();
    return 0;
}
