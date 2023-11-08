#include "matrixsquare.h"

MatrixSquare :: MatrixSquare(vector<vector<number>> matrix_vector) : Matrix(matrix_vector){
    size = rows;
}

number MatrixSquare::find_determinant(){
    if(size == 1){
        return this->matrix_vector[0][0];
    }
    if (size == 2) {
        return this->matrix_vector[0][0] * this->matrix_vector[1][1] - this->matrix_vector[0][1] * this->matrix_vector[1][0];
    }
    number det = 0.0;
    for (int col = 0; col < size; col++) {
        vector<vector<number>> minor_vector(size - 1, vector<number>(size - 1, 0));
        for (int i = 1; i < size; i++) {
            int minorCol = 0;
            for (int j = 0; j < size; j++) {
                if (j != col) {
                    minor_vector[i - 1][minorCol++] = this->matrix_vector[i][j];
                }
            }
        }
        MatrixSquare minor(minor_vector);
        det += this->matrix_vector[0][col] * (col % 2 == 0 ? 1 : -1)  * minor.find_determinant();
    }
    return det;
}


int MatrixSquare::find_rang(){
    if(find_determinant() != 0) return size;
    for(int count = 1; count < size; count++){
        for(int i = 0; i <= count; i++){
            for(int j = 0; j <= count; j++){
                vector<vector<number>> minor_vector(3, vector<number>(3, 0));
                for(int x = i, x1 = 0; x1 < size - count; x++, x1++){
                    for(int y = j, y1 = 0; y1 < size - count; y++, y1++){
                        minor_vector[x1][y1] = this->matrix_vector[x][y];
                    }
                }
                MatrixSquare minor(minor_vector);
                if(minor.find_determinant() != 0) return size - count;
            }

        }
    }
    return 0;
}
