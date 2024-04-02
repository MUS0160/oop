#include <iostream>
#include "Faktura.h"

int main() {
	Faktura fa1 = Faktura(20240301, "Juraj Musil", 7810317713, "Tatranska 24, Banska Bystrica", 20);
	fa1.setPolozka("pivo", 1.5);
	fa1.setPolozka("pivo", 1.5);
	fa1.setPolozka("pivo", 1.5);
	fa1.setPolozka("pivo", 1.5);

	std::cout << fa1.getCelkovaCena() << std::endl;

	return 0;
}