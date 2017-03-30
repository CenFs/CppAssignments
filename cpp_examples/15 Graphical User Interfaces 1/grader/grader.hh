#ifndef GRADER_HH
#define GRADER_HH

#include <QWidget>

namespace Ui {
class Grader;
}

class Grader : public QWidget
{
    Q_OBJECT

public:
    explicit Grader(QWidget *parent = 0);
    ~Grader();

// Slots (methods) we can send signals to (have
// the method called) when something interesting
// happens in the user interface (like a button
// gets clicked).
public slots:
    void print();

private:
    Ui::Grader *ui;
};

#endif // GRADER_HH
