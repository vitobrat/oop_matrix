#ifndef DERIVESAMPLE_H
#define DERIVESAMPLE_H

#include "sample.h"

class DeriveSample : public Sample
{
private:
    int activeIndex;

public:
    DeriveSample(Graph*);
    void draw(QPainter*, QRect&);
    void change(Graph*);
    void update(bool);
};

#endif // DERIVESAMPLE_H
