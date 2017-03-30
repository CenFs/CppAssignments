#include "stopwatch.hh"
#include "ui_stopwatch.h"
#include <QTimer>
#include <ctime>

using namespace std;

Stopwatch::Stopwatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stopwatch)
{
    ui->setupUi(this);

    start_time = time(nullptr);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),
            this, SLOT(advance_time()));

    timer->start(1000);
}

Stopwatch::~Stopwatch()
{
    delete ui;
}

void Stopwatch::advance_time() {
    time_t now = time(nullptr);
    int passed = now - start_time;

    ui->timelabel->setNum(passed);
}
