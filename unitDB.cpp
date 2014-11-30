#include "unitDB.h"
#include <iostream>

unitDB::unitDB()
{
    unitDB_ = new QVector<QVector<QString > >;

    // TEST PURPOSE
    QVector<QString> temp;
    QString str = QString::number(1);
    str.prepend("bane ");
    str.append("  [Deaktiv]");
    temp.push_front(str);

    unitDB_->push_front(temp);
}

unitDB::~unitDB()
{
    delete unitDB_;
}

int unitDB::getUnits( QVector<QVector<QString> > * saveHere )
{
    *saveHere = *unitDB_;

    return 0;
}

int unitDB::saveUnit( QString indikator)
{

    // tjek om den findes
    for(int i = 0; i < unitDB_->size(); i++)
    {
        int position = unitDB_->at(i).at(0).indexOf(indikator);
        std::cout << indikator.toAscii().data() << " already found at: " << position << std::endl;
    }

    indikator.prepend("bane ");
    indikator.append("  [Deaktiv]");

    QVector<QString> temp;

    temp.push_front(indikator);

    unitDB_->push_back(temp);
}
