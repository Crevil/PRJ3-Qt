#include "winConfig.h"
#include "ui_winConfig.h"
#include "UI.h"
#include <iostream>

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

void winConfig::on_tUnits_cellClicked (int row, int dummy)
{
    QTableWidgetItem * unitHumi = ui->tUnits->item(row, 2);

    if(!unitHumi || unitHumi->text().isEmpty())
        return;

    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showParam();
}
