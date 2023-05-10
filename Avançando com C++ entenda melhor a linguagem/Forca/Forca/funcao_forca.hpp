#pragma once

#include<string>
#include<vector>
#include <array>
#include<map>
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>

//extern string palavra_secreta;
//extern map<char, bool> chutou;

namespace Forca {

    bool letra_exite(char chute, std::string palavra_secreta);

    //void chuta(char* chute, std::string palavra_secreta, std::vector<char>* chutes_errados,
    //    std::map<char, bool>* chutou);
    void chuta(char* chute, std::string palavra_secreta, std::array<char, 7>* chutes_errados, 
        int* numero_chutes_errados, std::map<char, bool>* chutou);
    
    namespace Status {
        //bool nao_enforcou(std::vector<char>& chutes_errados);
        bool nao_enforcou(int& numero_chutes_errados);
        bool nao_acertou(const std::string& palavra_secreta, const std::map<char, bool>& chutou);
        //void exibe_chute(const char& chute, const std::vector<char>& chutes_errados,
        //    const std::string& palavra_secreta, const std::map<char, bool>& chutou);
        void exibe_chute(const char& chute, std::array<char, 7>& chutes_errados, const int& numero_chutes_errados,
            const std::string& palavra_secreta, const std::map<char, bool>& chutou);
    }

    namespace StartGame {
        std::vector<std::string> carrega_palavras();
        std::string sorteia_palavra(const std::vector<std::string>& palavras);
    }

}

void adiciona_palavra();
void salva_arquivo(std::vector<std::string>& nova_lista);

inline void exibe_cabecalho() {
    std::cout << "*********************" << std::endl;
    std::cout << "*** Jogo da Forca ***" << std::endl;
    std::cout << "*********************" << std::endl;
    std::cout << std::endl;
}