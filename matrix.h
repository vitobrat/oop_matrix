#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include <QString>



using namespace std;
class Matrix
{
private:
    int rows;
    int columns;
public:
    vector<vector<int>> matrix_vector ;
    Matrix(vector<vector<int>> matrix_vector) :  rows(matrix_vector[0].size()), columns(matrix_vector.size()), matrix_vector(matrix_vector){}
};

#endif // MATRIX_H
