#ifndef INTERFACE_H
#define INTERFACE_H

#include "sample.h"

#include <QWidget>
#include <QPushButton>
#include <QLabel>


class Interface : public QWidget {
private:
    Q_OBJECT
    Sample *sample;
    QLabel *error_text;

public:
    Interface(Sample*, QWidget *parent = nullptr);
    ~Interface() override;

protected:
    void paintEvent(QPaintEvent*) override;

};


#endif // INTERFACE_H
