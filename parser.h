#ifndef OOP_PARSER_H
#define OOP_PARSER_H

#include "graph.h"
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <vector>
#include <fstream>


class TParser : public QWidget {
    friend class TSample;

private:
    Q_OBJECT
    Graph *graph;
    short parseFile(const std::string& file);

public:
    TParser(QWidget *parent = nullptr);
};


#endif //OOP_PARSER_H
