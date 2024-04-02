#pragma once
#include <iostream>
#include <string>

#include "Bank.h"

/*--------------------CLIENT--------------------*/

Client::Client(std::string name, long long int birthNo) {
	this->name = name;
	this->birthNo = birthNo;
};

long long int Client::GetBirthNo() {
	return this->birthNo;
};

std::string Client::GetName() {
	return this->name;
};


/*--------------------ACCOUNT--------------------*/

Account::Account(int accNumber, Client* owner) {
	this->accNumber = accNumber;
	this->balance = 0;
	this->accInterestRate = 0.02; //TO DO, set to basic interest rate of a bank
	this->accOwner = owner;
	this->accPartner = nullptr;
};

Account::Account(int accNumber, Client* owner, Client* partner) {
	this->accNumber = accNumber;
	this->balance = 0;
	this->accInterestRate = 0.02;
	this->accOwner = owner;
	this->accPartner = partner;
};

Account::Account(int accNumber, Client* owner, double accInterestRate) {
	this->accNumber = accNumber;
	this->balance = 0;
	this->accInterestRate = accInterestRate;
	this->accOwner = owner;
	this->accPartner = nullptr;
};

Account::Account(int accNumber, Client* owner, Client* partner, double accInterestRate) {
	this->accNumber = accNumber;
	this->balance = 0;
	this->accInterestRate = accInterestRate;
	this->accOwner = owner;
	this->accPartner = partner;
};

int Account::GetNumber() {
	return this->accNumber;
};

double Account::GetBalance() {
	return this->balance;
};

double Account::GetInterestRate() {
	return this->accInterestRate;
};

Client* Account::GetOwner() {
	return this->accOwner;
};

bool Account::IsPartner() {
	if (this->accPartner == nullptr) {
		return false;
	}
	return true;
};

Client* Account::GetPartner() {
	return this->accPartner;
};

bool Account::CanWithdraw() {
	if (this->balance > 0) {
		return true;
	}
	return false;
};

bool Account::Withdraw(double sum) {
	if (this->balance > sum) {
		this->balance -= sum;
		return true;
	}
	return false;
};

void Account::Deposit(double sum) {
	this->balance += sum;
};

void Account::AddInterest() {
	this->balance += (this->balance * this->accInterestRate);
};



/*--------------------BANK--------------------*/

Bank::Bank(int totalAccCount, int totalClientCount) {
	this->accounts = new Account * [totalAccCount];
	this->accountCount = 0;
	this->clients = new Client * [totalClientCount];
	this->clientCount = 0;
	this->basicInterestRate = 0.02;
};

Bank::~Bank() {
	for (int i = 0; i < this->accountCount; ++i) {
		delete this->accounts[i];
	}
	delete[] this->accounts;

	for (int i = 0; i < this->clientCount; ++i) {
		delete this->clients[i];
	}
	delete[] this->clients;
};

Client* Bank::GetClient(long long int birthNo) {
	for (int i = 0; i < this->clientCount; ++i) {
		if (this->clients[i]->GetBirthNo() == birthNo) {
			return this->clients[i];
		}
	}
	return nullptr;
};

Account* Bank::GetAccount(int accNumber) {
	for (int i = 0; i < this->accountCount; ++i) {
		if (this->accounts[i]->GetNumber() == accNumber) {
			return this->accounts[i];
		}
	}
	return nullptr;
};

Client* Bank::CreateClient(std::string name, long long int birthNo) {
	Client* newClient = new Client(name, birthNo);
	this->clients[this->clientCount] = newClient;
	this->clientCount += 1;
	return newClient;
};

Account* Bank::CreateAccount(int accNumber, Client* owner) {
	Account* newAccount = new Account(accNumber, owner);
	this->accounts[this->accountCount] = newAccount;
	this->accountCount += 1;
	return newAccount;
};

Account* Bank::CreateAccount(int accNumber, Client* owner, Client* partner) {
	Account* newAccount = new Account(accNumber, owner, partner);
	this->accounts[this->accountCount] = newAccount;
	this->accountCount += 1;
	return newAccount;
};

Account* Bank::CreateAccount(int accNumber, Client* owner, double accInterestRate) {
	Account* newAccount = new Account(accNumber, owner, accInterestRate);
	this->accounts[this->accountCount] = newAccount;
	this->accountCount += 1;
	return newAccount;
};

Account* Bank::CreateAccount(int accNumber, Client* owner, Client* partner, double accInterestRate) {
	Account* newAccount = new Account(accNumber, owner, partner, accInterestRate);
	this->accounts[this->accountCount] = newAccount;
	this->accountCount += 1;
	return newAccount;
};

void Bank::AddInterest() {
	for (int i = 0; i < this->accountCount; ++i) {
		this->accounts[i]->AddInterest();
	}
};




