#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QTextStream>
#include "funs.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->scanButton,SIGNAL(clicked()),this,SLOT(selectFileName()));
    fileName = tr("");
    ui->pathEdit->setText(fileName);
    ui->statusLabel->setText(tr("Select descriptive xml file"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::selectFileName()
{
    QFileDialog dlg;
    DataStr dat;
    FileCode err;

    if(dlg.exec()==QDialog::Accepted) {
        fileName = dlg.selectedFiles().at(0);
        ui->pathEdit->setText(fileName);

        //read file
        ui->statusLabel->setText(tr("Reading file..."));
        if(readFile(dat,fileName,err)) {
            ui->statusLabel->setText(tr("Succeed to read file!"));
        }
        else {
            ui->statusLabel->setText(tr("Failed with error code: ")+err);
            return;
        }

        //construct files
        ui->statusLabel->setText(tr("Constructing file..."));
        if(transform(dat,fileName,err)) {
            ui->statusLabel->setText(tr("Succeed to construct files!"));
        }
        else {
            ui->statusLabel->setText(tr("Failed with error code: ")+err);
        }
    }
}
