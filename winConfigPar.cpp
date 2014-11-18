#include "winConfigPar.h"
#include "ui_winConfigPar.h"
#include "UI.h"

winConfigPar::winConfigPar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winConfigPar)
{
    ui->setupUi(this);
}

winConfigPar::~winConfigPar()
{
    delete ui;
}

//
// Button events
//
void winConfigPar::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}

void winConfigPar::on_bSave_clicked()
{

}