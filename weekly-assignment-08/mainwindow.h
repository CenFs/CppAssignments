#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();

public slots:
    void clear_button_clicked();
    void calculate_miles();

private:
    Ui::Mainwindow *ui;
};

#endif // MAINWINDOW_H
