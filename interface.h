#ifndef INTERFACE_H
#define INTERFACE_H

#include "derivesample.h"
#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>


class Interface : public QWidget {
private:
    Q_OBJECT
    DeriveSample *sample;
    QLabel *error_text;
    QPushButton *update_button;
public:
    Interface(DeriveSample*, QWidget *parent = nullptr);
    ~Interface() override;

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
public slots:
    void upd();
};


#endif // INTERFACE_H
