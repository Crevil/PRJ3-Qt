#include "cLoadData.h"

cLoadData::cLoadData(QObject *parent) :
    QObject(parent)
{
    qDebug("cLoadData(): Called");

    // Create logData Timer
    qDebug("cLoadData(): Creating timer");
    QTimer * logTimer = new QTimer;
    QObject::connect(logTimer, SIGNAL(timeout()), this, SLOT(getData()));
    logTimer->start(GETDATATIMEOUT*1000);
}

cLoadData::~cLoadData()
{
    qDebug("~cLoadData(): Called");
}

// Thread function
void cLoadData::getData()
{
    qDebug("cLoadData.getLog(): Called");
}

