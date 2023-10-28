#include "rational.h"
#include "common.h"

QChar Rational::SEPARATOR = separator;

Rational::Rational(const int& r)
{
    num = r;
    den = 1;
}
Rational :: Rational(const Rational& other) {
    num = other.num;
    den = other.den;
}
Rational::Rational(const int& r, const int& c)
{
    num = r;
    den = c;
}
Rational::Rational()
{

}

Rational::Rational(const QByteArray &arr) {
    int sepInd = arr.indexOf(SEPARATOR.toLatin1());
    num = arr.left(sepInd).toDouble();
    den = arr.right(arr.length() - sepInd - 1).toDouble();
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


QString& operator<<(QString& s, Rational d){
    if (d.num == 0) {
        s += "0";
        return s;
    }
    s += QString().setNum(d.num);
    s += '/';
    if (d.den == 0){
        d.den = 1;
    }
    s += QString().setNum(d.den);
    return s;

}

QByteArray &operator>>(QByteArray &arr, Rational &num) {
    int sepInd = arr.indexOf(Rational::SEPARATOR.toLatin1());
    sepInd =  arr.indexOf(Rational::SEPARATOR.toLatin1(), sepInd + 1);
    if (sepInd > 0) {
        num = Rational(arr.left(sepInd));
        arr = arr.right(arr.length() - sepInd - 1);
    }
    return arr;
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

Rational Rational :: operator=(const Rational &c){
    num = c.num;
    den = c.den;
    return *this;
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
