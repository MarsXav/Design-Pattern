#include <bits/stdc++.h>
#include "Splitter.h"
using namespace std;
int main() {
    SplitterFactory* sf = new BinarySplitterFactory();
    auto* mainForm = new MainForm(sf);
    mainForm -> Process();

    return 0;
}
