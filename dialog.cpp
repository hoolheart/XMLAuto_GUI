#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->scanButton,SIGNAL(clicked()),this,SLOT(selectFileName()));
    fileName = tr("");
    ui->pathEdit->setText(fileName);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::selectFileName()
{
    QFileDialog dlg;

    if(dlg.exec()==QDialog::Accepted) {
        fileName = dlg.selectedFiles().at(0);
        ui->pathEdit->setText(fileName);
    }
}
