#include "complex.h"

complex::complex(const int& r)
{
    re = r;
    im = 0;
}

complex::complex()
{

}
std :: ostream& operator << (std :: ostream& os, complex c){
    if((c.re == 0) && (c.im == 0)) os << '0';
    else{
        if (c.re != 0 ) os << c.re;
        if(c.im != 0){
            if(c.im > 0) os << "+" <<c.im<< "i";
            else os << " " <<c.im<< "i";
        }
    }
    return os;
}
std :: istream& operator >> (std :: istream& is, complex &c){
    is >> c.re >> c.im;
    return is;
}
complex complex :: operator*(complex c){
    complex result;
    result.re = re * c.re - im * c.im;
    result.im = re * c.im + im * c.re;
    return result;
}
complex complex :: operator-(complex c){
    complex result;
    result.re = re - c.re;
    result.im = im - c.im;
    return result;
}
complex complex :: operator*(int c){
    complex result;
    result.re = re * c;
    result.im = im * c;
    return result;
}
complex complex :: operator += (complex c){
    re += c.re;
    im += c.im;
    return re;
}

bool complex :: operator != (complex c){
    if ((re == c. re) && (im == c.im)) return false;
    else return true;
}
