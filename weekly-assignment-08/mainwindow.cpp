#include "mainwindow.h"
#include "ui_mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainwindow)
{
    ui->setupUi(this);

    connect(ui->myClearButton, SIGNAL(clicked(bool)), this,
            SLOT(clear_button_clicked()));
    connect(ui->mySpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(calculate_miles()));
}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::clear_button_clicked() {
    ui->mySpinBox->setValue(0);
    ui->myLcdNumber->display(0.0);
}

void Mainwindow::calculate_miles() {
    double miles = ui->mySpinBox->value() / 1.609;
    ui->myLcdNumber->display(miles);
}
