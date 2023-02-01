#include "Command.h"

int main(){
	auto* receiver = new ReceiverChild();
	ConcreteCommand1 command1(receiver, "Arg ###");
	ConcreteCommand2 command2(receiver, "Arg $$$");
	
	MacroCommand macro;
	macro.addCommand(&command1);
	macro.addCommand(&command2);

	macro.execute();
	return 0;
}
