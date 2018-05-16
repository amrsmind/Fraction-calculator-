#include "Fraction.h"
#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <cstdlib>

using namespace std;

Fraction::Fraction()
{
nume = 0;

}
Fraction::Fraction(int up,int down){
nume = up;
if(down!=0) denom = down;
else {cout <<"zero error, the denomenator can't be like that"<<endl;exit(0);}
reducefraction(nume,denom);
}
void Fraction::reducefraction(int &xnume,int &xdenom){
    bool negativenume=0;
    bool negativedenom=0;
    if(xnume<0){negativenume=1;}
    if(xdenom<0){negativedenom=1;}
    int xnumeabs = abs(xnume);
    int xdenomabs = abs(xdenom);
if(xdenomabs>=xnumeabs){
    for(int i=xnumeabs;i>=2;i--){
        if(xdenomabs%i==0 && xnumeabs%i==0){
            xnumeabs = xnumeabs/i;
            xdenomabs = xdenomabs/i;
        }
    }

}
else if(xnumeabs>xdenomabs){
    for(int i=xdenomabs;i>=2;i--){
        if(xdenomabs%i==0 && xnumeabs%i==0){
            xnumeabs = xnumeabs/i;
            xdenomabs = xdenomabs/i;

        }
    }

}
    xnume = xnumeabs;
    xdenom = xdenomabs;
    if(negativenume) xnume = 0-xnume;
    if(negativedenom) xdenom = 0-xdenom;
}

void Fraction::addfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown){
    int newdenom;
    int resultnume;
   // int resultdenom;
    if(xdenom!=ydenom){
        newdenom = xdenom * ydenom;
        xnume = (newdenom/xdenom)*xnume;
        ynume = (newdenom/ydenom)*ynume;
        resultnume = xnume + ynume;
    }
    else{
        newdenom = xdenom;
        resultnume = xnume + ynume;
    }
    reducefraction(resultnume,newdenom);
    resultup = resultnume;
    resultdown = newdenom;
}
void Fraction::subtractfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown){
    int newdenom;
    int resultnume;
   // int resultdenom;
    if(xdenom!=ydenom){
        newdenom = xdenom * ydenom;
        xnume = (newdenom/xdenom)*xnume;
        ynume = (newdenom/ydenom)*ynume;
        resultnume = xnume - ynume;
    }
    else{
        newdenom = xdenom;
        resultnume = xnume - ynume;
    }
            reducefraction(resultnume,newdenom);
            resultup=resultnume;
            resultdown=newdenom;
}
void Fraction::multiplyfractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown){
int resultnume = xnume * ynume;
int resultdenom = xdenom * ydenom;
reducefraction(resultnume,resultdenom);
resultup = resultnume;
resultdown = resultdenom;
}

void Fraction::dividefractions(int xnume,int xdenom,int ynume,int ydenom,int &resultup,int &resultdown){
multiplyfractions(xnume,xdenom,ydenom,ynume,resultup,resultdown);
}
bool Fraction::greaterthan(int xnume,int xdenom,int ynume,int ydenom){
if((xnume+.0/xdenom)>(ynume+.0/ydenom)) return true;
else return false;
}
bool Fraction::lessthanorequal(int xnume,int xdenom,int ynume,int ydenom){
if(!greaterthan(xnume,xdenom,ynume,ydenom)) return true;
else return false;
}
bool Fraction::lessthan(int xnume,int xdenom,int ynume,int ydenom){
if((xnume+.0/xdenom)<(ynume+.0/ydenom)) return true;
else return false;
}
bool Fraction::greaterthanorequal(int xnume,int xdenom,int ynume,int ydenom){
if(!lessthan(xnume,xdenom,ynume,ydenom)) return true;
else return false;
}

Fraction Fraction::operator+(const Fraction &bo){
    Fraction temp;
 addfractions(nume,denom,bo.nume,bo.denom,temp.nume,temp.denom);
 return temp;

}
Fraction Fraction::operator-(const Fraction &bo){
    Fraction temp;
 subtractfractions(nume,denom,bo.nume,bo.denom,temp.nume,temp.denom);
 return temp;
}
Fraction Fraction::operator*(const Fraction &bo){
    Fraction temp;
 multiplyfractions(nume,denom,bo.nume,bo.denom,temp.nume,temp.denom);
 return temp;

}
Fraction Fraction::operator/(const Fraction &bo){
    Fraction temp;
 dividefractions(nume,denom,bo.nume,bo.denom,temp.nume,temp.denom);
 return temp;
}
bool Fraction::operator>(const Fraction &bo){
return greaterthan(nume,denom,bo.nume,bo.denom);
}
bool Fraction::operator<=(const Fraction &bo){
return lessthanorequal(nume,denom,bo.nume,bo.denom);
}
bool Fraction::operator<(const Fraction &bo){
return lessthan(nume,denom,bo.nume,bo.denom);
}
bool Fraction::operator>=(const Fraction &bo){
return greaterthanorequal(nume,denom,bo.nume,bo.denom);
}
bool Fraction::operator==(const Fraction &bo){
return !(greaterthan(nume,denom,bo.nume,bo.denom)) && !(lessthan(nume,denom,bo.nume,bo.denom));
}







