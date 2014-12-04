#include "log.h"
#include <iostream>
#include "QDebug"

log::log() : log_(new QVector<QVector<QString> >), latest_(new QVector<QString>)
{
    // test log

    QVector<QString> pushThis;


    pushThis.push_front(QString::number(0));
    pushThis.push_front(QString::number(0));
    pushThis.push_front(QString::number(54));
    pushThis.push_front(QString::number(22.1));

    log_->push_front(pushThis);

    pushThis.push_front(QString::number(1));
    pushThis.push_front(QString::number(0));
    pushThis.push_front(QString::number(89));
    pushThis.push_front(QString::number(32.1));

    for(int i = 0; i < 4; i++)
    {
       latest_->push_back(pushThis.at(i));
    }
    log_->push_front(pushThis);
}

int log::saveLog( QVector<QString> saveThis)
{
        log_->push_front(saveThis);
        *latest_ = saveThis;
        qDebug() << saveThis;
        qDebug("saved log");
        return 0;
}

int log::getLog( QVector<QVector<QString> > * saveHere )
{
    *saveHere = *log_;

    return 0;
}

int log::getLatest( QVector< QString > * saveHere)
{
   *saveHere = *latest_;

    return 0;
}
