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
    number find_determinant();
    int find_rang();
    number determinant = 0;
    int rang = size;
public:
    Matrix(int size, bool flag);
    void transpose(Matrix *matrix);
    number get_determinant();
    int get_rang();
    void fill_matrix(vector<vector<number>> &matrix_vector);
    friend ostream& operator<< (ostream&, Matrix&);
};

#endif // MATRIX_H
