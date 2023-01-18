//
// Created by Dell on 2023/1/18.
//

#ifndef TEMPLATE_METHOD_LIBRARY_H
#define TEMPLATE_METHOD_LIBRARY_H

#include <bits/stdc++.h>
using namespace std;

class Library {
public:
    void run(); //stable operation
protected:
    void step1() {} //stable step
    void step2() {} //stable step

    virtual void step3() = 0; //unstable step
    virtual void step4() = 0; //unstable step

};


#endif //TEMPLATE_METHOD_LIBRARY_H
