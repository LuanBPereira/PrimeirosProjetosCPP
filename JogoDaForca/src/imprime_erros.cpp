#include <vector>
#include <iostream>
#include "imprime_erros.hpp"

extern std::vector<char> chutes_errados;

void imprime_erros() {
	std::cout << "Chutes errados: ";
	for (char letra : chutes_errados) {
		std::cout << letra << " ";
	}
	std::cout << std::endl;
}