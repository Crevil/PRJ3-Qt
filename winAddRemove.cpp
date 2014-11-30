#include "winAddRemove.h"
#include "ui_winAddRemove.h"
#include "UI.h"

winAddRemove::winAddRemove(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winAddRemove)
{
    ui->setupUi(this);
}

winAddRemove::~winAddRemove()
{
    delete ui;
}

//
// Button events
//
void winAddRemove::on_bAdd_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showParam();
}

void winAddRemove::on_bRemove_clicked()
{

}

void winAddRemove::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCAddRemove()->menuAbort();
}
