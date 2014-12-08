#ifndef UNITDB_H
#define UNITDB_H

#include <QVector>
#include <QString>

class unitDB
{
public:
    unitDB();
    ~unitDB();

    int getUnits( QVector<QVector<QString> > * units);
    int saveUnit( QVector<QString> temp );

private:
    QVector<QVector<QString > > * unitDB_;
};

#endif // UNITDB_H
