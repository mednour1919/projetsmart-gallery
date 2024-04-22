#include "ard.h"
#include "ui_ard.h"

ard::ard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ard)
{
    ui->setupUi(this);
}

ard::~ard()
{
    delete ui;
}
