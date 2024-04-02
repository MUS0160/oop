#pragma once
#include <iostream>
#include <string>

class AnimalTree {

private:
	std::string key;
	std::string value;
	AnimalTree *left;
	AnimalTree* right;

public:
	AnimalTree(std::string key, std::string value);
	~AnimalTree();

	std::string getKey();
	std::string getValue();

	AnimalTree* getLeft();
	AnimalTree* getRight();

	AnimalTree* createLeft(std::string key, std::string value);
	AnimalTree* createRight(std::string key, std::string value);
};