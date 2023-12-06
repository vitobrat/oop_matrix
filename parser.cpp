#include "parser.h"


TParser::TParser(QWidget *parent) : QWidget(parent) {
    std::string path = "C:\\OOP\\matrix\\oop_matrix\\graph.txt";
    graph = new Graph();
    parseFile(path);
}

short TParser::parseFile(const std::string &path) {
    std::ifstream file(path);
    if (!file.is_open()) return -1;
    std::string line;
    std::getline(file, line);
    std::string neighbour;
    std::vector<char> neighbours;
    for (auto &c : line) {
        if (c == ' ') {
            if (!neighbour.empty()) neighbours.push_back(neighbour[0]);
            neighbour.clear();
        } else {
            neighbour += c;
            if (neighbour.length() > 1) return -2;
        }
    }
    neighbours.push_back(neighbour[0]);

    std::vector<std::vector<int>> values;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == '0' || line[i] == '1') {
                row.push_back(line[i] - '0');
            }
        }
        values.push_back(row);
    }
    Matrix matrix(values);
    graph->setVer(neighbours, matrix);
    file.close();
    return 1;
}
