#include "Gerente.h"

Gerente::Gerente(std::string nome, Cpf cpf, float salario, std::string senha) :
	Funcionario(nome, cpf, salario), Autenticador(senha) {
}

float Gerente::bonificacao() const{
	return recuperaSalario() * 0.5;
}
