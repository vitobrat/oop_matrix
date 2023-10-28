#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
#include <QString>
using namespace std;

class Rational
{
    int num, den;
    void simplifyFraction();
public:
    static QChar SEPARATOR;
    Rational();
    Rational(const int&);
    Rational(const Rational& other);
    Rational(const int& r, const int& c);
    Rational(const QByteArray&);
    Rational operator=(const Rational &);
    Rational operator * (Rational);
    Rational operator * (int);
    Rational operator - (Rational);
    Rational operator += (Rational);
    bool operator != (Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend QString& operator<<(QString&, Rational);
    friend QByteArray &operator>>(QByteArray &arr, Rational &num);
};

#endif // RATIONAL_H
