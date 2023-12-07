#ifndef INTERFACE_H
#define INTERFACE_H

#include "sample.h"

#include <QWidget>
#include <QPushButton>


class Interface : public QWidget {
private:
    Q_OBJECT
    Sample *sample;

public:
    Interface(Sample*, QWidget *parent = nullptr);
    ~Interface() override;

protected:
    void paintEvent(QPaintEvent*) override;
};


#endif // INTERFACE_H
