#ifndef COMPOSITE_PATTERN_COMPOSITE_H
#define COMPOSITE_PATTERN_COMPOSITE_H

#include <algorithm>
#include <list>
#include <string>
#include <iostream>

class  Component{
public:
	virtual void process() = 0;
	virtual ~Component() = default;
};

// root nodes
class Composite : public Component {
private:
	std::string name;
	std::list<Component*> elements;
public:
	Composite(const std::string& s) : name(s){}
	void add(Component* element) {
		elements.push_back(element);
	} 
	void remove (Component* element) {
		elements.remove(element);
	}
	void process(){

		// process current nodes
		std::cout << "processing root nodes" << std::endl;		
		// process leaf nodes
		for (auto& e : elements){
			e->process(); // polymorphic evoking
			std::cout << "processing leaf nodes" << std::endl;
		}
	}
};

// leaf nodes
class Leaf : public Component{
private:
	std::string name;
public:
	Leaf(std::string s) : name(s){}

	void process(){
		// process current node	
		std::cout << "processing leaf nodes" << std::endl;
	}
};

void Invoke(Component& C){
	C.process();
}

#endif
