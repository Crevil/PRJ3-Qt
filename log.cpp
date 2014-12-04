#include "log.h"
#include <iostream>

log::log() : log_(new QVector<QVector<QString> >)
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

    latest_ = pushThis;
    log_->push_front(pushThis);
}

int log::saveLog( QVector<QString> saveThis)
{
        log_->push_front(saveThis);
        latest_ = saveThis;
        return 0;
}

int log::getLog( QVector<QVector<QString> > * saveHere )
{
    *saveHere = *log_;

    return 0;
}

int log::getLatest( QVector< QString > & saveHere)
{
    saveHere = latest_;

    return 0;
}
