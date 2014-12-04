#include "cLoadData.h"

cLoadData::cLoadData(SPI_api * SPIPtr, log * logPtr, QObject *parent) :
    QObject(parent), SPI_apiPtr_(SPIPtr), logPtr_(logPtr)
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
    qDebug("cLoadData.getData(): Called");

    // Create temp Qstring vector
    std::vector<std::string> tempVec;

    // Get data from SPI
    int test = SPI_apiPtr_->getLog(tempVec, NULL, 0);   // Last two arguments are dummy


    if(test != 0 || tempVec.size() == 0)
        return;

    // Convert data from std::vector<string> to QVector<QString>
    QVector<QString> tempQVecData;
    QVector<QString> tempQVecErr;
    QString tempQString;

    for(unsigned int i = 0; i < tempVec.size(); i++)
    {
        tempQString = QString::fromStdString(tempVec[i]);
        if(tempQString[0] == 'D')   // Save only data
            tempQVecData.push_back(tempQString);
        else
            tempQVecErr.push_back(tempQString);
    }

    // Send data to log
    qDebug("size after copy");
    qDebug() << tempVec.size();
    logPtr_->saveLog(tempQVecData);
}

