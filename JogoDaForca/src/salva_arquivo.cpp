#include <fstream>
#include <iostream>
#include "salva_arquivo.hpp"

void salva_arquivo(std::vector<std::string> nova_lista) {
	std::ofstream arquivo; // output file stream -> coloca valores em um arquivo
	arquivo.open("palavras.txt");

	if (arquivo.is_open()) {
		arquivo << nova_lista.size() << std::endl;

		for (std::string palavra : nova_lista) {
			arquivo << palavra << std::endl;
		}
		arquivo.close();
	}
	else {
		std::cout << "Não foi possível acessar o banco de palavras." << std:: endl;
		exit(0);
	}
}