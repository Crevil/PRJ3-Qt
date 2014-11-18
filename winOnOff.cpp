#include "winOnOff.h"
#include "ui_winOnOff.h"
#include "UI.h"

winOnOff::winOnOff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winOnOff)
{
    ui->setupUi(this);
}

winOnOff::~winOnOff()
{
    delete ui;
}

//
// Button events
//
void winOnOff::on_bOn_clicked()
{

}

void winOnOff::on_bOff_clicked()
{

}

void winOnOff::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}
