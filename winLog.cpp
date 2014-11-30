#include "winLog.h"
#include "ui_winLog.h"
#include "UI.h"

winLog::winLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winLog)
{
    ui->setupUi(this);
}

winLog::~winLog()
{
    delete ui;
}

QTableWidget * winLog::getTable()
{
    return ui->tAll;
}

void winLog::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}
