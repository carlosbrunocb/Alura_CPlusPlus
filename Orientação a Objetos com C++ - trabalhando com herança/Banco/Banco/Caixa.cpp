#include "Caixa.h"
#include<string>

Caixa::Caixa(std::string nome, Cpf cpf, float salario) : 
	Funcionario (nome, cpf, salario) {
}

float Caixa::bonificacao() const {
	return recuperaSalario()*0.1;
}
