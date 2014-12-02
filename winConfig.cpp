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

void winConfig::on_tUnits_cellPressed (int row, int column)
{
    row_ = row;
    column_ = column;
    QTableWidgetItem * unitHumi = ui->tUnits->itemAt(row, 2);
    QString tester = unitHumi->text();
    int test = tester.toInt();
    if(test < 0 | test > 100)
        return;

    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showParam();

}
