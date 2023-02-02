#ifndef VISITOR_PATTERN_VISITOR_H
#define VISITOR_PATTERN_VISITOR_H

#include <iostream>

class Visitor;

class Element{
public:
	virtual void accept(Visitor& visitor) = 0;
	virtual ~Element() = default;
};

class ElementA : public Element{
public:
	void accept (Visitor& visitor) override {
		visitor.visitElementA(*this);	
	}
};
class ElementB : public Element{
public:
	void accept (Visitor& visitor) override {
		visitor.visitElementB(*this);	
	}
};

//expansion base class
class Visitor {
public:
	virtual void visitElementA(ElementA& element) = 0;
	virtual void visitElementB(ElementB& element) = 0;
	virtual ~Visitor() = default;
};

//expansion 1
class Visitor1 : public Visitor {
public:
	void visitElementA(ElementA& element) override {
		std::cout << "Visitor1 is processing ElementA" << std::endl;
	}
	void visitElementB(ElementB& element) override {
		std::cout << "Visitor1 is processing ElementB" << std::endl;
	}
};
//expansion 2
class Visitor2 : public Visitor {
public:
	void visitElementA(ElementA& element) override {
		std::cout << "Visitor2 is processing ElementA" << std::endl;
	}
	void visitElementB(ElementB& element) override {
		std::cout << "Visitor2 is processing ElementB" << std::endl;
	}
};


#endif
