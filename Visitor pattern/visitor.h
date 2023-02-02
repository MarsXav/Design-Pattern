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
	void accept (Visitor& visitor) override;
};
class ElementB : public Element{
public:
	void accept (Visitor& visitor) override;
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
	void visitElementA(ElementA& element) override;
	void visitElementB(ElementB& element) override;
};
//expansion 2
class Visitor2 : public Visitor {
public:
	void visitElementA(ElementA& element) override;
	void visitElementB(ElementB& element) override ;
};


#endif
