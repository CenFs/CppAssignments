#include "grader.hh"
#include "ui_grader.h"
#include <QMessageBox>

#include <iostream>   // Just for testing purposes.  Generally you don't
using namespace std;  // need terminal input or output in a graphical program.


Grader::Grader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grader)
{
    ui->setupUi(this);

    // When the user clicks Print-button in the user interface
    // we want the print_button slot (i.e. method) to be called.
    connect(ui->print_button, SIGNAL(clicked()),
            this, SLOT(print()));
}


Grader::~Grader()
{
    delete ui;
}


void Grader::print() {
    int answer = QMessageBox::question(
                     this,
                     "Print",
                     "Are you sure you\nwant to print it?",
                     QMessageBox::Ok|QMessageBox::Cancel,
                     QMessageBox::Ok
                 );

    if ( answer == QMessageBox::Ok ) {
        // Test print just to demonstrate the ways we can access
        // the contents of QLineEdit and QSlider components (widgets).
        cout << "printing: "
             << ui->id_editor->text().toStdString() << ":"
             << ui->name_editor->text().toStdString() << ":"
             << ui->gradeslider->value()
             << endl;
    }
}
