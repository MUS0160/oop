#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Person {
public:
	Person(const std::string& name, const int rodneCislo);
	Person(const std::string& name, const int rodneCislo, const std::string &address);

	void showPerson();
	std::string& getName();
	void


private:
	std::string name;
	std::string address;
	int rodneCislo;
};

