#include "parser.h"

enum Errors{
    NO_MISTAKE = 0,
    NO_SQUARE ,
    INCORRECT_VALUE,
};

Parser::Parser(QWidget *parent) : QWidget(parent) {
    std::string path = "D:\\qt\\prodjs\\oop_matrix\\graph.txt";
    graph = new Graph();
    switch (check_matrix(path)) {
    case NO_MISTAKE :
        graph = parseFile(path);
        error = NO_MISTAKE;
        break;
    case NO_SQUARE:
        qDebug () <<"NO_SQUARE";
        error = NO_SQUARE;
        break;
    case INCORRECT_VALUE:
        qDebug () << "INCORRECT_VALUE";
        error = INCORRECT_VALUE;
        break;
    default:
        break;
    }

}

int Parser::check_matrix(const std::string &path){
    std :: ifstream file(path);
    std :: vector<std :: string> adjacency_matrix;
    std :: string buff;
    std :: string no_space_first_str;
    while(std::getline(file,buff)) adjacency_matrix.push_back(buff);
    for(int i = 0; i < adjacency_matrix[0].size();i++) if(adjacency_matrix[0][i] != ' ') no_space_first_str += adjacency_matrix[0][i];

    int size_of_row = no_space_first_str.size(), size_of_column = adjacency_matrix.size() - 1;

if(size_of_row != size_of_column) return NO_SQUARE;

    for(int i = 1; i < adjacency_matrix.size();i++){
        for(int j = 0; j < adjacency_matrix[0].size();j++){
            if(adjacency_matrix[i][j] != '1' and adjacency_matrix[i][j] != '0' and adjacency_matrix[i][j] != ' ')
                return INCORRECT_VALUE;
        }
    }
    return NO_MISTAKE;
}

Graph* Parser::parseFile(const std::string &path) {
    std::ifstream file(path);
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
    return graph;
}
