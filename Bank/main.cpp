#pragma once
#include <iostream>
#include "Bank.h"

void BankSimul(int, int);
void createClient(Bank*, const std::string, long long int);
void createAccount(Bank*, int, Client*);
void createAccount(Bank*, int, Client*, Client*);

int main() {
	int countAcc = 10;
	int countCl = 10;
	
	BankSimul(countAcc,countCl);

	return 0;
}

void BankSimul(int countAcc, int countCl) {
	Bank* bank = new Bank(countAcc, countCl);
	
	const char* namesOwner[4] = {"Juraj Musil", "JMusil", "MusilJ", "Musil"};
	long long int birthNumbers[4] = { 1000000000, 2000000000, 3000000000, 4000000000 };
	const char* namesPartners[4] = { "JM1", "JM2", "JM3", "JM4" };
	long long int birthNumbersPart[4] = { 7800000001, 7800000002, 7800000003, 7800000004 };
	int namesCount = 4;

	int accNumbers[4] = { 1001, 1002, 1003, 1004 };
	int accNumbersPartners[4] = { 2001, 2002, 2003, 2004 };
	int accCount = 4;

	/*CREATE CLIENTS - OWNER*/
	for (int i = 0; i < namesCount; ++i) {
		createClient(bank, namesOwner[i], birthNumbers[i]);
	}
	/*CREATE CLIENTS - PARTNER*/
	for (int i = 0; i < namesCount; ++i) {
		createClient(bank, namesPartners[i], birthNumbersPart[i]);
	}

	/*CREATE ACCOUNTS - NO PARTNERS*/
	for (int i = 0; i < accCount; ++i) {
		Client* owner = bank->GetClient(birthNumbers[i]);
		createAccount(bank, accNumbers[i], owner);
	}
	
	/*CREATE ACCOUNTS - WITH PARTNERS*/
	for (int i = 0; i < accCount; ++i) {
		Client* owner = bank->GetClient(birthNumbers[i]);
		Client* partner = bank->GetClient(birthNumbersPart[i]);
		createAccount(bank, accNumbersPartners[i], owner, partner);
	}

	/*MAKE DEPOSITS*/
	for (int i = 0; i < accCount; ++i) {
		Account* acc1 = bank->GetAccount(accNumbers[i]);
		Account* acc2 = bank->GetAccount(accNumbersPartners[i]);
		acc1->Deposit(i * 1000 + 100);
		acc2->Deposit(i * 1200 + 200);
	}

	/*CHECK DEPOSIT*/
	for (int i = 0; i < accCount; ++i) {
		Account* acc1 = bank->GetAccount(accNumbers[i]);
		Account* acc2 = bank->GetAccount(accNumbersPartners[i]);
		std::cout << acc1->GetNumber() << " | " << acc1->GetOwner()->GetName() << " | " << acc1->GetBalance() << std::endl;
		std::cout << acc2->GetNumber() << " | " << acc2->GetOwner()->GetName() << " | " << acc2->GetPartner()->GetName() << " | " << acc2->GetBalance() << std::endl;
		std::cout << acc1->GetNumber() << " | " << acc1->GetInterestRate() << std::endl;
		std::cout << acc2->GetNumber() << " | " << acc1->GetInterestRate() << std::endl;
	}

	/*ADD INTERESR*/
	bank->AddInterest();
	
	std::cout << std::endl;
	/*CHECK DEPOSIT*/
	for (int i = 0; i < accCount; ++i) {
		Account* acc1 = bank->GetAccount(accNumbers[i]);
		Account* acc2 = bank->GetAccount(accNumbersPartners[i]);
		std::cout << acc1->GetNumber() << " | " << acc1->GetOwner()->GetName() << " | " << acc1->GetBalance() << std::endl;
		std::cout << acc2->GetNumber() << " | " << acc2->GetOwner()->GetName() << " | " << acc2->GetPartner()->GetName() << " | " << acc2->GetBalance() << std::endl;
		
	}

}

void createClient(Bank* bank, std::string name, long long int id) {
	bank->CreateClient(name, id);
	Client* ja = bank->GetClient(id);
	/*
	if (ja != nullptr) {
		std::cout << ja->GetName() << " | " << ja->GetBirthNo() << std::endl;
	}
	else {
		std::cout << "nullptr" << std::endl;
	}
	*/
}

void createAccount(Bank* bank, int accNo, Client* owner) {
	Account* acc = bank->CreateAccount(accNo, owner);
	/*
	if (acc != nullptr) {
		std::cout << acc->GetOwner()->GetName() << " | " << acc->GetNumber() << std::endl;
	}
	*/
}

void createAccount(Bank* bank, int accNo, Client* owner, Client* partner) {
	Account* acc = bank->CreateAccount(accNo, owner, partner);
	/*
	if (acc != nullptr) {
		std::cout << acc->GetOwner()->GetName() << " | " << acc->GetPartner()->GetName() << " | " << acc->GetNumber() << std::endl;
	}
	*/
}
