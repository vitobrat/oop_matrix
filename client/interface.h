#ifndef INTERFACE_H
#define INTERFACE_H
#include <QWidget>
#include"common.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QAbstractButton>
class Interface : public QWidget
{
    Q_OBJECT

    QLabel *output_text, *fractional_text1, *fractional_text2, *fractional_text3, *fractional_text4, *fractional_text5, *fractional_text6
        , *fractional_text7, *fractional_text8, *fractional_text9;
    QLineEdit *num_edit00, *den_edit00,*num_edit01, *den_edit01,*num_edit02, *den_edit02,*num_edit10, *den_edit10,
        *num_edit11, *den_edit11,*num_edit12, *den_edit12,*num_edit20, *den_edit20,*num_edit21, *den_edit21, *num_edit22, *den_edit22;
    QPushButton *det_btn, *transport_btn, *rang_btn, *print_btn;

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
public slots:
    void answer(QString);
private slots:
    void formRequest();

signals:
    void request(QString);

};
#endif // INTERFACE_H
