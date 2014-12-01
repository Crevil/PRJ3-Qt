#include "winConfig.h"
#include "ui_winConfig.h"
#include "UI.h"

winConfig::winConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winConfig)
{
    ui->setupUi(this);
}

winConfig::~winConfig()
{
    delete ui;
}

QTableWidget * winConfig::getTable()
{
    return ui->tUnits;
}
//
// Button events
//
void winConfig::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}
