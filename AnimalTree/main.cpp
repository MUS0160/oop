#include <iostream>
#include "AnimalTree.h"

void printLeftRigth(AnimalTree*);
void printLeft(AnimalTree*);
void printRight(AnimalTree*);

AnimalTree* createStructure() {

	AnimalTree* at1 = new AnimalTree("Risa? ", "Zviera");
	AnimalTree* at11 = at1->createLeft("Charakter? ", "Skutocne");
	AnimalTree* at12 = at1->createRight("Charakter? ", "Rozpravkove");

	AnimalTree* at111 = at11->createLeft("Co zerie? ", "Bylinozravec");
	AnimalTree* at112 = at11->createRight("Co zerie? ", "Masozravec");
	AnimalTree* at121 = at12->createLeft("Kde zije? ", "V_mori");
	AnimalTree* at122 = at12->createRight("Kde zije? ", "Na_susi");

	AnimalTree* at1111 = at111->createLeft("Druh? ", "Krava");
	AnimalTree* at1112 = at111->createRight("Druh? ", "Koza");
	AnimalTree* at1121 = at112->createLeft("Druh? ", "Medved");
	AnimalTree* at1122 = at112->createRight("Druh? ", "Vlk");

	AnimalTree* at1211 = at121->createLeft("Druh? ", "Kraken");
	AnimalTree* at1212 = at121->createRight("Druh? ", "Morska_Panna");
	AnimalTree* at1221 = at122->createLeft("Druh? ", "Jednorozer");
	AnimalTree* at1222 = at122->createRight("Druh? ", "Drak");

	return at1;
}

void printStructure(AnimalTree *at) {
	printLeftRigth(at);
}

void printLeftRigth(AnimalTree* at) {
	std::cout << (at->getLeft())->getKey() << ": " << (at->getLeft())->getValue() << std::endl;
	if ((at->getLeft())->getLeft() != nullptr) {
		std::cout << "	";
		printLeftRigth(at->getLeft());
	}
	else {
		std::cout << "	";
	}
	std::cout << (at->getRight())->getKey() << ": " << (at->getRight())->getValue() << std::endl;
	if ((at->getRight())->getLeft() != nullptr) {
		std::cout << "	";
		printLeftRigth(at->getRight());
	}
}

void printLeft(AnimalTree* at) {
	std::cout << (at->getLeft())->getKey() << ": " << (at->getLeft())->getValue() << std::endl;
}

void printRight(AnimalTree* at) {
	std::cout << (at->getRight())->getKey() << ": " << (at->getRight())->getValue() << std::endl;
}


int main() {
	AnimalTree* at = createStructure();
	std::cout << at->getKey() << ": " << at->getValue() << std::endl;
	std::cout << "	";
	printStructure(at);
	/*
	std::string answer;
	std::cout << at->getKey();
	std::cin >> answer;
	if (answer == at->getValue()) {
		std::cout << (at->getLeft())->getKey();
		std::cin >> answer;
	}
	while ((answer == (at->getLeft())->getValue()) || (answer == (at->getRight())->getValue())) {
		if (answer == (at->getLeft())->getValue()) {
			at = at->getLeft();
		}
		else if( answer == (at->getRight())->getValue()){
			at = at->getRight();
		}
		if (at->getLeft() == nullptr) {
			break;
		}
		std::cout << (at->getLeft())->getKey();
		std::cin >> answer;		
	}
	
	std::cout << at->getKey() << " Odpoved =  " << at->getValue() << std::endl;
	*/
	return 0;
}