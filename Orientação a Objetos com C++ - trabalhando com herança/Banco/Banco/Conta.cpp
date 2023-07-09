#include<iostream>
#include "Conta.hpp"

// Inicializando o atributo static
	// Atributo global para todo classe
int Conta::m_numeroDeContas = 0;

Conta::Conta(std::string numero, Titular titular) :
	m_numero(numero), m_Titular(titular) {
	m_numeroDeContas++;
}

Conta::~Conta() {
	std::cout << "destrutor da Conta" << std::endl;
	m_numeroDeContas--;
}

void Conta::sacar(float valorASacar) {

	if (valorASacar < 0) {
		std::cout << "Nao pode sacar valor negativo" << std::endl;
		return;
	}

	float taxa = valorASacar * taxaDeSaque();
	float valorDoSaque = valorASacar + taxa;
	
	if (valorASacar > m_saldo) {
		std::cout << "Saldo Insuficiente" << std::endl;
		return;
	}

	m_saldo -= valorDoSaque;
}

void Conta::depositar(float valorADepositar) {

	if (valorADepositar < 0) {
		std::cout << "Nao pode depositar valor negativo" << std::endl;
		return;
	}

	m_saldo += valorADepositar;
}

std::string Conta::recuperaNumero() {
	return this->m_numero;
}

float Conta::recuperaSaldo() const {
	return this->m_saldo;
}

int Conta::recuperaNumeroDeContas() {
	return m_numeroDeContas;
}