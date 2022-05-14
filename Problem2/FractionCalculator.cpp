//
// Created by future on 4/27/2022.
//

#include<iostream>
using namespace std;
#include "Fraction.h"
#include "FractionCalculator.h"


/*FractionCalculator::FractionCalculator()
{
    //ctor
}

FractionCalculator::~FractionCalculator()
{
    //dtor
}*/
void FractionCalculator::calc()
{
    cout<<"Hello User! \n";
    cout<<"Welcome to Fraction Calculator..\n\n";
    Fraction num1,num2,num3;
    int i;
    while(true)
    {

        cout<<"1--Adding\n";
        cout<<"2--Subtract\n";
        cout<<"3--multiplication\n";
        cout<<"4--divide\n";
        cout<<"5--reduce only\n";
        cout<<"6--compare\n";
        cout<<"7--Exit\n";
        cout<<"Choose Operation: ";
        cin>>i;
        if(i==7){
            cout<<endl<<"Good Bye.."<<endl;
            break;
        }

        switch(i)
        {
            case 1:
                cout<<"Enter 1st Fraction: ";
                cin>>num1;
                cout<<"Enter 2nd Fraction: ";
                cin>>num2;
                num3 = num1+num2;
                cout<<"The product of the sum = "<<num3<<endl<<endl;
                break;
            case 2:
                cout<<"Enter 1st Fraction: ";
                cin>>num1;
                cout<<"Enter 2nd Fraction: ";
                cin>>num2;
                num3 = num1-num2;
                cout<<num3<<endl<<endl;
                break;
            case 3:
                cout<<"Enter 1st Fraction: ";
                cin>>num1;
                cout<<"Enter 2nd Fraction: ";
                cin>>num2;
                num3 = num1*num2;
                cout<<num3<<endl<<endl;
                break;
            case 4:
                cout<<"Enter 1st Fraction: ";
                cin>>num1;
                cout<<"Enter 2nd Fraction: ";
                cin>>num2;
                num3 = num1/num2;
                cout<<num3<<endl<<endl;
                break;
            case 5:
                cout<<"Enter Fraction: ";
                cin>>num1;
                cout<<num1.reduce(num1.getNomenator(),num1.getDenomenator())<<endl<<endl;
            case 6:
                cout<<"Enter 1st Fraction: ";
                cin>>num1;
                cout<<"Enter 2nd Fraction: ";
                cin>>num2;
                if(num1>num2)
                {
                    cout<<"num1 is grater than num2..\n";
                }else{
                    cout<<"num2 is grater than num1..\n";
                }
        }

    }
}

