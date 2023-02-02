#include "visitor.h"

int main(){
	Visitor2 visitor;
	ElementB elementB;
	// double dispatch
	elementB.accept(visitor); // ElementB -> accept(Visitor2->visitElementB(ElementB))

	ElementA elementA;
	elementA.accept(visitor);

	return 0;
}
