#include "interface.h"


const int size_x = 500;
const int size_y = 440;

Interface::Interface(DeriveSample *sample, QWidget *parent) : QWidget(parent) {
    setWindowTitle("lab8");
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
    update_button = new QPushButton("Change file", this);
    update_button->setGeometry(300, 405, 80, 30);
    connect(update_button, &QPushButton::pressed, this, &Interface::upd);
}



Interface::~Interface() {
    delete sample;
    delete update_button;
}


void Interface::paintEvent(QPaintEvent*) {
    QPainter painter;
    painter.begin(this);
    QRect rect(0, 0, size_x, size_y - 40);
    sample->draw(&painter, rect);
    painter.end();
}

void Interface::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton)  sample->update(false);
    if (event->button() == Qt::RightButton)  sample->update(true);
    update();
}

void Interface::upd() {
    Parser parser;
    sample->changeSource(parser.graph);
    if (sample->empty()) close();
    resize(size_x, size_y);
}




