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

QListWidget * winOnOff::getList()
{
    return ui->list;
}

//
// Button events
//
void winOnOff::on_bOn_clicked()
{
    int row = ui->list->currentRow();
    QListWidgetItem * test = ui->list->item(row);

    if(!test || test->text().isEmpty())
        return;

    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCOnOff()->On();
}

void winOnOff::on_bOff_clicked()
{
    int row = ui->list->currentRow();
    QListWidgetItem * test = ui->list->item(row);

    if(!test || test->text().isEmpty())
        return;

    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCOnOff()->Off();
}

void winOnOff::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->getCOnOff()->menuAbort();
}
