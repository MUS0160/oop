#pragma once
#include "KeyValue.h"

KeyValue::KeyValue(int n, double v) {
	this->key = n;
	this->value = v;
	this->next = nullptr;
};

KeyValue::~KeyValue() {
	if (this->next != nullptr) {
		delete this->next;
		this->next = nullptr;
	}
};

int KeyValue::getKey() {
	return this->key;
};

double KeyValue::getValue() {
	return this->value;
};

KeyValue* KeyValue::getNext() {
	return this->next;
};

KeyValue* KeyValue::createNext(int n, double v) {
	this->next = new KeyValue(n, v);
	return this->next;
};
