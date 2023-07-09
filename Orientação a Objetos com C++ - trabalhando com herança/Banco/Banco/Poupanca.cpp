#include "Poupanca.hpp"
#include <iostream>

Poupanca::Poupanca(std::string numero, Titular titular) : Conta(numero, titular){
}

Poupanca::~Poupanca() {
	std::cout << "destrutor da Conta Poupanca" << std::endl;
}

void Poupanca::sacar(float valorASacar) {

	if (valorASacar < 0) {
		std::cout << "Nao pode sacar valor negativo" << std::endl;
		return;
	}

	float taxa = valorASacar * 0.03;
	float valorDoSaque = valorASacar + taxa;

	if (valorASacar > m_saldo) {
		std::cout << "Saldo Insuficiente" << std::endl;
		return;
	}

	m_saldo -= valorDoSaque;
}

float Poupanca::taxaDeSaque() const {
	std::cout << "Sacando da Conta Poupanca" << std::endl;
	return 0.03;
}
