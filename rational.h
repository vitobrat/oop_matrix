#ifndef RATIONAL_H
#define RATIONAL_H

#include<iostream>
#include <QWidget>
#include <QString>
using namespace std;

class Rational
{
    int num, den;
    void simplifyFraction();
public:
    Rational();
    Rational(const int&);
    Rational(const Rational& other);
    Rational(const int& r, const int& c);
    Rational operator=(const Rational &);
    Rational operator * (Rational);
    Rational operator * (int);
    Rational operator - (Rational);
    Rational operator += (Rational);
    bool operator != (Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend ostream& operator<<(ostream&, Rational);
    friend QString& operator<<(QString&, Rational &);
};

#endif // RATIONAL_H
