#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>

#include "Document.h"

int main() {
	//create Document, empty
	Document dc1;
	Document dc2("Document1");
	Document dc3("Document2", "Juraj Musil");

	dc1.setAuthor("Juraj Musil");
	dc1.write("Loooooong text");

	dc2.append("First line\n");
	dc2.append("Second line\n");
	dc2.append("Third line\n");
	dc2.append("And so on ....");

	dc1.show();
	dc2.showFull();

	return 0;
}