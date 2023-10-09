#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Interface : public QWidget
{
    Q_OBJECT

    QLabel *name, *fractional, *output;
    QLineEdit *num, *den;
    QPushButton *creat_btn, *det_btn, *transport_btn, *rang_btn, *print_btn;

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
};
#endif // INTERFACE_H
