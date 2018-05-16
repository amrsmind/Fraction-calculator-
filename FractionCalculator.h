#ifndef FRACTIONCALCULATOR_H_INCLUDED
#define FRACTIONCALCULATOR_H_INCLUDED

#include <iostream>
#include "Fraction.h"

using namespace std;

class FractionCalculator:public Fraction{
private:
    int up;
    int down;
public:
    FractionCalculator();
};



#endif // FRACTIONCALCULATOR_H_INCLUDED
