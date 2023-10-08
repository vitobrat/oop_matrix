#include "rational.h"

Rational::Rational(const int& r)
{
    num = r;
    den = 1;
}

Rational::Rational()
{

}

// Функция для нахождения НОД двух чисел
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функция для сокращения дроби
void Rational::simplifyFraction() {
    int common_divisor = gcd(num, den);
    num /= common_divisor;
    den /= common_divisor;
    if (den < 0){
        num *= -1;
        den *= -1;
    }
}

std :: ostream& operator << (std :: ostream& os, Rational rational){
    if (rational.num == 0) os << '0';
    else{
        rational.simplifyFraction();
        os << rational.num << " / " << rational.den;
    }
    return os;
}

std :: istream& operator >> (std :: istream& is, Rational &rational){
    is >> rational.num >> rational.den;
    if (rational.den == 0) rational.den = 1;
    return is;
}

Rational Rational :: operator*(Rational rational){
    Rational result;
    result.num = num * rational.num;
    result.den = den * rational.den;
    return result;
}

Rational Rational :: operator-(Rational rational){
    Rational result;
    result.num = rational.den * num - rational.num * den;
    result.den= den * rational.den;
    return result;
}

Rational Rational :: operator*(int c){
    Rational result;
    result.num = num * c;
    result.den= den;
    return result;
}

Rational Rational :: operator += (Rational rational){
    num = rational.den * num + rational.num * den;
    den= den * rational.den;
    return num;
}

bool Rational :: operator != (Rational rational){
    simplifyFraction();
    rational.simplifyFraction();
    if ((num == rational.num) && (den == rational.den)) return false;
    else return true;
}
