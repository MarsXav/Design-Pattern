#include <iostream>
#include "TaxStrategy.h"
#include "TaxStrategy.cpp"

int main() {
    auto cn = new CNTax();
    auto tax = new CalculateTax(cn);
    tax -> calculate();

    return 0;
}
