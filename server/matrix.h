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
    template <class T>
    friend QString& operator<< (QString&, Matrix<T>&);
};

#endif // MATRIX_H
using namespace std;

template <class number>
Matrix<number> :: Matrix(vector<vector<number>> matrix_vector) :  rows(matrix_vector[0].size()), columns(matrix_vector.size()), matrix_vector(matrix_vector) {

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
