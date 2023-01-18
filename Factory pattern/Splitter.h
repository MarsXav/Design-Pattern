//
// Created by Dell on 2023/1/18.
//

#ifndef FACTORY_PATTERN_SPLITTER_H
#define FACTORY_PATTERN_SPLITTER_H

#include <bits/stdc++.h>
using namespace std;

class Splitter { //abstract class
public:
    virtual void split() = 0;
    virtual ~Splitter(){}
};

class BinarySplitter : public Splitter{ //detailed class
    virtual void split(){}
};

class SplitterFactory{ //factory base class
public:
    virtual Splitter* CreateSplitter() = 0;
    virtual ~SplitterFactory(){}
};

class BinarySplitterFactory : public SplitterFactory{ //detailed factories
public:
    virtual Splitter* CreateSplitter(){
        return new BinarySplitter();
    }

};

class MainForm{
protected:
    SplitterFactory* factory;
public:
    MainForm(SplitterFactory* sf) : factory(sf){} // input a detailed factory

    void Process(){
        Splitter* splitter = factory -> CreateSplitter(); // polymorphic new
        splitter ->  split();
    }
};

#endif //FACTORY_PATTERN_SPLITTER_H
