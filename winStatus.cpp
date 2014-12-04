#include "winStatus.h"
#include "ui_winStatus.h"
#include "UI.h"

winStatus::winStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winStatus)
{
    ui->setupUi(this);
}

winStatus::~winStatus()
{
    delete ui;
}

//
// Button events
//
void winStatus::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}

//
// Getters
//
Ui::winStatus * winStatus::getUI()
{
    return ui;
}
