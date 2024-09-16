#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese_Brazil");

    cout << "*************************************";
    cout << "* Bem-vindo ao jogo da adivinhação! *";
    cout << "**************************************";

    cout << "Escolha o seu nível de dificuldade: " << endl;
    cout << "Fácil (F), Medio (M) ou Difícil (D)" << endl;
    
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

    srand(time(NULL)); // seed para gerar os números aleatórios
    const int NUMERO_SECRETO = rand() % 100; // usado o '% 100' para manter sempre os números de 0 - 100

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

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou){
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            naoAcertou = false;
            break;
        }
        else if (maior) {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que número secreto!" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if (naoAcertou) {
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else {
        cout << "Você acertou o número secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2); // usado para mostrar 2 numeros das casas decimais
        cout << fixed; // settar os decimais para os 'pontos'
        cout << "Sua pontuação foi de: " << pontos << " pontos." << endl;
    }

    return 0;
}
