//
// Created by Dell on 2023/1/20.
//

#ifndef PROTOTYPE_PATTERN_SPLITTERPROTOTYPE_H
#define PROTOTYPE_PATTERN_SPLITTERPROTOTYPE_H
#include <bits/stdc++.h>
using namespace std;

class Splitter { //abstract class
public:
    virtual void split() = 0;

    virtual Splitter* clone() = 0; //create object by cloning itself

    virtual ~Splitter(){
        cout << "deleted splitter" << endl;
    };
};

class BinarySplitter : public Splitter{ //detailed class
public:
    BinarySplitter()= default;
    BinarySplitter(BinarySplitter& B) {B = *this;}
    Splitter* clone() override{
        cout << "cloned a Binary Splitter class" << endl;
        return new BinarySplitter(*this);
    }
    void split() override{
        cout << "Split operation" << endl;
    }

};


class MainForm{
protected:
    BinarySplitter* prototype;
public:
    explicit MainForm(BinarySplitter* splitter) : prototype(splitter){} // input a detailed factory

    void Process(){
        Splitter* splitter = prototype->clone(); //clone prototype to obtain a new object
        splitter->split();
    }
};

#endif //PROTOTYPE_PATTERN_SPLITTERPROTOTYPE_H