#ifndef EDITOR_HH
#define EDITOR_HH

#include <QMainWindow>
#include <string>

using namespace std;

namespace Ui {
class Editor;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = 0);
    ~Editor();

public slots:
    void editor_quit();
    bool editor_save();
    void editor_document_change();

private:
    Ui::Editor *ui;

    bool document_has_been_modified_ = false;
    string filename_ = "";
};

#endif // EDITOR_HH
