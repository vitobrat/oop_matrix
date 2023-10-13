#include "interface.h"
#include "number.h"
using namespace std;

const int window_size_x = 600;
const int window_size_y = 400;
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


    num_edit00 = new QLineEdit("0", this);
    num_edit00->setGeometry(window_size_x*1/5, window_size_y*1/20, edit_size_x, edit_size_y);
    fractional_text1 = new QLabel(" / ", this);
    fractional_text1->setGeometry(window_size_x*1/5 + 2*delta, window_size_y*1/20, text_size_x, text_size_y);
    den_edit00 = new QLineEdit("1", this);
    den_edit00->setGeometry(window_size_x*1/5 + 3*delta, window_size_y*1/20, edit_size_x, edit_size_y);

    num_edit01 = new QLineEdit("0", this);
    num_edit01->setGeometry(window_size_x*2/5, window_size_y*1/20, edit_size_x, edit_size_y);
    fractional_text2 = new QLabel(" / ", this);
    fractional_text2->setGeometry(window_size_x*2/5 + 2*delta, window_size_y*1/20, text_size_x, text_size_y);
    den_edit01 = new QLineEdit("1", this);
    den_edit01->setGeometry(window_size_x*2/5 + 3*delta, window_size_y*1/20, edit_size_x, edit_size_y);

    num_edit02 = new QLineEdit("0", this);
    num_edit02->setGeometry(window_size_x*3/5, window_size_y*1/20, edit_size_x, edit_size_y);
    fractional_text3 = new QLabel(" / ", this);
    fractional_text3->setGeometry(window_size_x*3/5 + 2*delta, window_size_y*1/20, text_size_x, text_size_y);
    den_edit02 = new QLineEdit("1", this);
    den_edit02->setGeometry(window_size_x*3/5 + 3*delta, window_size_y*1/20, edit_size_x, edit_size_y);

    num_edit10 = new QLineEdit("0", this);
    num_edit10->setGeometry(window_size_x*1/5, window_size_y*4/20, edit_size_x, edit_size_y);
    fractional_text4 = new QLabel(" / ", this);
    fractional_text4->setGeometry(window_size_x*1/5 + 2*delta, window_size_y*4/20, text_size_x, text_size_y);
    den_edit10 = new QLineEdit("1", this);
    den_edit10->setGeometry(window_size_x*1/5 + 3*delta, window_size_y*4/20, edit_size_x, edit_size_y);

    num_edit11 = new QLineEdit("0", this);
    num_edit11->setGeometry(window_size_x*2/5, window_size_y*4/20, edit_size_x, edit_size_y);
    fractional_text5 = new QLabel(" / ", this);
    fractional_text5->setGeometry(window_size_x*2/5 + 2*delta, window_size_y*4/20, text_size_x, text_size_y);
    den_edit11 = new QLineEdit("1", this);
    den_edit11->setGeometry(window_size_x*2/5 + 3*delta, window_size_y*4/20, edit_size_x, edit_size_y);

    num_edit12 = new QLineEdit("0", this);
    num_edit12->setGeometry(window_size_x*3/5, window_size_y*4/20, edit_size_x, edit_size_y);
    fractional_text6 = new QLabel(" / ", this);
    fractional_text6->setGeometry(window_size_x*3/5 + 2*delta, window_size_y*4/20, text_size_x, text_size_y);
    den_edit12 = new QLineEdit("1", this);
    den_edit12->setGeometry(window_size_x*3/5 + 3*delta, window_size_y*4/20, edit_size_x, edit_size_y);

    num_edit20 = new QLineEdit("0", this);
    num_edit20->setGeometry(window_size_x*1/5, window_size_y*7/20, edit_size_x, edit_size_y);
    fractional_text7 = new QLabel(" / ", this);
    fractional_text7->setGeometry(window_size_x*1/5 + 2*delta, window_size_y*7/20, text_size_x, text_size_y);
    den_edit20 = new QLineEdit("1", this);
    den_edit20->setGeometry(window_size_x*1/5 + 3*delta, window_size_y*7/20, edit_size_x, edit_size_y);

    num_edit21 = new QLineEdit("0", this);
    num_edit21->setGeometry(window_size_x*2/5, window_size_y*7/20, edit_size_x, edit_size_y);
    fractional_text8 = new QLabel(" / ", this);
    fractional_text8->setGeometry(window_size_x*2/5 + 2*delta, window_size_y*7/20, text_size_x, text_size_y);
    den_edit21 = new QLineEdit("1", this);
    den_edit21->setGeometry(window_size_x*2/5 + 3*delta, window_size_y*7/20, edit_size_x, edit_size_y);

    num_edit22 = new QLineEdit("0", this);
    num_edit22->setGeometry(window_size_x*3/5, window_size_y*7/20, edit_size_x, edit_size_y);
    fractional_text9 = new QLabel(" / ", this);
    fractional_text9->setGeometry(window_size_x*3/5 + 2*delta, window_size_y*7/20, text_size_x, text_size_y);
    den_edit22 = new QLineEdit("1", this);
    den_edit22->setGeometry(window_size_x*3/5 + 3*delta, window_size_y*7/20, edit_size_x, edit_size_y);

    det_btn = new QPushButton("Определитель", this);
    det_btn->setGeometry(window_size_x*0/5 + delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    transport_btn = new QPushButton("Транспонировать", this);
    transport_btn->setGeometry(window_size_x*1/5 + 2*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    rang_btn = new QPushButton("Ранг", this);
    rang_btn->setGeometry(window_size_x*2/5 + 3*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);
    print_btn = new QPushButton("Вывод матрицы", this);
    print_btn->setGeometry(window_size_x*3/5 + 4*delta, window_size_y - 1.5*button_size_y, button_size_x, button_size_y);

    output_text = new QLabel("", this);
    output_text->setGeometry(window_size_x*1/5, window_size_y*10/20, window_size_x/4, window_size_y/4);

    connect(det_btn,SIGNAL(pressed()), this, SLOT(value_det()));
    connect(transport_btn,SIGNAL(pressed()), this, SLOT(print_trans()));
    connect(rang_btn,SIGNAL(pressed()), this, SLOT(value_rang()));
    connect(print_btn,SIGNAL(pressed()), this, SLOT(print()));

}

Interface::~Interface()
{
    delete num_edit00;
    delete den_edit00;
    delete num_edit01;
    delete den_edit01;
    delete num_edit02;
    delete den_edit02;
    delete num_edit10;
    delete den_edit10;
    delete num_edit11;
    delete den_edit11;
    delete num_edit12;
    delete den_edit12;
    delete num_edit20;
    delete den_edit20;
    delete num_edit21;
    delete den_edit21;
    delete num_edit22;
    delete den_edit22;
    delete fractional_text1;
    delete fractional_text2;
    delete fractional_text3;
    delete fractional_text4;
    delete fractional_text5;
    delete fractional_text6;
    delete fractional_text7;
    delete fractional_text8;
    delete fractional_text9;
    delete det_btn;
    delete transport_btn;
    delete rang_btn;
    delete print_btn;
}
Matrix Interface :: create_matix(){
    vector<vector<number>> vec(3, std::vector<number>(3, 0));
    number num1 (num_edit00->text().toDouble(), den_edit00->text().toDouble());
    vec[0][0] = num1;
    number num2 (num_edit01->text().toDouble(), den_edit01->text().toDouble());
    vec[0][1] = num2;
    number num3 (num_edit02->text().toDouble(), den_edit02->text().toDouble());
    vec[0][2] = num3;
    number num4 (num_edit10->text().toDouble(), den_edit10->text().toDouble());
    vec[1][0] = num4;
    number num5 (num_edit11->text().toDouble(), den_edit11->text().toDouble());
    vec[1][1] = num5;
    number num6 (num_edit12->text().toDouble(), den_edit12->text().toDouble());
    vec[1][2] = num6;
    number num7 (num_edit20->text().toDouble(), den_edit20->text().toDouble());
    vec[2][0] = num7;
    number num8 (num_edit21->text().toDouble(), den_edit21->text().toDouble());
    vec[2][1] = num8;
    number num9 (num_edit22->text().toDouble(), den_edit22->text().toDouble());
    vec[2][2] = num9;
    Matrix new_mat(vec);
    return new_mat;
}

void Interface:: value_det(){
    Matrix matrix = create_matix();
    QString output("");
    number result = matrix.find_determinant();
    output << result;
    output_text->setText(output);
}

void Interface:: value_rang(){
    Matrix matrix = create_matix();
    QString output("");
    output += to_string(matrix.find_rang());
    output_text->setText(output);
}

void Interface:: print_trans(){
    Matrix matrix = create_matix();
    matrix.transpose();
    QString output("");
    output << matrix;
    output_text->setText(output);
}

void Interface:: print(){
    Matrix matrix = create_matix();
    QString output("");
    output << matrix;
    output_text->setText(output);
}
