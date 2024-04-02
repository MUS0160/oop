#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

#include "Person.h"

int main() {
	
	Person me("Juraj Musil", 7810317713);
	std::string name = me.getName();
	std::cout << name << std::endl;
	int age = me.getAge();
	std::cout << age << std::endl;
	std::string date_of_birth = me.getBirthDate();
	std::cout << date_of_birth << std::endl;
	std::cout << me.isMan() << std::endl;
	


	return 0;
}