//
// Created by future on 4/27/2022.
//

#include "Fraction.h"
#include<iostream>
using namespace std;
Fraction::Fraction()
{
    nom=0;
    denom=0;
}
Fraction::Fraction(int n,int d)
{
    nom=n;
    denom=d;
}

int Fraction::getNomenator()
{
    return nom;
}
int Fraction::getDenomenator()
{
    return denom;
}

///this Function Return greatest common divisor
int Fraction::DivBy()
{

    int x=nom,y=denom;
    while(x != y){
        if(x > y){
            x-=y;
        }
        else{
            y-=x;
        }

    }
    return x;
}
Fraction Fraction::reduce(int x,int y)
{
    nom=x;
    denom=y;
    int d =DivBy();
    nom/=d;
    denom/=d;

    return Fraction(nom,denom);
}
Fraction Fraction::operator + (const Fraction right)
{
    Fraction res;
    res.nom = (nom*right.denom)+(right.nom*denom);
    res.denom = denom*right.denom;
    reduce(res.nom,res.denom);

    return reduce(res.nom,res.denom);
}

Fraction Fraction::operator - (const Fraction right)
{
    Fraction res;
    res.nom = (nom*right.denom)-(right.nom*denom);
    res.denom = denom*right.denom;
    //reduce(res.nom,res.denom);
    //cout<<res.nom<<endl;

    return reduce(res.nom,res.denom);
}
Fraction Fraction::operator * (const Fraction right)
{
    Fraction res;
    res.nom = nom*right.nom;
    res.denom = denom * right.denom;

    return reduce(res.nom,res.denom);
}
Fraction Fraction::operator / (const Fraction right)
{
    Fraction res;
    res.nom = nom*right.denom;
    res.denom = denom * right.nom;

    return reduce(res.nom,res.denom);
}
bool Fraction::operator == (const Fraction right)
{
    if (nom == right.nom && denom==right.denom)
        return true;

    return false;
}
bool Fraction::operator != (const Fraction right)
{
    if (nom != right.nom && denom!=right.denom)
        return true;

    return false;
}
bool Fraction::operator > (const Fraction right)
{
    Fraction res;
    res.nom = (nom*right.denom)-(right.nom*denom);
    if (res.nom > 0)
        return true;

    return false;
}
bool Fraction::operator < (const Fraction right)
{
    Fraction res;
    res.nom = (nom*right.denom)-(right.nom*denom);
    if (res.nom < 0)
        return true;

    return false;
}
ostream& operator<<(ostream& out,Fraction frac)
{
    out<<frac.nom<<"/"<<frac.denom;
}
istream& operator>>(istream& in,Fraction &frac)
{
    char c;

    in>>frac.nom;cin>>c;in>>frac.denom;
}
/*Fraction::~Fraction()
{
    //dtor
}*/

