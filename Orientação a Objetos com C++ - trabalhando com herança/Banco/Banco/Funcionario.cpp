#include "Funcionario.hpp"

Funcionario::Funcionario(std::string nome, Cpf cpf, float salario) :
	Pessoa(nome, cpf), m_salario(salario) {
}

std::string Funcionario::recuperaNome() const {
	return m_nome;
}

float Funcionario::recuperaSalario() const {
	return m_salario;
}
