#include "funcao_forca.hpp"

namespace Forca {

    bool letra_exite(char chute, std::string palavra_secreta) {

        for (char letra : palavra_secreta) {
            if (letra == chute) {
                return true;
            }
        }
        return false;
    }

    namespace Status {

        bool nao_acertou(const std::string& palavra_secreta, const std::map<char, bool>& chutou) {
            for (auto letra : palavra_secreta) {
                if (chutou.find(letra) == chutou.end() || !chutou.at(letra)) {
                    return true;
                }
            }
            return false;
        }

        //void exibe_chute(const char& chute, const std::vector<char>& chutes_errados,
        //    const std::string& palavra_secreta, const std::map<char, bool>& chutou) {
        void exibe_chute(const char& chute, std::array<char, 7>& chutes_errados, const int& numero_chutes_errados,
            const std::string& palavra_secreta, const std::map<char, bool>& chutou) {

            std::cout << ":^( chutes errados: ";
            for (uint16_t i = 0; i < numero_chutes_errados; i++) {
                std::cout << chutes_errados[i] << " ";
            }
 
            //for (char letra : chutes_errados) {
            //    std::cout << letra << " ";
            //}
            
            std::cout << std::endl;

            for (auto letra : palavra_secreta) {
                // cout << "letra: "<< letra << " :: " << chutou[letra] << endl;
                if (chutou.find(letra) != chutou.end()) {
                    std::cout << letra << " ";
                }
                else {
                    std::cout << "_ ";
                }
            }
        }
    }

    namespace StartGame {

        std::vector<std::string> carrega_palavras() {

            std::vector<std::string> palavras;
            std::ifstream arquivo;
            int quatindade_de_palavras;

            arquivo.open("palavras.txt");

            if (arquivo.is_open()) {
                arquivo >> quatindade_de_palavras;

                for (uint16_t i = 0; i < quatindade_de_palavras; i++) {
                    std::string palavra_lida;
                    arquivo >> palavra_lida;
                    palavras.push_back(palavra_lida);
                }

                arquivo.close();
            }
            else {
                std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
                std::cout << "O programa nao pode ser executado!" << std::endl;

                exit(0);
            }

            return  palavras;
        }
    }
}

//namespace definition namespace definition using names resolution operator ::
//bool Forca::Status::nao_enforcou(std::vector<char>& chutes_errados) {
bool Forca::Status::nao_enforcou(int& numero_chutes_errados) {

    using namespace std;

    switch (numero_chutes_errados) {
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
    return numero_chutes_errados < 7;
}

//void Forca::chuta(char* chute, std::string palavra_secreta, std::vector<char>* chutes_errados, 
//           std::map<char, bool>* chutou) {
void Forca::chuta(char* chute, std::string palavra_secreta, std::array<char, 7>* chutes_errados, 
    int* numero_chutes_errados, std::map<char, bool>* chutou) {

    std::cout << "  ?? SEU CHUTE: ";
    std::cin >> *chute;

    (*chutou)[*chute] = true;

    if (letra_exite(*chute, palavra_secreta)) {
        std::cout << "\nVoce acertou! Seu chute esta na palavra." << std::endl;

    }
    else {
        (*chutes_errados)[*numero_chutes_errados] = (*chute);
        (*numero_chutes_errados)++;
        std::cout << "\nVoce errou! Seu chute nao esta na palavra." << std::endl;
    }
}

std::string Forca::StartGame::sorteia_palavra(const std::vector<std::string>& palavras) {
    srand(time(NULL));
    int indice_sorteado = rand() % (palavras.size());
    return palavras[indice_sorteado];
}

void salva_arquivo(std::vector<std::string>& nova_lista) {

    std::ofstream arquivo;

    arquivo.open("palavras.txt");

    if(arquivo.is_open()) {
        arquivo << nova_lista.size() << std::endl;

        for (std::string palavra : nova_lista) {
            arquivo << palavra << std::endl;
        }
        arquivo.close();
    } else {
        std::cout << "Nao foi possivel acessar o banco de palavras." << std::endl;
        std::cout << "A palavra nao pode ser adicionada!" << std::endl;
        exit(0);
    }
}

void adiciona_palavra() {

    using namespace std;
    using namespace Forca::StartGame;

    string nova_palavra;
    vector<string> lista_de_palavras = carrega_palavras();

    cout << "Digite a nova palavra em letras MAIUSCULAS: ";
    cin >> nova_palavra;

    lista_de_palavras.push_back(nova_palavra);

    salva_arquivo(lista_de_palavras);
}