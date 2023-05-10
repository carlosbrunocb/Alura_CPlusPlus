#include "funcao_forca.hpp"

using namespace std;

static string palavra_secreta;
static map<char, bool> chutou;

int main () {
    
    namespace status = Forca::Status;

    char chute = NULL;
    //vector<char> chutes_errados;
    array<char,7> chutes_errados;
    int numero_chutes_errados = 0;
    vector<string> palavras;

    exibe_cabecalho();
    palavras = Forca::StartGame::carrega_palavras();
    palavra_secreta = Forca::StartGame::sorteia_palavra(palavras);

    while (status::nao_acertou(palavra_secreta, chutou) && status::nao_enforcou(numero_chutes_errados)) {

        status::exibe_chute(chute, chutes_errados, numero_chutes_errados, palavra_secreta, chutou);
        Forca::chuta(&chute, palavra_secreta, &chutes_errados, &numero_chutes_errados, &chutou);
    }

    cout << "\nFim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (status::nao_acertou(palavra_secreta, chutou)) {
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