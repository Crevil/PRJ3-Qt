#include <QApplication>
#include <QThread>

//#include "UI.h"    // UI controller

// Controllers
#include "cStatus.h"
#include "cOnOff.h"
#include "cAddRemove.h"
#include "cConfig.h"
#include "cLoadData.h"

// Domains
#include "unitDB.h"


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

    // Create controller loadData in new thread
    cLoadData cLoadDataObj;
    QThread * cLoadDataT = new QThread;     // Create thread
    cLoadDataObj.moveToThread(cLoadDataT);  // Move controller object to thread
    cLoadDataT->start();                    // Start thread

    // Create domain classes
    unitDB unitDBObj;   // unitDB
    log logObj;         // log


    UI UIObj;

    // Set association pointers in UI object
    UIObj.setCStatus(cStatusObj);
    UIObj.setCOnOff(cOnOffObj);
    UIObj.setCAddRemove(cAddRemoveObj);
    UIObj.setCConfig(cConfigObj);
    UIObj.setCLogView(cLogViewObj);

    // Set association pointers in controller objects
    cStatusObj.setUI(UIObj);
    cOnOffObj.setUI(UIObj, unitDBObj);
    cAddRemoveObj.setUI(UIObj, unitDBObj);
    cConfigObj.setUI(UIObj);
    cLogViewObj.setUI(UIObj, logObj);


    // Show GUI
    UIObj.showFullScreen();
    return a.exec();
}
