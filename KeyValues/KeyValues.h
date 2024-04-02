#pragma once
#include <iostream>

// ---------------KeyValue-----------------//
class KeyValue {
private:
	int key;
	double value;

public:
	KeyValue(int n, double v);
	int GetKey();
	double GetValue();
};

// ---------------KeyValues-----------------//
class KeyValues {
private:
	KeyValue** keyValues;
	int count;
public:
	KeyValues(int n);
	~KeyValues();
	KeyValue* CreateObject(int k, double v);
	KeyValue* SearchObject(int key);
	KeyValue* RemoveObject(int key);
	int Count();
};