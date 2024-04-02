#include "Faktura.h"
// ---------------PolozkaFaktury-----------------//
PolozkaFaktury::PolozkaFaktury(std::string nazov, double cena) {
	this->nazov = nazov;
	this->cena = cena;
};

double PolozkaFaktury::getCena() {
	return this->cena;
};

std::string PolozkaFaktury::getNazov() {
	return this->nazov;
};

// ---------------Faktura-----------------//
Faktura::Faktura(long long int number, const std::string& name, long long int rodneCislo, const std::string& address, int maxNum) {
	this->number = number;
	this->fakturant = new Person(name, rodneCislo, address);
	this->polozky = new PolozkaFaktury * [maxNum];
	this->count = 0;
};

Faktura::~Faktura() {
	for (int i = 0; i < this->count; ++i) {
		delete this->polozky[i];
	}
	delete[] this->polozky;
	delete fakturant;
};

PolozkaFaktury* Faktura::setPolozka(std::string nazov, double cena) {
	PolozkaFaktury* newPolozka = new PolozkaFaktury(nazov, cena);

	this->polozky[this->count] = newPolozka;
	this->count += 1;

	return newPolozka;
};

double Faktura::getCelkovaCena() {
	double sum = 0;
	for (int i = 0; i < this->count; ++i) {
		sum += this->polozky[i]->getCena();
	}
	return sum;
};

