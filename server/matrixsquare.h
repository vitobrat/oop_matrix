#ifndef MATRIXSQUARE_H
#define MATRIXSQUARE_H
#include "matrix.h"

template <class number>
class MatrixSquare : public Matrix<number>
{
    int size;
public:
    MatrixSquare(vector<vector<number>> matrix_vector);
};

template <class number>
MatrixSquare<number> :: MatrixSquare(vector<vector<number>> matrix_vector) : Matrix<number>(matrix_vector){
    size = this->rows;
}


#endif // MATRIXSQUARE_H
