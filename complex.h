#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>

class complex
{
    double re, im;
public:
    complex();
    complex(const int&);
    complex operator * (complex);
    complex operator * (int);
    complex operator - (complex);
    complex operator += (complex);
    bool operator != (complex);
    friend std :: ostream& operator<<(std ::ostream&, complex);
    friend std :: istream& operator>>(std ::istream&, complex &);
};

#endif // COMPLEX_H
