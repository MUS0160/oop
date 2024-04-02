#pragma once
#include <iostream>

class KeyValue{
private:
	int key;
	double value;
	KeyValue* next;

public:
	KeyValue(int n, double v);
	~KeyValue();
	
	int getKey();
	double getValue();

	KeyValue* getNext();
	KeyValue* createNext(int n, double v);
};