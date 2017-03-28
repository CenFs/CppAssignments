#include "editor.hh"
#include "ui_editor.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <fstream>
#include <string>

using namespace std;


Editor::Editor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editor)
{
    ui->setupUi(this);

    connect(ui->textarea, SIGNAL(textChanged()),
            this, SLOT(editor_document_change()));
    connect(ui->quit_button, SIGNAL(clicked()),
            this, SLOT(editor_quit()));
    connect(ui->save_button, SIGNAL(clicked()),
            this, SLOT(editor_save()));
}

Editor::~Editor()
{
    delete ui;
}

int document_modified_should_we_quit_anyways() {
    QMessageBox message;

    message.setWindowTitle("Are you sure?");
    message.setStandardButtons(QMessageBox::Save
                               | QMessageBox::Discard
                               | QMessageBox::Cancel);
    message.setInformativeText("Document has been modified, what to do?");

    return message.exec();
}

void Editor::editor_quit() {
    if ( not document_has_been_modified_ ) {
        qApp->quit();
    }


    int answer = document_modified_should_we_quit_anyways();

    if ( answer == QMessageBox::Discard ) {
        qApp->quit();
    } else if ( answer == QMessageBox::Cancel ) {
        return;
    } else if ( editor_save() ) {
        qApp->quit();
    } else {
        return;
    }
}

bool Editor::editor_save() {
    if ( not document_has_been_modified_ ) {
        return true;
    }

    QString answer = QFileDialog::getSaveFileName(
                        nullptr,
                        "Input the file name",
                        QString::fromStdString(filename_),
                        ".txt-files (*.txt) | all-files (*.*)"
                     );

    string filename = answer.toStdString();

    ofstream file(filename);
    if ( not file ) {
        return false;
    }

    file << ui->textarea->toPlainText().toStdString();

    if ( not file ) {
        return false;
    }

    file.close();

    document_has_been_modified_ = false;

    return true;
}

void Editor::editor_document_change() {
    document_has_been_modified_ = true;
}
