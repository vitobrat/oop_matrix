#ifndef OOP_SAMPLE_H
#define OOP_SAMPLE_H


#include "parser.h"

#include <QPainter>
#include <map>


class Sample {
private:
    Graph *graph;

public:
    // Constructor and updater
    Sample(Graph*);
    void changeSource(Graph*);

    bool empty();
    void draw(QPainter*, QRect&);
};


#endif //OOP_SAMPLE_H
