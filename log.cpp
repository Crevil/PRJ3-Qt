#include "log.h"
#include <iostream>
#include "QDebug"

log::log() : log_(new QVector<QVector<QString> >), latest_(new QVector<QString>)
{
}

log::~log()
{
    delete log_;
    delete latest_;
}

int log::saveLog( QVector<QString> saveThis)
{
        log_->push_front(saveThis);
        *latest_ = saveThis;
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
