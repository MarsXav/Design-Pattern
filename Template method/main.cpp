#include <iostream>
#include "Library.h"
#include "Library.cpp"

int main() {
    Library* library = new App();
    library -> run();
    return 0;
}
