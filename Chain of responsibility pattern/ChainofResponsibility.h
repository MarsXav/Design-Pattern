#ifndef CHAIN_OF_RESPONSIBILITY_PATTERN_CHAINOFRESPONSIBILITY_H
#define CHAIN_OF_RESPONSIBILITY_PATTERN_CHAINOFRESPONSIBILITY_H

#include <string>

enum class RequestType{
	REQ_HANDLER1,
	REQ_HANDLER2,
	REQ_HANDLER3,
};

class Request{
private:
	std::string description;
	RequestType reqType;
public:
	Request(const std::string& desc, RequestType type) : description(desc), reqType(type){}
	RequestType getReqType() const {return reqType;}
	const std::string& getDescription() const {return description;}
};

class ChainHandler{
private:
	ChainHandler* m_nextChain; //polymophic pinter
	
	void sendRequestToNextHandler(const Request& req){
		if (m_nextChain) {
			m_nextChain->handle(req);
		}
	}

protected:
	virtual bool canHandleRequest(const Request& req) = 0;
	virtual void processRequest(const Request& req) = 0;

public:
	ChainHandler() {m_nextChain = nullptr;}
	void setNextChain(ChainHandler* next) {m_nextChain = next;}

	void handle(const Request& req){
		if (canHandleRequest(req)){
			processRequest(req);
		}	
		else {
			sendRequestToNextHandler(req);
		}
	}
};

class Handler1 : public ChainHandler{
protected:
	bool canHandleRequest(const Request& req) override {
		return req.getReqType() == RequestType::REQ_HANDLER1;
	}
	void processRequest(const Request& req) override{
		// process logic
		req.getDescription();
	}
};
class Handler2 : public ChainHandler{
protected:
	bool canHandleRequest(const Request& req) override {
		return req.getReqType() == RequestType::REQ_HANDLER2;
	}
	void processRequest(const Request& req) override{
		// process logic
		req.getDescription();
	}
};
class Handler3 : public ChainHandler{
protected:
	bool canHandleRequest(const Request& req) override {
		return req.getReqType() == RequestType::REQ_HANDLER3;
	}
	void processRequest(const Request& req) override{
		//process logic 
		req.getDescription();
	}
};
#endif
