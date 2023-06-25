#include<iostream>
#include "Conta.hpp"

// Inicializando o atributo static
	// Atributo global para todo classe
int Conta::numeroDeContas = 0;

//Conta::Conta() {
//
//}

Conta::Conta(std::string numero, Titular m_Titular, float saldo) :
	numero(numero), m_Titular(m_Titular), saldo(saldo) {
	numeroDeContas++;
}

Conta::Conta(std::string numero, Titular m_Titular) : 
numero(numero), m_Titular(m_Titular) {
	numeroDeContas++;
}


Conta::~Conta() {
	numeroDeContas--;
}

void Conta::sacar(float valorASacar) {

	if (valorASacar < 0) {
		std::cout << "Nao pode sacar valor negativo" << std::endl;
		return;
	}

	if (valorASacar > saldo) {
		std::cout << "Saldo Insuficiente" << std::endl;
		return;
	}

	saldo -= valorASacar;
}

void Conta::depositar(float valorADepositar) {

	if (valorADepositar < 0) {
		std::cout << "Nao pode depositar valor negativo" << std::endl;
		return;
	}

	saldo += valorADepositar;
}

std::string Conta::recuperaNumero() {
	return this->numero;
}

float Conta::recuperaSaldo() const {
	return this->saldo;
}

int Conta::recuperaNumeroDeContas() {
	return numeroDeContas;
}