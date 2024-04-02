#include <stdio.h>
#include <iostream>

#include "KeyValue.h"


int main() {
	KeyValue* kvlist[1000];
	kvlist[0] = new KeyValue(0, 0.5);
	int n = 10;
	for (int indx = 1; indx < n; ++indx) {
		double val = double(indx) / 2.0;
		kvlist[indx] = (kvlist[indx - 1])->createNext(indx, val);
	}
	
	KeyValue* iter = kvlist[0];
	while (iter) {
		std::cout << iter->getKey() << " | " << iter->getValue() << std::endl;
		iter = iter->getNext();
	}

	delete kvlist[0];
	
	return 0;
}

