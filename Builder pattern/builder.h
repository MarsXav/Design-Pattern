//
// Created by Dell on 2023/1/22.
//

#ifndef BUILDER_PATTERN_BUILDER_H
#define BUILDER_PATTERN_BUILDER_H

#include <bits/stdc++.h>

using namespace std;

class House { //representation of object
public:
    //...
};

class HouseBuilder { // construction of object
protected:
    House *pHouse{};

public:
    inline House *GetResult() { return pHouse; }

    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual void BuildPart3() = 0;

    virtual ~HouseBuilder() = default;
};

class StoneHouse : public House {
public:
    //...
};

class StoneHouseBuilder : public HouseBuilder {
public:
    void BuildPart1() override {}
    void BuildPart2() override {}
    void BuildPart3() override {}
};

class HouseDirector{
protected:
    HouseBuilder *pHouseBuilder;
public:
    explicit HouseDirector(HouseBuilder *houseBuilder) : pHouseBuilder(houseBuilder) {}

    House *Construct() {
        pHouseBuilder->BuildPart1();
        pHouseBuilder->BuildPart2();
        pHouseBuilder->BuildPart3();
        return pHouseBuilder->GetResult();
    }
};

#endif //BUILDER_PATTERN_BUILDER_H
