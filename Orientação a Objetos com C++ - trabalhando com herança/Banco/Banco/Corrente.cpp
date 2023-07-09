#include "Corrente.hpp"
#include<iostream>

Corrente::Corrente(std::string numero, Titular titular) : Conta(numero, titular){
}

Corrente::~Corrente() {
	std::cout << "destrutor da Conta Corrente" << std::endl;
}

float Corrente::taxaDeSaque() const {
	std::cout << "Sacando da Conta Corrente" << std::endl;
	return 0.05;
}

void Corrente::transferePara(Conta& contaDestino, float valor) {
	sacar(valor);
	contaDestino.depositar(valor);
}
