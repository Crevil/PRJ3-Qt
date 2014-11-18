#include <QApplication>
//#include "UI.h"    // UI controller

// Controllers
#include "cAddRemove.h"
#include "cConfig.h"


int main(int argc, char *argv[])
{
    // Create Qt application
    QApplication a(argc, argv);

    // Create controllers
    cAddRemove cAddRemoveObj;
    cConfig cConfigObj;

    // Create UI
    UI UIObj;

    // Set association pointers in UI object
    UIObj.setCAddRemove(&cAddRemoveObj);
    UIObj.setCConfig(&cConfigObj);

    // Set association pointers in controller objects
    cAddRemoveObj.setUI(&UIObj);
    cConfigObj.setUI(&UIObj);

    // Show GUI
    UIObj.show();
    return a.exec();
}
