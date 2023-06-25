#include "Titular.hpp"
#include<iostream>

Titular::Titular(std::string nome, Cpf cpf) :
nome(nome), cpf(cpf) {
	verificaTamanhoDoNome();
}

void Titular::renomear(std::string nome) {
	this->nome = nome;
}

std::string Titular::recuperaNome() {
	return this->nome;
}

Cpf Titular::recuperaCpf() {
	return this->cpf;
}

void Titular::verificaTamanhoDoNome() {
	if (nome.size() < 5) {
		std::cout << "Nome curto" << std::endl;
		exit(1);
	}
}