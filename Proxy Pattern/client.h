#ifndef PROXY_PATTERN_CLIENT_H
#define PROXY_PATTERN_CLIENT_H 

class Subject{
public:
	virtual void process() = 0;
};

class RealSubject : public Subject{
public:
	virtual void process(){
	//...
	}
};

class SubjectProxy : public Subject{
	RealSubject realsubject;
	Subject* subject;
public:
	virtual void process(){
	// an indirect access to the real subject	
	}
};

class ClientApp{
private:
	Subject* subject;
public:
	ClientApp(){
		subject = new SubjectProxy();	
	}
	void DoTask(){
		subject->process();
	}

};


#endif
