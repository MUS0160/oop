#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

#include "Email.h"

int main(){
	//create email1, empty
	Email em1;
	Email em2("Juraj Musil", "FEI-VSB", "Actual text of the email in em4.");
	
	em1.show();
	em2.show();
	

	em1.editSender("Juraj Musil");
	em1.editText("Loooooooong teeeexxxxt");
	
	em1.show();

	em1.send();


	return 0;
}