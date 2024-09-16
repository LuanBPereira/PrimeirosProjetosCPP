#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <locale.h>
#include "adiciona_palavra.hpp"
#include "chuta.hpp"
#include "imprime_cabecalho.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "le_arquivo.hpp"
#include "letra_existe.hpp"
#include "nao_acertou.hpp"
#include "nao_enforcou.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"

using namespace std;

/*
* BOA PRATICA CRIAÇÃO ARQUIVO!
* Sempre que criar um arquivo .cpp, crie também um .hpp (ou .h)
* para colocar as declarações, como funções e classes.
* No arquivo .cpp, inclua o .hpp correspondente.
*
* Exemplo:
* - Se você tem classeA.cpp e classeA.hpp,
*   faça o include de classeA.hpp dentro de classeA.cpp.
*
* Isso garante que o arquivo .cpp conheça as declarações feitas no .hpp
* e ajuda a manter o código organizado e evita erros.
* 
* Legal comentar que, se o .cpp incluir a biblioteca de string
* e o .hpp também a incluir, o .cpp não precisa incluir a
* biblioteca de string novamente, pois o .hpp já a inclui.
* Assim, o .cpp vai acesso às funcionalidades da biblioteca.
* 
*/

/*
* VARIAVEL EXTERNA!
* para usar uma váriavel externa, ou seja que foi criada em outro lugar,
* como é o caso do arquivo imprime_erros.cpp, que tá usando a variavel chutou,
* é usado uma palavrinha que é 'extern'. Com isso a gente tá dizendo pro compilador
* compilador, o seguinte, confia em mim que eu sei que essa variável tá definida em
* outro lugar. Não precisa definir ela ou dar erro, porque eu sei que ela foi criada em outro lugar.
*/ 

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main() {
	setlocale(LC_ALL, "portuguese_Brazil");

	imprime_cabecalho();

	le_arquivo();
	sorteia_palavra();

	while (nao_acertou() && nao_enforcou()) {
		imprime_erros();

		imprime_palavra();

		chuta();
	}

	cout << "Fim de jogo!" << endl;
	cout << "A palavra secreta era: " << palavra_secreta << "." << endl;
	if (nao_acertou()) {
		cout << "Você perdeu! Tente novamente!" << endl;
	}
	else {
		cout << "Parabéns! Você acertou a palavra secreta!" << endl;

		cout << "Você deseja adicionar uma palavra nova ao banco? (S/N)";
		char resposta;
		cin >> resposta;
		if (resposta == 'S' || resposta == 's') {
			adiciona_palavra();
		}
	}
	cin.get();
}