#include "Email.h"

//CONSTR/DESTR
Email::Email() {
	this->created = setTime();
};

Email::Email(const std::string& sender) : Email() {
	this->sender = sender;
};

Email::Email(const std::string& sender, const std::string& recipient) : Email() {
	this->sender = sender;
	this->recipient = recipient;
};

Email::Email(const std::string& sender, const std::string& recipient, const std::string text) :Email() {
	this->sender = sender;
	this->recipient = recipient;
	this->text = text;
};

Email::~Email() {};

//GETTERS
void Email::show() {
	std::cout << "-----------------------------------------------------------------------------";
	std::cout << std::endl << "| Email from: " << this->sender << " | Email to: " << this->recipient << " |" << std::endl;
	std::cout << "Created: " << this->created << "Changed: " << this->changed << "Sent: " << this->sent << std::endl;
	std::cout << this->text << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
};

//SETERS
void Email::editSender() {
	std::cout << "Provide the name of the sender: ";
	std::getline(std::cin, this->sender);
	this->changed = setTime();
};

void Email::editSender(const std::string& sender) {
	this->sender = sender;
	this->changed = setTime();
};

void Email::editRecipient() {
	std::cout << "Provide the name of the recipient: ";
	std::getline(std::cin, this->recipient);
	this->changed = setTime();
};

void Email::editRecipient(const std::string& recipient) {
	this->recipient = recipient;
	this->changed = setTime();
};

void Email::editText() {
	std::cout << "Provide the new body of email: ";
	std::getline(std::cin, this->text);
	this->changed = setTime();
}

void Email::editText(const std::string& text) {
	this->text = text;
	this->changed = setTime();
}

//OTHERS
void Email::send(){
	if (this->recipient.empty()){
		editRecipient();
	};
	this->sent = setTime();
	std::cout << "\nFollowing email was sent:" << std::endl;
	show();
};

//PRIVATE METHODS

std::string Email::setTime() {
	time_t now = time(0);
	#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
	std::string actualTime = ctime(&now);
	return actualTime;
};

