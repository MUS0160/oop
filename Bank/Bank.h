#pragma once
#include <string>

/*--------------------CLIENT--------------------*/
class Client {
private:
	std::string name;
	long long int birthNo;
public:
	Client(std::string name, long long birthNo);

	long long int GetBirthNo();
	std::string GetName();
};


/*--------------------ACCOUNT--------------------*/
class Account {
private:
	int accNumber;
	double balance;
	double accInterestRate;
	Client* accOwner;
	Client* accPartner;
public:
	Account(int accNumber, Client* owner);
	Account(int accNumber, Client* owner, Client* partner);
	Account(int accNUmber, Client* owner, double accInterestRate);
	Account(int accNUmber, Client* owner, Client* partner, double accInterestRate);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();

	Client* GetOwner();
	bool IsPartner();
	Client* GetPartner();

	bool CanWithdraw();
	bool Withdraw(double sum);
	void Deposit(double sum);
	void AddInterest();
};


/*--------------------BANK--------------------*/
class Bank {
private:
	Account** accounts;
	int accountCount;
	Client** clients;
	int clientCount;
	double basicInterestRate;

public:
	Bank(int totalAccCount, int totalClientCount);
	~Bank();

	Client* GetClient(long long birthNo); //return nullptr if birthNo not find, cant call methods of Client on such returned value
	Account* GetAccount(int accNumber); //return nullptr if accNUmber not find, cant call methods of Account on such returned value

	Client* CreateClient(std::string name, long long int birthNo);
	Account* CreateAccount(int accNumber, Client* owner);
	Account* CreateAccount(int accNumber, Client* owner, Client* partner);
	Account* CreateAccount(int accNumber, Client* owner, double accInterestRate);
	Account* CreateAccount(int accNumber, Client* owner, Client* partner, double accInterestRate);

	void AddInterest();

};



