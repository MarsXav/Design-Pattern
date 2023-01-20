#include <iostream>
#include "SplitterPrototype.h"

int main() {
    auto* binarySplitter = new BinarySplitter();
    auto* mf = new MainForm(binarySplitter);
    mf->Process();
    delete binarySplitter;
    return 0;
}
