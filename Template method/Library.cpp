//
// Created by Dell on 2023/1/18.
//

#include "Library.h"

class App : public Library{
protected:
    virtual void step3() {cout << "overwrite step3";} //overwrite in child class
    virtual void step4() {cout << "overwrite step4";} //overwrite in child class
};

void Library::run() {
    step1();
    step4();
    step2();
    step3();
}