//
// Created by Dell on 2023/1/18.
//

#ifndef STRATEGY_PATTERN_TAXSTRATEGY_H
#define STRATEGY_PATTERN_TAXSTRATEGY_H


class TaxStrategy{
public:
    virtual double Calculate(double tax) = 0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Calculate(double tax) {return 0.0;}
};

class FRTax : public TaxStrategy{
public:
    virtual double Calculate(double tax) {return 0.0;}
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(double tax) {return 0.0;}
};


#endif //STRATEGY_PATTERN_TAXSTRATEGY_H
