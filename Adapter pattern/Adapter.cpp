#include "Adapter.h"

void Process(){
	Adaptee* adaptee = new OldClass();
	Target* target = new Adapter(adaptee);
	target->process();
}

