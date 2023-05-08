#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<ctime>
#include<random>

using namespace std;

// const string PALAVRA_SECRETA = "MELANCIA";
string palavra_secreta;
map<char, bool> chutou;

bool letra_exite(char);
void exibe_chute(char, vector<char>);
bool nao_enforcou(vector<char>);
bool nao_acertou ();
void exibe_cabecalho();
vector<string> carrega_palavras();
void sorteia_palavra(vector<string>);
void adiciona_palavra();
void salva_arquivo(vector<string>);

int main () {
    
    char chute;
    vector<char> chutes_errados;
    vector<string> palavras_secretas;

    exibe_cabecalho();
    palavras_secretas = carrega_palavras();
    sorteia_palavra(palavras_secretas);

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

void exibe_cabecalho() {
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl;
    cout << endl; 
}

bool nao_acertou () {
    for (auto letra : palavra_secreta) {
        if(!chutou[letra]) {
            return true;
        }
    }
    return false;
}

bool nao_enforcou(vector<char> chutes_errados) {

    switch (chutes_errados.size()) {
        case 1:
            cout << "       (x_x)" << endl;
            break;
        case 2:
            cout << "       (x_x)    " << endl;
            cout << "     +==| |==+  " << endl;
            break;
        case 3:
            cout << "       (x_x)    " << endl;
            cout << "     +==| |==+  " << endl;
            cout << "        |_|     " << endl;
            break;
        case 4:
            cout << "       (x_x)    " << endl;
            cout << "     +==| |==+  " << endl;
            cout << "        |_|     " << endl;
            cout << "        \/ \\     " << endl;
            break;
        case 5:
            cout << "       (x_x)    " << endl;
            cout << "     +==| |==+  " << endl;
            cout << "        |_|     " << endl;
            cout << "        \/ \\     " << endl;
            cout << "      _<   >_    " << endl;
            break;
        case 6:
            cout << "  ___         ___" << endl;
            cout << "  \\  \\_(x_x)_\/  \/" << endl;
            cout << "   \\ +==| |==+ \/ " << endl;
            cout << "    ^^^^|_|^^^^  " << endl;
            cout << "        \/ \\      " << endl;
            cout << "      _<   >_    " << endl;
            break;
        case 7:
            cout << endl;
            cout << ":^\/  GAMER OVER  :^(" << endl;
            cout << "  ___   ===   ___" << endl;
            cout << "  \\  \\_(x_x)_\/  \/" << endl;
            cout << "   \\ +==| |==+ \/ " << endl;
            cout << "    ^^^^|_|^^^^  " << endl;
            cout << "        \/ \\      " << endl;
            cout << "      _<   >_    " << endl;
            cout << "Enfocardo := Morto X^(" << endl;
            break;
        default:
            break;
    }
    return chutes_errados.size() < 7;
}

bool letra_exite(char chute) {

    for(char letra : palavra_secreta) {
        if (letra == chute) {
            return true;
        }
    }
    return false;
}

void exibe_chute(char chute, vector<char> chutes_errados) {

    cout << ":^( chutes errados: ";
    for(char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;

    for (auto letra : palavra_secreta) {
        // cout << "letra: "<< letra << " :: " << chutou[letra] << endl;
        if(chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
}

vector<string> carrega_palavras() {

    vector<string> palavras;
    ifstream arquivo;
    int quatindade_de_palavras;

    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {
        arquivo >> quatindade_de_palavras;

        for (uint16_t i = 0; i < quatindade_de_palavras; i++) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras.push_back(palavra_lida);
        }

        arquivo.close();
    } else {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        cout << "O programa nao pode ser executado!" << endl;

        exit(0);
    }

    return  palavras;
}

void sorteia_palavra(vector<string> palavras) {
    srand(time(NULL));
    int indice_sorteado = rand() % (palavras.size());
    palavra_secreta = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {

    ofstream arquivo;

    arquivo.open("palavras.txt");

    if(arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista) {
            arquivo << palavra << endl;
        }
        arquivo.close();
    } else {
        cout << "Nao foi possivel acessar o banco de palavras." << endl;
        cout << "A palavra nao pode ser adicionada!" << endl;
        exit(0);
    }
}

void adiciona_palavra() {

    string nova_palavra;
    vector<string> lista_de_palavras = carrega_palavras();

    cout << "Digite a nova palavra em letras MAIUSCULAS: ";
    cin >> nova_palavra;

    lista_de_palavras.push_back(nova_palavra);

    salva_arquivo(lista_de_palavras);
}