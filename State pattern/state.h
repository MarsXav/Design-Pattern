#ifndef STATE_PATTER_STATE_H
#define STATE_PATTER_STATE_H

// 

class NetworkStates{
public:
	NetworkStates* pNextState;
	virtual void Operation1() = 0;
	virtual void Operation2() = 0;
	virtual void Operation3() = 0;

	virtual ~NetworkStates();
};

class OpenState;
class CloseState;
class ConnectState;

class OpenState : public NetworkStates{
	static NetworkStates* m_instance;
public:
	static NetworkStates* getInstance(){
		if (m_instance == nullptr){
			m_instance = new OpenState();
		}
		return m_instance;
	}

	void Operation1(){
		// ...
		pNextState = CloseState::getInstance();
	}
	void Operation2() {
		// ...
		pNextState = ConnectState::getInstance();
	}
	void Operation3(){
		// ...
		pNextState = OpenState::getInstance();
	}
	
};

class CloseState : public NetworkStates{
	static NetworkStates* m_instance;
public:
	static NetworkStates* getInstance() {
		if (m_instance == nullptr) {
			m_instance = new CloseState();
		}
		return m_instance;
	}

	void Operation1() {}
	void Operation2() {}
	void Operation3() {}
};

class ConnectState : public NetworkStates{
	static NetworkStates* m_instance;
public:
	static NetworkStates* getInstance(){
		if (m_instance == nullptr){
			m_instance = new ConnectState();
		}
		return m_instance;
	}

	void Operation1() {}
	void Operation2() {}
	void Operation3() {}
};

class NetworkProcessor{
protected:
	NetworkStates* pState;
public:
	NetworkProcessor(NetworkStates* networkState) : pState(networkState){}
	
	void Operation1() {
		pState->Operation1();
		pState = pState->pNextState;
	}
	void Operation2(){
		pState->Operation2();
		pState = pState->pNextState;
	}
	void Operation3(){
		pState->Operation3();
		pState = pState->pNextState;
	}
};


#endif
