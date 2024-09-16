#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese_Brazil");

    cout << "*************************************";
    cout << "* Bem-vindo ao jogo da adivinha��o! *";
    cout << "**************************************";

    cout << "Escolha o seu n�vel de dificuldade: " << endl;
    cout << "F�cil (F), Medio (M) ou Dif�cil (D)" << endl;
    
    char dificuldade;
    cin >> dificuldade;

    int numeroDeTentativas;

    if (dificuldade == 'F' || dificuldade == 'f') {
        numeroDeTentativas = 15;
    }
    else if (dificuldade == 'M' || dificuldade == 'm') {
        numeroDeTentativas = 10;
    } 
    else {
        numeroDeTentativas = 5;
    }

    srand(time(NULL)); // seed para gerar os n�meros aleat�rios
    const int NUMERO_SECRETO = rand() % 100; // usado o '% 100' para manter sempre os n�meros de 0 - 100

    bool naoAcertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numeroDeTentativas; tentativas++) {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontosPerdidos = abs((chute - NUMERO_SECRETO) / 2.0);
        pontos = pontos - pontosPerdidos;

        cout << "O valor do seu chute �: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "Parab�ns! Voc� acertou o n�mero secreto!" << endl;
            naoAcertou = false;
            break;
        }
        else if (maior) {
            cout << "Seu chute foi maior que o n�mero secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que n�mero secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if (naoAcertou) {
        cout << "Voc� perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Voc� acertou o n�mero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2); // usado para mostrar 2 numeros das casas decimais
        cout << fixed; // settar os decimais para os 'pontos'
        cout << "Sua pontua��o foi de: " << pontos << " pontos." << endl;
    }

    return 0;
}
