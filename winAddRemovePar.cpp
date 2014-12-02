#include "winAddRemovePar.h"
#include "ui_winAddRemovePar.h"
#include "UI.h"


winAddRemovePar::winAddRemovePar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winAddRemovePar)
{
    ui->setupUi(this);
}

winAddRemovePar::~winAddRemovePar()
{
    delete ui;
}

QComboBox * winAddRemovePar::getBane()
{
    return ui->cbBane;
}

QSpinBox * winAddRemovePar::getTemp()
{
    return ui->sbTemp;
}

QSpinBox * winAddRemovePar::getHumi()
{
    return ui->sbHumi;
}


//
// Button events
//
void winAddRemovePar::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}

void winAddRemovePar::on_bSave_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCAddRemove()->add();
}
