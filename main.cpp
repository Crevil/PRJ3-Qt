#include <QApplication>
//#include "UI.h"    // UI controller

// Controllers
#include "cStatus.h"
#include "cOnOff.h"
#include "cAddRemove.h"
#include "cConfig.h"


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

    // Create UI
    UI UIObj;

    // Set association pointers in UI object
    UIObj.setCStatus(cStatusObj);
    UIObj.setCOnOff(cOnOffObj);
    UIObj.setCAddRemove(cAddRemoveObj);
    UIObj.setCConfig(cConfigObj);
    UIObj.setCLogView(cLogViewObj);

    // Set association pointers in controller objects
    cStatusObj.setUI(UIObj);
    cOnOffObj.setUI(UIObj);
    cAddRemoveObj.setUI(UIObj);
    cConfigObj.setUI(UIObj);
    cLogViewObj.setUI(UIObj);


    // Show GUI
    UIObj.showFullScreen();
    return a.exec();
}
