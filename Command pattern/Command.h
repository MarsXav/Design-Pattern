#ifndef COMMAND_PATTERN_COMMAND_H
#define COMMAND_PATTERN_COMMAND_H

#include <string>
#include <vector>
#include <iostream>

class Receiver{
public:
	virtual void action() = 0;
};
class ReceiverChild : public Receiver {
public:
	void action() override {
		std::cout << "..." << std::endl;
	}
};

class Command{
public:
	virtual void execute() = 0;
};

// action objects : command1 & 2
class ConcreteCommand1 : public Command{
private:
	Receiver* receiver;
	std::string arg;
public:
	ConcreteCommand1(Receiver* rec, const std::string& a) : receiver(rec), arg(a){}
	void execute() override {
		receiver->action();
	}
};
class ConcreteCommand2 : public Command{
private:
	Receiver* receiver;
	std::string arg;
public:
	ConcreteCommand2(Receiver* rec, const std::string& a) : receiver(rec), arg(a){}
	void execute() override {
		receiver->action();
	}
};

class MacroCommand : public Command{
private:
	std::vector<Command*> commands;
public:
	void addCommand(Command* c) {
		commands.push_back(c);
	}
	void execute () override {
		for (auto& c : commands){
			c->execute();
		}
	}
};
#endif

