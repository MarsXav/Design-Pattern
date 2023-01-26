#ifndef ADAPTER_PATTERN_ADAPTER_H
#define ADAPTER_PATTERN_ADAPTER_H

class Target{ //target interface
public:
	virtual void process()=0;
	virtual ~Target(){}
};

class Adaptee{
public:
	virtual void foo()=0;
	virtual int bar()=0;
	virtual ~Adaptee(){}

};

class OldClass : public Adaptee{ // old class contains old operations
	 //...
	 void foo() override {}
	 int bar() override {return 0;}
	
	 void process(){}


};

class Adapter : public Target{
protected:
	Adaptee* pAdaptee;
public:
	Adapter(Adaptee* adaptee) : pAdaptee(adaptee){}
	virtual void process(){
		int data = pAdaptee->bar();
		pAdaptee->foo();
	}
};

#endif
