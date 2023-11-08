#ifndef MATRIXSQUARE_H
#define MATRIXSQUARE_H
#include "matrix.h"

class MatrixSquare : public Matrix
{
    int size;
public:
    MatrixSquare(vector<vector<number>> matrix_vector);
    number find_determinant();
    int find_rang();
};

#endif // MATRIXSQUARE_H
