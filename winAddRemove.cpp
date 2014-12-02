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

QTableWidget * winAddRemove::getTable()
{
    return ui->tUnits;
}

//
// Button events
//
void winAddRemove::on_bAdd_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showAddRemovePar();
}

void winAddRemove::on_bRemove_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCAddRemove()->remove();
}

void winAddRemove::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCAddRemove()->menuAbort();
}
