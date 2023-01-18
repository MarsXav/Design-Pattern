//
// Created by Dell on 2023/1/18.
//
#include "TaxStrategy.h"
class CalculateTax{
private:
    TaxStrategy* taxStrategy;
public:
    CalculateTax(TaxStrategy* ts) : taxStrategy(ts){}
    void calculate(){
        taxStrategy ->Calculate(0.0);
    }
};