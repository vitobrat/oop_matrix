#include "application.h"
#include "number.h"
#include <iostream>
#include "matrix.h"

using namespace std;

Application::Application()
{

}

//функция, имитирующая консоль, где все команды происходят
int Application::exec(){
    int size = 3;
    Matrix *matrix = new Matrix(size, false);
    while(true){
        int user_choice = menu();//получаем выбор пользователя
        switch (user_choice) {
        //выход
        case 0:
            delete matrix;
            return 0;
        //команду, инициирующую ввод с консоли значений, задающих объект матрицы
        //(до ввода в программе должна быть задана матрица по умолчанию);
        case 1:
            cout << "Matrix size: \n";
            cin >> size;
            delete matrix;
            matrix = new Matrix(size, true);
            break;
        //команду, инициирующую расчет определителя матрицы и вывод результатов расчета;
        case 2:
            cout << "Determinant:" << matrix->get_determinant() << "\n";
            break;
        //команду, инициирующую формирования транспонированной матрицы и ее вывода в консоль;
        case 3:
            matrix->transpose(matrix);
            cout << *matrix;
            break;
        //команду, инициирующую расчет ранга матрицы и вывод результатов расчета;
        case 4:
            cout << "Rang:" << matrix->get_rang() << "\n";
            break;
        //команду, инициирующую представление в консоль текущего объекта матрицы;
        case 5:
            cout << *matrix;
            break;
        default:
            break;
        }
    }
}

//функция просто печатает в консоль, что пользователь может выбрать
//передает в exec() int user_choice(выбор пользователя)
int Application::menu(){
    int user_choice;
    cout << "1 - input matrix\n";
    cout << "2 - calculate determinant\n";
    cout << "3 - transpose\n";
    cout << "4 - rang\n";
    cout << "5 - print matrix\n";
    cout << "0 - exit\n";
    cin >> user_choice;
    return user_choice;
}
