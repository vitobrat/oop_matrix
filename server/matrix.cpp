#include "matrix.h"
#include <iostream>
#include <vector>
#include "number.h"

using namespace std;

//конструктор класса Matix по умолчанию заполняется матрицей 3*3, состоящей из value.
Matrix::Matrix(int size, int value) :  size(size), matrix_vector(size, vector<number>(size, value)) {
}

Matrix::Matrix(vector<vector<number>> matrix_vector) :  size(matrix_vector[0].size()), matrix_vector(matrix_vector) {

}


number Matrix::find_determinant(){
    if(size == 1){
        return matrix_vector[0][0];
    }
    if (size == 2) {
        return matrix_vector[0][0] * matrix_vector[1][1] - matrix_vector[0][1] * matrix_vector[1][0];
    }
    number det = 0.0;
    for (int col = 0; col < size; col++) {
        Matrix minor(size - 1, 0);
        for (int i = 1; i < size; i++) {
            int minorCol = 0;
            for (int j = 0; j < size; j++) {
                if (j != col) {
                    minor.matrix_vector[i - 1][minorCol++] = matrix_vector[i][j];
                }
            }
        }
        det += matrix_vector[0][col] * (col % 2 == 0 ? 1 : -1)  * minor.find_determinant();
    }
    return det;
}


int Matrix::find_rang(){
    if(find_determinant() != 0) return size;
    for(int count = 1; count < size; count++){
        for(int i = 0; i <= count; i++){
            for(int j = 0; j <= count; j++){
                Matrix minor(size - count, 0);
                for(int x = i, x1 = 0; x1 < size - count; x++, x1++){
                    for(int y = j, y1 = 0; y1 < size - count; y++, y1++){
                        minor.matrix_vector[x1][y1] = matrix_vector[x][y];
                    }
                }
                if(minor.find_determinant() != 0) return size - count;
            }

        }
    }
    return 0;
}


//транспонирует матрицу тем, что в объекте matrix изменяет matrix_vector. вывод на экран осуществляется в Application.exec()
void Matrix::transpose(){
    for(int i = 0; i < this->size; i++){
        for (int j = i + 1; j < this->size; j++){
            swap(this->matrix_vector[i][j], this->matrix_vector[j][i]);
        }
    }
}



//дружественная функция для вывода матрицы на экран
QString& operator<< (QString& cout, Matrix& matrix){

    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            cout << matrix.matrix_vector[i][j];
            cout += "\t";
    }
    cout += "\n";
    }
    return cout;
}
