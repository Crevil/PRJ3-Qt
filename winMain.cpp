#include "winMain.h"
#include "ui_winMain.h"
#include "UI.h"
//#include "cAddRemove.h"
//#include "cConfig.h"
#include <iostream>

winMain::winMain(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::winMain)
{
    ui_->setupUi(this);
}

winMain::~winMain()
{
    delete ui_;
}

// Slots
void winMain::on_bAddRemove_clicked()
{
    //parent_->getCAddRemove()->menuAddRemove();
}

void winMain::on_bConfig_clicked()
{
    //parent_->getCConfig()->menuConfig();
}
