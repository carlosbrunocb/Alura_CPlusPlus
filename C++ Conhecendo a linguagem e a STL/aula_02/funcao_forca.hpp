#pragma once

#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>

using namespace std;

extern string palavra_secreta;
extern map<char, bool> chutou;

bool letra_exite(char);
void exibe_chute(char, vector<char>);
bool nao_enforcou(vector<char>);
bool nao_acertou ();
void exibe_cabecalho();
vector<string> carrega_palavras();
void sorteia_palavra(vector<string>);
void adiciona_palavra();
void salva_arquivo(vector<string>);