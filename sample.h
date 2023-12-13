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
    void changeSource(Graph*);

    bool empty();
    void draw(QPainter*, QRect&);
};


#endif //OOP_SAMPLE_H
