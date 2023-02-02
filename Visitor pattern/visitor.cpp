#include "visitor.h"

void ElementA::accept(Visitor& visitor) {
	visitor.visitElementA(*this);	
}

void ElementB::accept(Visitor& visitor){
	visitor.visitElementB(*this);
}

void Visitor1::visitElementA(ElementA& element) {
	std::cout << "Visitor1 is processing ElementA" << std::endl;
}
void Visitor1::visitElementB(ElementB& element){
	std::cout << "Visitor1 is processing ElementB" << std::endl;
}
void Visitor2::visitElementA(ElementA& element) {
	std::cout << "Visitor1 is processing ElementA" << std::endl;
}
void Visitor2::visitElementB(ElementB& element){
	std::cout << "Visitor1 is processing ElementB" << std::endl;
}
