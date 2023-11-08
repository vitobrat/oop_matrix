#include "matrix.h"
#include <iostream>
#include <vector>
#include "number.h"

using namespace std;


Matrix::Matrix(vector<vector<number>> matrix_vector) :  rows(matrix_vector[0].size()), columns(matrix_vector.size()), matrix_vector(matrix_vector) {

}

//транспонирует матрицу тем, что в объекте matrix изменяет matrix_vector
void Matrix::transpose(){
    vector<vector<number>> matrix_vector_help_me (rows, vector<number>(columns, 0));
    for(int i = 0; i < this->columns; i++){
        for (int j = 0; j < this->rows; j++){
            matrix_vector_help_me[j][i] = matrix_vector[i][j];
        }
    }
    matrix_vector = matrix_vector_help_me;
}



//дружественная функция для вывода матрицы на экран
QString& operator<< (QString& cout, Matrix& matrix){

    for (int i = 0; i < matrix.columns; ++i) {
        for (int j = 0; j < matrix.rows; ++j) {
            cout << matrix.matrix_vector[i][j];
            cout += "\t";
    }
    cout += "\n";
    }
    return cout;
}
