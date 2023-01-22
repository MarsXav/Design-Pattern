#include <iostream>
#include "builder.h"

int main() {
    auto* stoneHouseBuilder = new StoneHouseBuilder();
    auto* houseDirector = new HouseDirector(stoneHouseBuilder);
    houseDirector->Construct();
    return 0;
}
