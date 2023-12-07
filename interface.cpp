#include "interface.h"


const int size_x = 400;
const int size_y = 440;

Interface::Interface(Sample *sample, QWidget *parent) : QWidget(parent) {
    setWindowTitle("lab7");
    setFixedSize(size_x, size_y);
    this->sample = sample;
}


Interface::~Interface() {
    delete sample;
}


void Interface::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    QRect rect(0, 0, size_x, size_y - 40);
    sample->draw(&painter, rect);
    painter.end();
}


