#include "winMain.h"
#include "ui_winMain.h"
#include "UI.h"

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

//
// Button events
//
void winMain::on_bStatus_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCStatus()->menuStatus();
}

void winMain::on_bOnOff_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCOnOff()->menuOnOff();
}

void winMain::on_bLog_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCLogView()->menuLog();
}

void winMain::on_bAddRemove_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCAddRemove()->menuAddRemove();
}

void winMain::on_bConfig_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCConfig()->menuConfig();
}
