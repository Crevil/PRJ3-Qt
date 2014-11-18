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

void winConfig::on_bAbort_clicked()
{
    UI * ui = (UI *) ((QStackedWidget *) parent())->parent();
    ui->showMain();
}
