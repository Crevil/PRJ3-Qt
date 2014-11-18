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

// Slots
void winMain::on_bAddRemove_clicked()
{

}

void winMain::on_bConfig_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCConfig()->menuConfig();
}
