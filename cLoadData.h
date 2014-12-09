#ifndef CLOADDATA_H
#define CLOADDATA_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QDebug>

#include <vector>
#include <string>
#include <iostream>

#include "SPI_api.h"
#include "log.h"

#define GETDATATIMEOUT 15    // in sec

class cLoadData : public QObject
{
    Q_OBJECT
public:
    explicit cLoadData(SPI_api * SPIPtr, log * logPtr, QObject *parent = 0);
    ~cLoadData();
private:
    SPI_api * SPI_apiPtr_;
    log * logPtr_;

signals:

public slots:
    void getData();
};

#endif // CLOADDATA_H
