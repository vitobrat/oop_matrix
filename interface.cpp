#include "interface.h"


const int size_x = 500;
const int size_y = 440;

Interface::Interface(Sample *sample, QWidget *parent) : QWidget(parent) {
    setWindowTitle("lab7");
    setFixedSize(size_x, size_y);
    this->sample = sample;
    error_text = new QLabel("", this);
    error_text->setGeometry(20, 405, 460, 30);
    switch(sample->graph->error){
    case 0:
        error_text->setText("Файл корректен");
        break;
    case 1:
        error_text->setText("Файл составлен неправильно(матрица смежности составлена неправильно)");
        break;
    case 2:
        error_text->setText("Файл составлен неправильно(недопустимые значения в файле)");
        break;

    }
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




