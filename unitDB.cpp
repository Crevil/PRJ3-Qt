#include "unitDB.h"
#include <iostream>

unitDB::unitDB() : unitDB_(new QVector<QVector<QString > >)
{
    QString zero = QString::number(0);
    QString minus = QString::number(-1);
    for(int i = 18; i > 0; i--)
    {
        QString init = QString::number(i);
        QVector<QString> temp;
        temp.push_front(init);
        temp.push_back(minus);
        temp.push_back(minus);
        temp.push_back(" [Deaktiv]");
        unitDB_->push_front(temp);
    }

    // TEST PURPOSE
    QVector<QString> temp;
    QString str1 = QString::number(15);
    QString str2 = QString::number(52);
    QString str3 = " [Aktiv]";

    int b = 1;
    unitDB_->operator[](b).operator[](1) = str1;
    unitDB_->operator[](b).operator[](2) = str2;
    unitDB_->operator[](b).operator[](3) = str3;
}

unitDB::~unitDB()
{
    delete unitDB_;
}

int unitDB::getUnits( QVector< QVector< QString> > * saveHere )
{
    *saveHere = *unitDB_;

    return 0;
}

int unitDB::saveUnit( QVector<QString> temp)
{
    QString str = temp.at(0);

    int index = str.toInt();
    index = (index - 1);
    unitDB_->operator[](index).operator[](1) = temp.at(1);
    unitDB_->operator[](index).operator[](2)= temp.at(2);
    unitDB_->operator[](index).operator[](3) = temp.at(3);


    return 0;

}
