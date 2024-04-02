#pragma once
#include <iostream>
#include <string>
#include <ctime>

class Document {
public:
	//CONSTR/DESTR
	Document();
	Document(const std::string &title); //author empty, body empty, set created and lastModification
	Document(const std::string &title, const std::string &author); //body empty, set created and lastModification

	//GETTERS
	void show(); //print body
	void showFull(); //print author, dates and body

	//SETTERS
	void setAuthor(const std::string& author); 
	void rename(const std::string& newName);
	void write(const std::string &newBody); //overwrite whole body
	void append(const std::string& appendix); //apend appendinx at the end of the body

private:
	//DATA MEMBERS
	std::string title;
	std::string author;
	std::string created;
	std::string modified;
	std::string body;

	//PRIVATE METHODS
	std::string setTime();
};
