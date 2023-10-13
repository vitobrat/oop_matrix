#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include <QString>
#include "number.h"


using namespace std;

class Matrix
{
    int size = 3;
    vector<vector<number>> matrix_vector ;
public:
    Matrix(vector<vector<number>> matrix_vector);
    Matrix(int size, int value);
    number find_determinant();
    int find_rang();
    void transpose();
    void fill_matrix(vector<vector<number>> &matrix_vector);
    friend QString& operator<< (QString&, Matrix&);
};

#endif // MATRIX_H
