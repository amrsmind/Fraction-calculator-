#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>
#include <string>
#include <ostream>
#include <istream>
#include <cstdlib>

using namespace std;


class Fraction
{
public:
    int nume;
    int denom;
public:
Fraction();
Fraction(int up,int down);
void reducefraction(int &xnume,int &xdenom);
void addfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown);
void subtractfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown);
void multiplyfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown);
void dividefractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown);
bool greaterthan(int xnume,int xdenom,int ynume,int ydenom);
bool lessthanorequal(int xnume,int xdenom,int ynume,int ydenom);
bool lessthan(int xnume,int xdenom,int ynume,int ydenom);
bool greaterthanorequal(int xnume,int xdenom,int ynume,int ydenom);
Fraction operator+(const Fraction &bo);
Fraction operator-(const Fraction &bo);
Fraction operator*(const Fraction &bo);
Fraction operator/(const Fraction &bo);

bool operator>(const Fraction &bo);
bool operator<=(const Fraction &bo);
bool operator<(const Fraction &bo);
bool operator>=(const Fraction &bo);
bool operator==(const Fraction &bo);

friend ostream& operator<<(ostream& os,const Fraction &bo){
if(bo.nume==0) os<<0<<endl;
else if(bo.nume == bo.denom) os<<1<<endl;
else os<<bo.nume<<" / "<<bo.denom<<endl;
return os;
}
friend istream& operator>>(istream& is,Fraction &bo){
    if(bo.denom==0){cout <<"zero error, the denomenator can't be like that"<<endl;exit(0);}
    is>>bo.nume>>bo.denom;
    return is;
}


};
#endif // FRACTION_H_INCLUDED
