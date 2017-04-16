#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionFemale->setIconVisibleInMenu(true);
    ui->actionMale->setIconVisibleInMenu(false);

    connect(ui->actionReset, SIGNAL(triggered()), this,
            SLOT(reset()));
    connect(ui->actionQuit, SIGNAL(triggered()), this,
            SLOT(close()));
    connect(ui->actionFemale, SIGNAL(triggered()), this,
            SLOT(female_clicked()));
    connect(ui->actionMale, SIGNAL(triggered()), this,
            SLOT(male_clicked()));

    connect(ui->spinBox_Height, SIGNAL(valueChanged(int)), this,
            SLOT(calculate_BMI()));
    connect(ui->spinBox_Weight, SIGNAL(valueChanged(int)), this,
            SLOT(calculate_BMI()));
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::reset() {
    ui->spinBox_Height->setValue(0);
    ui->spinBox_Weight->setValue(0);
    ui->label2_BMI->setText("-");
    ui->label2_Interpretation->setText("-");
    ui->label2_Gender->setText("Female");

    ui->actionFemale->setIconVisibleInMenu(true);
    ui->actionMale->setIconVisibleInMenu(false);
}

void MainWindow::female_clicked() {
    ui->label2_Gender->setText("Female");
    ui->actionFemale->setIconVisibleInMenu(true);
    ui->actionMale->setIconVisibleInMenu(false);
    if (ui->label2_BMI->text() != "-") {
        calculate_BMI();
    }
}

void MainWindow::male_clicked() {
    ui->label2_Gender->setText("Male");
    ui->actionFemale->setIconVisibleInMenu(false);
    ui->actionMale->setIconVisibleInMenu(true);
    if (ui->label2_BMI->text() != "-") {
        calculate_BMI();
    }
}

void MainWindow::calculate_BMI() {
    double height = ui->spinBox_Height->value();
    int weight = ui->spinBox_Weight->value();
    double bmi = 0.0;
    if (height != 0) {
        bmi = weight / (height * height / 10000);
    }
    // double bmi = ui->spinBox_Weight->value() / (ui->spinBox_Height->value() * ui->spinBox_Height->value() / 10000);
    ui->label2_BMI->setText(QString::number(bmi));
    // QApplication::processEvents();
    // ui->label2_BMI->repaint();

    if (ui->label2_Gender->text() == "Male") {
        QString tmp;
        if (bmi <= 20.7) {
            tmp = "underweight";
        } else if (bmi <= 26.4) {
            tmp = "normal";
        } else if (bmi <= 27.8) {
            tmp = "slight overweight";
        } else if (bmi <= 31.1) {
            tmp = "overweight";
        } else {
            tmp = "much overweight";
        }
        ui->label2_Interpretation->setText(tmp);
    } else {
        QString tmp;
        if (bmi <= 19.1) {
            tmp = "underweight";
        } else if (bmi <= 25.8) {
            tmp = "normal";
        } else if (bmi <= 27.3) {
            tmp = "slight overweight";
        } else if (bmi <= 32.2) {
            tmp = "overweight";
        } else {
            tmp = "much overweight";
        }
        ui->label2_Interpretation->setText(tmp);
    }
}
