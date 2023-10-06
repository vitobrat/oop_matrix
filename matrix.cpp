#include "matrix.h"
#include <iostream>
#include <vector>
#include "number.h"

using namespace std;

//конструктор класса Matix по умолчанию заполняется матрицей 3*3, состоящей из value.
Matrix::Matrix(int size, int value) :  size(size), matrix_vector(size, vector<number>(size, value)) {
}

Matrix::Matrix(int size) :  size(size), matrix_vector(size, vector<number>(size, 0)) {
    fill_matrix(matrix_vector);
}

//пользователь заполняет матрицу. вызывается в конструкторе при создании объекта
void Matrix::fill_matrix(vector<vector<number>> &matrix_vector){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
                    cin >> matrix_vector[i][j];
        }
    }
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
void Matrix::transpose(Matrix *matrix){
    for(int i = 0; i < matrix->size; i++){
        for (int j = i + 1; j < matrix->size; j++){
                    swap(matrix->matrix_vector[i][j], matrix->matrix_vector[j][i]);
        }
    }
}



//дружественная функция для вывода матрицы на экран
ostream& operator<< (ostream& cout, Matrix& matrix){
    cout << "Matrix " << matrix.size << "x" << matrix.size << ":" << std::endl;
    for (int i = 0; i < matrix.size; ++i) {
        for (int j = 0; j < matrix.size; ++j) {
            cout << matrix.matrix_vector[i][j] << "\t";
    }
    cout << endl;
    }
    return cout;
}
