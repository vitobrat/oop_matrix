#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include "number.h"


using namespace std;

class Matrix
{
    int size = 3;
    vector<vector<number>> matrix_vector ;
public:
    Matrix(int size);
    Matrix(int size, int value);
    number find_determinant();
    int find_rang();
    void transpose(Matrix *matrix);
    void fill_matrix(vector<vector<number>> &matrix_vector);
    friend ostream& operator<< (ostream&, Matrix&);
};

#endif // MATRIX_H
