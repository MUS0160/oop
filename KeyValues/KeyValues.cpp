#pragma once
#include <iostream>
#include "KeyValues.h"

// ---------------KeyValue-----------------//
KeyValue::KeyValue(int n, double v) {
	this->key = n;
	this->value = v;
};

int KeyValue::GetKey() {
	if (this != nullptr) {
		return this->key;
	}
	return std::numeric_limits<int>::min();;
};

double KeyValue::GetValue() {
	if (this != nullptr) {
		return this->value;
	}
	return std::numeric_limits<int>::min();;
};

// ---------------KeyValues-----------------//
KeyValues::KeyValues(int n) {
	this->keyValues = new KeyValue* [n];
	this->count = 0;
};

KeyValues::~KeyValues() {
	for (int i = 0; i < this->count; ++i) {
		delete this->keyValues[i];
	}
	delete[] this->keyValues;
};

KeyValue* KeyValues::CreateObject(int k, double v) {
	KeyValue* newObject = new KeyValue(k, v);
	
	this->keyValues[this->count] = newObject;
	this->count += 1;

	return newObject;
};

KeyValue* KeyValues::SearchObject(int key) {
	for (int i = 0; i < this->count; ++i) {
		if (this->keyValues[i]->GetKey() == key) {
			return this->keyValues[i];
		}
	}
	return nullptr;
};

KeyValue* KeyValues::RemoveObject(int key) {
	
	for (int indx = 0; indx < this->count; ++indx) {
		if (this->keyValues[indx]->GetKey() == key) {
			KeyValue* ret = this->keyValues[indx];
			this->keyValues[indx] = this->keyValues[(this->count)-1];
			this->keyValues[(this->count)-1] = nullptr;
			this->count = (this->count) - 1;
			return ret;
		}
	}
	return nullptr;
};

int KeyValues::Count() {
	return this->count;
};