#include "Document.h"

//CONSTR/DESTR
Document::Document() {
	this->created = setTime();
	this->modified = setTime();
};

Document::Document(const std::string &title): Document() {
	this->title = title;
};

Document::Document(const std::string &title, const std::string& author): Document(title) {
	this->author = author;
};

//GETTERS
void Document::show() {
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << this->body << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
};

void Document::showFull() {
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "Title: " << this->title << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Created: " << this->created;
	std::cout << "Modified: " << this->modified;
	std::cout << "--------------------------------BODY-----------------------------------------" << std::endl;
	std::cout << this->body << std::endl;
	std::cout << "--------------------------------END-OF-BODY----------------------------------" << std::endl;
};

//SETTERS
void Document::setAuthor(const std::string & author) {
	this->author = author;
};

void Document::write(const std::string &newBody) {
	this->body = newBody;
	this->modified = setTime();
};

void Document::append(const std::string& appendix) {
	this->body.append(appendix);
	this->modified = setTime();
};

void Document::rename(const std::string& newName) {
	this->title = newName;
	this->modified = setTime();
}

//PRIVATE METHODS
std::string Document::setTime() {
	time_t now = time(0);
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
	std::string actualTime = ctime(&now);
	return actualTime;
};