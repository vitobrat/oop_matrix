#ifndef OOP_PARSER_H
#define OOP_PARSER_H

#include "graph.h"
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <vector>
#include <fstream>


class Parser : public QWidget {
    friend class TSample;

protected:
    Q_OBJECT
    Graph* parseFile(const std::string &path);

public:
    Parser(QWidget *parent = nullptr);
    Graph *graph;
};


#endif //OOP_PARSER_H
