#ifndef OOP_SAMPLE_H
#define OOP_SAMPLE_H


#include "parser.h"
#include <QPainter>
#include <map>


class Sample {
private:

public:
    Graph *graph;
    Sample(Graph*);
    virtual void changeSource(Graph*);
    virtual void draw(QPainter*, QRect&);
    bool empty();
};


#endif //OOP_SAMPLE_H
