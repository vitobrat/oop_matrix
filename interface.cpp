#include "interface.h"

using namespace std;

const int window_size_x = 530;
const int window_size_y = 300;
const int delta = 20;
const int button_size_x = window_size_x / 5;
const int button_size_y = window_size_y / 10;
const int text_size_x = window_size_x / 5;
const int text_size_y = window_size_y / 10;
const int edit_size_x = window_size_x / 15;
const int edit_size_y = window_size_y / 10;

Interface::Interface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Практическая работа №3");
    setFixedSize(window_size_x, window_size_y);

    size_text = new QLabel("Размерность: ", this);
    size_text->setGeometry(window_size_x*1/5, window_size_y*1/20, text_size_x, text_size_y);
    input_matrix_text = new QLabel("Элемент [0][0]:", this);
    input_matrix_text->setGeometry(window_size_x*1/5, window_size_y*4/20, text_size_x, text_size_y);
    fractional_text = new QLabel(" / ", this);
    fractional_text->setGeometry(window_size_x*2/5 + 2*delta, window_size_y*4/20, text_size_x, text_size_y);
    output_text = new QLabel("0 0 0", this);
    output_text->setGeometry(window_size_x*1/5,  window_size_y*5/20, window_size_x/5, window_size_y/5);//пока не знаю насколько большой ее нужно делать

    matrix_size_edit = new QLineEdit("3", this);
    matrix_size_edit->setGeometry(window_size_x*2/5, window_size_y*1/20, edit_size_x, edit_size_y);
    num_edit = new QLineEdit("0", this);
    num_edit->setGeometry(window_size_x*2/5, window_size_y*4/20, edit_size_x, edit_size_y);
    den_edit = new QLineEdit("1", this);
    den_edit->setGeometry(window_size_x*2/5 + 3*delta, window_size_y*4/20, edit_size_x, edit_size_y);

    size_btn = new QPushButton("Создать", this);
    size_btn->setGeometry(window_size_x - button_size_x - delta, window_size_y*1/20, button_size_x, button_size_y);
    save_btn = new QPushButton("Сохранить", this);
    save_btn->setGeometry(window_size_x - button_size_x - delta, window_size_y*4/20, button_size_x, button_size_y);
    det_btn = new QPushButton("Определитель", this);
    det_btn->setGeometry(window_size_x*0/5 + delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    transport_btn = new QPushButton("Транспонировать", this);
    transport_btn->setGeometry(window_size_x*1/5 + 2*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    rang_btn = new QPushButton("Ранг", this);
    rang_btn->setGeometry(window_size_x*2/5 + 3*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    print_btn = new QPushButton("Вывод матрицы", this);
    print_btn->setGeometry(window_size_x*3/5 + 4*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
}

Interface::~Interface()
{
    delete size_text;
    delete input_matrix_text;
    delete fractional_text;
    delete output_text;
    delete matrix_size_edit;
    delete num_edit;
    delete den_edit;
    delete size_btn;
    delete save_btn;
    delete det_btn;
    delete transport_btn;
    delete rang_btn;
    delete print_btn;
}

