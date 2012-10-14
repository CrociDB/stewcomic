#include "stewcomic.h"
#include "ui_stewcomic.h"

stewcomic::stewcomic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stewcomic)
{
    ui->setupUi(this);
}

stewcomic::~stewcomic()
{
    delete ui;
}
