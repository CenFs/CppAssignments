#ifndef STOPWATCH_HH
#define STOPWATCH_HH

#include <QWidget>
#include <QTimer>
#include <ctime>

using namespace std;

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QWidget
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = 0);
    ~Stopwatch();

public slots:
    void advance_time();

private:
    Ui::Stopwatch *ui;
    QTimer* timer = nullptr;
    time_t start_time = 0;
};

#endif // STOPWATCH_HH
