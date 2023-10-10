#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Interface : public QWidget
{
    Q_OBJECT

    QLabel *size_text, *input_matrix_text, *fractional_text, *output_text;
    QLineEdit *num_edit, *den_edit, *matrix_size_edit;
    QPushButton *size_btn, *save_btn, *det_btn, *transport_btn, *rang_btn, *print_btn;

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
};
#endif // INTERFACE_H