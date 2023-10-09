#include "interface.h"

const int button_size_x = 40;
const int button_size_y = 110;
const int delta = 10;

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Практическая работа №3");
    setFixedSize(500, 450);

    name = new QLabel("Matrix: ", this);
    name->setGeometry(50, 20, 50, 20);
    fractional = new QLabel(" / ", this);
    fractional->setGeometry(140, 20, 10, 20);
    fractional = new QLabel(" / ", this);
    fractional->setGeometry(140, 50, 10, 20);

    num = new QLineEdit("0", this);
    num->setGeometry(100, 20, 40, 25);
    den = new QLineEdit("1", this);
    den->setGeometry(150, 20, 40, 25);

    det_btn = new QPushButton("Определитель", this);
    det_btn->setGeometry(delta, 380, button_size_y, button_size_x);
    transport_btn = new QPushButton("Транспонировать", this);
    transport_btn->setGeometry(2*delta + button_size_y, 380, button_size_y, button_size_x);
    rang_btn = new QPushButton("Ранг", this);
    rang_btn->setGeometry(3*delta + 2*button_size_y, 380, button_size_y, button_size_x);
    print_btn = new QPushButton("Вывод матрицы", this);
    print_btn->setGeometry(4*delta + 3*button_size_y, 380, button_size_y, button_size_x);
}

Interface::~Interface()
{
    delete name;
    delete fractional;
    delete num;
    delete den;
    delete det_btn;
    delete transport_btn;
    delete rang_btn;
    delete print_btn;
}

