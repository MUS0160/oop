#include "Person.h"

Person::Person(const std::string& name, long long int rodneCislo) {
	this->name = name;
	this->rodneCislo = rodneCislo;
};

Person::Person(const std::string& name, long long int rodneCislo, const std::string& address) {
	this->name = name;
	this->address = address;
	this->rodneCislo = rodneCislo;
};

void Person::showPerson() {
	std::cout << this->name;
	std::cout << this->address;
};

std::string& Person::getName() {
	return this->name;
}

std::string& Person::getAddress() {
	return this->address;
}

int Person::getAge() {
	int age = 0;
	long long int yearRodneCislo = this->rodneCislo;
	while (yearRodneCislo >= 100) {
		yearRodneCislo /= 10;
	}

	int currentYear = this->getActualYear();
	int lastTwoDigitsCurrentYear = currentYear % 100;
	if (yearRodneCislo > lastTwoDigitsCurrentYear) {
		age = int(lastTwoDigitsCurrentYear + (100 - yearRodneCislo));
	}
	else {
		age = int(lastTwoDigitsCurrentYear - yearRodneCislo);
	}
	return age;
};

std::string Person::getBirthDate() {
	std::string birthDate;
	int year = 0;
	int month = 0;
	int day = 0;
	long long int rodneCislo_rest = this->rodneCislo;
	while (rodneCislo_rest > 1000000) {
		rodneCislo_rest /= 10;
	}
	day = rodneCislo_rest % 100;
	while (rodneCislo_rest > 10000) {
		rodneCislo_rest /= 10;
	}
	month = rodneCislo_rest % 100;
	while (rodneCislo_rest > 100) {
		rodneCislo_rest /= 10;
	}
	year = rodneCislo_rest % 100;

	int currentYear = this->getActualYear();
	int lastTwoDigitsCurrentYear = currentYear % 100;
	if (year > lastTwoDigitsCurrentYear) {
		year = int(1900 + year);
	}
	else {
		year = int(2000 + year);
	}
	birthDate = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
	return birthDate;
};

bool Person::isMan() {
	int month = 0;
	long long int rodneCislo_rest = this->rodneCislo;
	while (rodneCislo_rest > 10000) {
		rodneCislo_rest /= 10;
	}
	month = int(rodneCislo_rest % 100);
	if (month <= 12) {
		return true;
	}
	else {
		return false;
	}
};

bool Person::isWoman() {
	return !this->isMan();
};

int Person::getActualYear() {
	std::time_t t = std::time(nullptr);
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
	std::tm* const pTInfo = std::localtime(&t);
	int currentYear = 1900 + +pTInfo->tm_year;
	return currentYear;
};

