#include <iostream>
#include "FractionCalculator.h"
#include "Fraction.h"
#include <cstdlib>

using namespace std;

FractionCalculator::FractionCalculator(){
Fraction temp;
Fraction temp1;
Fraction temp2;
cout <<"please enter the fraction : "<<endl;
cin >>temp1;
cout <<"enter the another fraction : "<<endl;
cin >>temp2;
cout <<"enter the operation (+)(-)(*)(/)"<<endl;
char choice;
cin >>choice;
switch(choice){
case '+':
    temp = temp1 + temp2;
    break;
case '-':
    temp = temp1 - temp2;
    break;
case '*':
    temp = temp1 * temp2;
    break;
case '/':
    temp = temp1 / temp2;
    break;
default:
    cout <<"you enter wrong operation"<<endl;
    exit(0);
}
up = temp.nume;
down = temp.denom;
cout <<"the result is : "<<temp;
cout <<"do you want to do another operation on the result(y/n) ? "<<endl;
cin >> choice;
while (choice == 'y'){

cout <<"enter the another fraction : "<<endl;
cin >>temp2;
cout <<"enter the operation (+)(-)(*)(/)"<<endl;
char choice;
cin >>choice;
switch(choice){
case '+':
    temp = temp + temp2;
    break;
case '-':
    temp = temp - temp2;
    break;
case '*':
    temp = temp * temp2;
    break;
case '/':
    temp = temp / temp2;
    break;
default:
    cout <<"you enter wrong operation"<<endl;
    exit(0);
}
up = temp.nume;
down = temp.denom;
cout <<"the result is : "<<temp;
cout <<"do you want to do another operation on the result(y/n) ? "<<endl;
cin >> choice;
}}
