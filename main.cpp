#include <QApplication>
#include <QThread>
#include <QtDebug>


//#include "UI.h"    // UI controller

// Controllers
#include "cStatus.h"
#include "cOnOff.h"
#include "cAddRemove.h"
#include "cConfig.h"
#include "cLoadData.h"

// SPI kommunikation
#include "SPI_api.h"

// Domains
#include "unitDB.h"
#include "log.h"


int main(int argc, char *argv[])
{
    // Create Qt application
    QApplication a(argc, argv);

    // Create controllers
    cStatus cStatusObj;
    cOnOff cOnOffObj;
    cAddRemove cAddRemoveObj;
    cConfig cConfigObj;
    cLogView cLogViewObj;

    // Create domain classes
    unitDB unitDBObj;   // unitDB
    log logObj;         // log

    // Create SPI class
    SPI_api spiObj;

     //Create controller loadData in new thread
    cLoadData cLoadDataObj(&spiObj, &logObj);
    QThread * cLoadDataT = new QThread;     // Create thread
    cLoadDataObj.moveToThread(cLoadDataT);  // Move controller object to thread
    cLoadDataT->start();                    // Start thread


    UI UIObj;

    // Set association pointers in UI object
    UIObj.setCStatus(cStatusObj);
    UIObj.setCOnOff(cOnOffObj);
    UIObj.setCAddRemove(cAddRemoveObj);
    UIObj.setCConfig(cConfigObj);
    UIObj.setCLogView(cLogViewObj);

    // Set association pointers in controller objects
    cStatusObj.setUI(UIObj);
    cStatusObj.setLog(logObj);
    cOnOffObj.setUI(UIObj, unitDBObj, spiObj);
    cAddRemoveObj.setUI(UIObj, unitDBObj, spiObj);
    cConfigObj.setUI(UIObj, unitDBObj, spiObj);
    cLogViewObj.setUI(UIObj, logObj);


    // Show GUI
    UIObj.showFullScreen();
    return a.exec();
}
