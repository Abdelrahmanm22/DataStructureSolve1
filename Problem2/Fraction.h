//
// Created by future on 4/27/2022.
//

#ifndef PROBLEM2_FRACTION_H
#define PROBLEM2_FRACTION_H


#include <iostream>
using namespace std;
class Fraction
{
    int nom, denom;
public:
    Fraction();
    Fraction(int n,int d);
    int getNomenator();
    int getDenomenator();

    ///this Function Return greatest common divisor
    int DivBy();
    //function for reducing fractions.
    Fraction reduce(int x,int y);


    /// This class defines adding, subtracting, multiplying, dividing and comparing-------------------
    Fraction operator + (const Fraction right);
    Fraction operator - (const Fraction right);
    Fraction operator * (const Fraction right);
    Fraction operator / (const Fraction right);
    bool operator == (const Fraction right);
    bool operator > (const Fraction right);
    bool operator < (const Fraction right);
    bool operator != (const Fraction right);
    /// This class defines adding, subtracting, multiplying, dividing and comparing-------------------



    ///overload I/O operators to be able to input and output fractions naturally-------------------
    friend ostream& operator << (ostream& out,Fraction frac);
    friend istream& operator >> (istream& in,Fraction &frac);
    ///overload I/O operators to be able to input and output fractions naturally-------------------
};

#endif //PROBLEM2_FRACTION_H
