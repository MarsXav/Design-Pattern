#include "ChainofResponsibility.h"

int main(){
	Handler1 h1;
	Handler2 h2;
	Handler3 h3;
	h1.setNextChain(&h2);
	h2.setNextChain(&h3);

	Request req("processing tasks", RequestType::REQ_HANDLER3);
	h1.handle(req);
	return 0;
}
