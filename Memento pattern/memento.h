#ifndef MEMENTO_PATTERN_MEMENTO_H
#define MEMENTO_PATTERN_MEMENTO_H

#include <iostream>

class Memento{
private:
	std::string state;
public:
	Memento(const std::string& s) : state(s){}
	std::string getState() const {return state;} 
	void setState(const std::string& s) {state = s;}
};

class Originator{
private:
	std::string state;
public:
	Originator() = default;
	Memento createMomento(){
		Memento m(state);
		return m;
	}
	void setMomento(const Memento& m){
		state = m.getState();
	}
};

void Process(){
	Originator originator;

	// store into the memento 
	Memento mem = originator.createMomento();

	//state changed due to services
	mem.setState("state");

	//revert back to the original state;
	originator.setMomento(mem);
}
#endif

