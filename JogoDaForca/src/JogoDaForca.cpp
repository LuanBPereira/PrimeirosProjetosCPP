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
* BOA PRATICA CRIA��O ARQUIVO!
* Sempre que criar um arquivo .cpp, crie tamb�m um .hpp (ou .h)
* para colocar as declara��es, como fun��es e classes.
* No arquivo .cpp, inclua o .hpp correspondente.
*
* Exemplo:
* - Se voc� tem classeA.cpp e classeA.hpp,
*   fa�a o include de classeA.hpp dentro de classeA.cpp.
*
* Isso garante que o arquivo .cpp conhe�a as declara��es feitas no .hpp
* e ajuda a manter o c�digo organizado e evita erros.
* 
* Legal comentar que, se o .cpp incluir a biblioteca de string
* e o .hpp tamb�m a incluir, o .cpp n�o precisa incluir a
* biblioteca de string novamente, pois o .hpp j� a inclui.
* Assim, o .cpp vai acesso �s funcionalidades da biblioteca.
* 
*/

/*
* VARIAVEL EXTERNA!
* para usar uma v�riavel externa, ou seja que foi criada em outro lugar,
* como � o caso do arquivo imprime_erros.cpp, que t� usando a variavel chutou,
* � usado uma palavrinha que � 'extern'. Com isso a gente t� dizendo pro compilador
* compilador, o seguinte, confia em mim que eu sei que essa vari�vel t� definida em
* outro lugar. N�o precisa definir ela ou dar erro, porque eu sei que ela foi criada em outro lugar.
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
		cout << "Voc� perdeu! Tente novamente!" << endl;
	}
	else {
		cout << "Parab�ns! Voc� acertou a palavra secreta!" << endl;

		cout << "Voc� deseja adicionar uma palavra nova ao banco? (S/N)";
		char resposta;
		cin >> resposta;
		if (resposta == 'S' || resposta == 's') {
			adiciona_palavra();
		}
	}
	cin.get();
}