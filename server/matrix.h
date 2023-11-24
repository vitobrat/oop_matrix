#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <vector>
#include <QString>



using namespace std;
template <class number>
class Matrix
{
protected:
    int rows;
    int columns;
    vector<vector<number>> matrix_vector ;
public:
    Matrix(vector<vector<number>> matrix_vector);
    void transpose();
    void fill_matrix(vector<vector<number>> &matrix_vector);
    number find_determinant();
    int find_rang();
    template <class T>
    friend QString& operator<< (QString&, Matrix<T>&);
};

#endif // MATRIX_H
using namespace std;

template <class number>
Matrix<number> :: Matrix(vector<vector<number>> matrix_vector) :  rows(matrix_vector[0].size()), columns(matrix_vector.size()), matrix_vector(matrix_vector) {

}

template <class number>
number Matrix<number>::find_determinant(){
    if(rows == 1){
        return this->matrix_vector[0][0];
    }
    if (rows == 2) {
        return this->matrix_vector[0][0] * this->matrix_vector[1][1] - this->matrix_vector[0][1] * this->matrix_vector[1][0];
    }
    number det = 0.0;
    for (int col = 0; col < rows; col++) {
        vector<vector<number>> minor_vector(rows - 1, vector<number>(rows - 1, 0));
        for (int i = 1; i < rows; i++) {
            int minorCol = 0;
            for (int j = 0; j < rows; j++) {
                if (j != col) {
                    minor_vector[i - 1][minorCol++] = this->matrix_vector[i][j];
                }
            }
        }
        Matrix minor(minor_vector);
        det += this->matrix_vector[0][col] * (col % 2 == 0 ? 1 : -1)  * minor.find_determinant();
    }
    return det;
}

template <class number>
int Matrix<number>::find_rang(){
    if(find_determinant() != 0) return rows;
    for(int count = 1; count < rows; count++){
        for(int i = 0; i <= count; i++){
            for(int j = 0; j <= count; j++){
                vector<vector<number>> minor_vector(rows - count, vector<number>(rows - count, 0));
                for(int x = i, x1 = 0; x1 < rows - count; x++, x1++){
                    for(int y = j, y1 = 0; y1 < rows - count; y++, y1++){
                        minor_vector[x1][y1] = this->matrix_vector[x][y];
                    }
                }
                Matrix minor(minor_vector);
                if(minor.find_determinant() != 0) return rows - count;
            }

        }
    }
    return 1;
}

//транспонирует матрицу тем, что в объекте matrix изменяет matrix_vector
template <class number>
void Matrix<number> ::transpose(){
    vector<vector<number>> matrix_vector_help_me (rows, vector<number>(columns, 0));
    for(int i = 0; i < this->columns; i++){
        for (int j = 0; j < this->rows; j++){
            matrix_vector_help_me[j][i] = matrix_vector[i][j];
        }
    }
    matrix_vector = matrix_vector_help_me;
}

//дружественная функция для вывода матрицы на экран
template <class number>
QString& operator<< (QString& cout, Matrix<number>& matrix){

    for (int i = 0; i < matrix.columns; ++i) {
        for (int j = 0; j < matrix.rows; ++j) {
            cout << matrix.matrix_vector[i][j];
            cout += "\t";
        }
        cout += "\n";
    }
    return cout;
}
