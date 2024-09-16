#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "le_arquivo.hpp"
#include "sorteia_palavra.hpp"

extern std::string palavra_secreta;

void sorteia_palavra() {
	std::vector<std::string> palavras = le_arquivo();

	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();

	palavra_secreta = palavras[indice_sorteado];
}