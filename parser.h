#ifndef OOP_PARSER_H
#define OOP_PARSER_H

#include "graph.h"
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>

class Parser : public QWidget {
    friend class TSample;

protected:
    Q_OBJECT
    Graph* parseFile(const std::string &path);
    std::string getPath();
public:
    Parser(QWidget *parent = nullptr);
    int check_matrix(const std::string &path);
    Graph *graph;
};


#endif //OOP_PARSER_H
