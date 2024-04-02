#pragma once
#include <iostream>
#include <string>
#include "Person.h"

class PolozkaFaktury {
private:
	std::string nazov;
	double cena;
public:
	PolozkaFaktury(std::string nazov, double cena);
	
	double getCena();
	std::string getNazov();
};

class Faktura {
private:
	long long int number;
	Person* fakturant;
	PolozkaFaktury** polozky;
	int count;
public:
	Faktura(long long int number, const std::string& name, long long int rodneCislo, const std::string& address, int maxNum);
	~Faktura();

	PolozkaFaktury* setPolozka(std::string nazov, double cena);
	double getCelkovaCena();

};