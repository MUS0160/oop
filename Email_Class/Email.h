#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Email {
public:
	//PUBLIC METHODS
	//CONSTR/DESTR
	Email();
	Email(const std::string &sender);
	Email(const std::string &sender, const std::string& recipient); 
	Email(const std::string &sender, const std::string& recipient, const std::string &text);
	~Email();
	
	//GETTERS
	void show();
	
	//SETTERS
	void editSender();
	void editSender(const std::string& sender);
	void editRecipient();
	void editRecipient(const std::string& recipinet);
	void editText();
	void editText(const std::string &text);
	
	//OTHERS
	void send(); //if empty recipient call for one, 

private:
	//DATA MEMBERS
	std::string sender;
	std::string recipient;
	std::string created; //exact time of email creation
	std::string changed;
	std::string sent;
	std::string text = "Empty email"; //text of email proper
	
	//PRIVATE METHODS
	std::string setTime();

};