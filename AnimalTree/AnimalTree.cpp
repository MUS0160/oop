#pragma once
#include "AnimalTree.h"

AnimalTree::AnimalTree(std::string key, std::string value) {
	this->key = key;
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

AnimalTree::~AnimalTree() {
	if (this->left != nullptr) {
		delete this->left;
	}
	if (this->right != nullptr) {
		delete this->right;
	}
	this->left = nullptr;
	this->right = nullptr;
};

std::string AnimalTree::getKey() {
	return this->key;
};

std::string AnimalTree::getValue() {
	return this->value;
};

AnimalTree* AnimalTree::getLeft() {
	return this->left;
};

AnimalTree* AnimalTree::getRight() {
	return this->right;
};

AnimalTree* AnimalTree::createLeft(std::string key, std::string value) {
	this->left = new AnimalTree(key, value);
	return this->left;
};

AnimalTree* AnimalTree::createRight(std::string key, std::string value) {
	this->right = new AnimalTree(key, value);
	return this->right;
};