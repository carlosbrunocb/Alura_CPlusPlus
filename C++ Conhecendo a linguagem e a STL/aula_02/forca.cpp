#include "funcao_forca.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;

int main () {
    
    char chute;
    vector<char> chutes_errados;
    vector<string> palavras;

    exibe_cabecalho();
    palavras = carrega_palavras();
    sorteia_palavra(palavras);

    while (nao_acertou() && nao_enforcou(chutes_errados)) {

        exibe_chute(chute, chutes_errados);
        cout<< "  ?? SEU CHUTE: ";
        cin >> chute;
        
        chutou[chute] = true;

        if (letra_exite(chute)) {
            cout << "\nVoce acertou! Seu chute esta na palavra." << endl;
        
        }
        else {
            chutes_errados.push_back(chute);
            cout << "\nVoce errou! Seu chute nao esta na palavra." << endl;
        }
    }

    cout << "\nFim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (nao_acertou ()) {
        cout << "TENTE NOVAMENTE!" << endl;
    } else {
        cout << "PARABENS! VOCE DESCOBRIU A PALAVRA SECRETA!\n" << endl;
        cout << "Voce deseja adicionar uma nova palavra ao banco? [S/N]: ";

        char resposta;
        cin >> resposta;

        if (resposta == 'S') {
            adiciona_palavra();
        }

    }
    return 0;
}