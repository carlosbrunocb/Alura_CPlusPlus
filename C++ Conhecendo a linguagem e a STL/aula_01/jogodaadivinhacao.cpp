#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int main () {

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int chute, 
        tentativas = 0,
        numero_de_tentativas;
    bool acertou, 
         maior, 
         nao_acertou;
    double pontos = 1000.0;
    double pontos_perdidos;
    char dificuldade;

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo da adivinhacao! *" << endl;
    cout << "**************************************" << endl;
    cout << "\nEscolha o nivel de dificuldade: " << endl;
    cout << "\nFacil (F), Medio (M) ou Dificil (D) " << endl;

    cin >> dificuldade;

    switch (dificuldade) {
        case 'F':
            numero_de_tentativas = 15;
            break;
        case 'M':
            numero_de_tentativas = 10;
            break;
        case 'D':
            numero_de_tentativas = 5;
            break;
        
        default:
            numero_de_tentativas = 15;
            break;
    }

    nao_acertou = true;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {

        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute?" << endl;
        cin >> chute;   

        acertou = chute == NUMERO_SECRETO;
        maior = chute > NUMERO_SECRETO;

        pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        if (acertou) {
            cout << "\n\n" << endl;
            cout << "\\o\/ Parabens! Voce acertou o numero secreto! \\o\/" << endl;
            cout << "\t++ " << NUMERO_SECRETO << " ++" << endl;
            nao_acertou = false;
            break;
        } else if (maior) {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
            cout << "\t-- " << chute << " --" << endl;
        } else {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
            cout << "\t-- " << chute << " --\n" << endl;
        }
    }

    cout << "\n############ Fim de jogo ############" << endl;

    if (nao_acertou) {
        cout << "Voce perdeu! Tente novamente! \n" << tentativas - 1 << " chutes\n" << endl;
        cout << "O numero secreto era " << NUMERO_SECRETO 
             << ". Nao conte para ninguem!\n\n" << endl;
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " chutes" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos.\n\n" << endl;
    }

    return 0;
}