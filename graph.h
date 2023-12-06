#ifndef ADS_GRAPH_H
#define ADS_GRAPH_H


#include <vector>
#include <matrix.h>

class Ver {
public:
    Ver(char c);
    void addNeighbor(Ver* n);
    char getName() const;
    std::vector<Ver*> getNeighbors() const;

private:
    char name;
    std::vector<Ver*> neighbors;
    friend class Graph;
};


class Graph {
private:
    std::vector<Ver*> vertices;
public:
    Graph() = default;
    void setVer(const std::vector<char> &names, const Matrix &matrix);
    int size() const;
    bool empty() const;
    std::vector<Ver*> getVer() const;
};


#endif //ADS_GRAPH_H
