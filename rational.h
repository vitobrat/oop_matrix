#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>

using namespace std;

class Rational
{
    int num, den;
    void simplifyFraction();
public:
    Rational();
    Rational(const int&);
    Rational operator * (Rational);
    Rational operator * (int);
    Rational operator - (Rational);
    Rational operator += (Rational);
    bool operator != (Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend istream& operator>>(istream&, Rational &);
};

#endif // RATIONAL_H
