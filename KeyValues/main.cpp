#include <iostream>
#include <limits>
#include "KeyValues.h"


int main() {
	int N = 10;
	KeyValues* kvl = new KeyValues(N);
	for (int indx = 0; indx < N; ++indx) {
		kvl->CreateObject(indx, indx/2.0);
	}
	for (int indx = 0; indx < kvl->Count(); ++indx) {
		//because SearchObject may return nullptr, calling method of returned KeyValue is incorrect, need to rework, 
		// first check obj. returned from SearchObject and only if correct call it's method
		std::cout << indx << ": " << kvl->SearchObject(indx)->GetValue() << std::endl;
	}
	
	KeyValue* kvret = kvl->RemoveObject(5);
	
	std::cout << std::endl;
	for (int indx = 0; indx < kvl->Count(); ++indx) {
		std::cout << indx << ": " << kvl->SearchObject(indx)->GetValue() << std::endl;
	}
	delete kvret;
	delete kvl;	
	
	return 0;
}