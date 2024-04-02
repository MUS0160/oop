#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <ctime>

class Person {
public:
	Person(const std::string& name, long long int rodneCislo);
	Person(const std::string& name, long long int rodneCislo, const std::string& address);

	void showPerson();
	std::string& getName();
	std::string& getAddress();
	int getAge();
	std::string getBirthDate();
	bool isMan();
	bool isWoman();

private:
	std::string name;
	std::string address;
	long long int rodneCislo;

	int getActualYear();
};
