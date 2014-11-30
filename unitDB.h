#ifndef UNITDB_H
#define UNITDB_H

#include <QVector>
#include <QString>

class unitDB
{
public:
    unitDB();
    ~unitDB();

    int getUnits( QVector<QVector<QString > > * units);
    int saveUnit( QString );

private:
    QVector<QVector<QString > > * unitDB_;
    int max_;
    int size_;

};

#endif // UNITDB_H
