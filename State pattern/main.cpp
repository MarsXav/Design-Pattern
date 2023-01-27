#include "state.h"

int main(){
	NetworkStates* state = OpenState::getInstance();
	auto* processor = new NetworkProcessor(state);
	processor->Operation1();
	processor->Operation2();
	processor->Operation3();

	return 0;
}
