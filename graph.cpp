#include "graph.h"


Ver::Ver(char n) {
    name = n;
}

void Ver::addNeighbor(Ver *Ver) {
    neighbors.push_back(Ver);
}


char Ver::getName() const {
    return name;
}


std::vector<Ver*> Ver::getNeighbors() const {
    return neighbors;
}


void Graph::setVer(const std::vector<char> &names, const Matrix &matrix) {
    for (auto &name : names){
        vertices.push_back(new Ver(name));
    }
    for (int i = 0; i < vertices.size(); ++i)
        for (int j = 0; j < vertices.size(); ++j)
            if (i != j && matrix.matrix_vector[i][j] != 0)
                vertices[i]->addNeighbor(vertices[j]);
}


bool Graph::empty() const {
    return vertices.empty();
}


int Graph::size() const {
    return vertices.size();
}

std::vector<Ver*> Graph::getVer() const {
    return vertices;
}
