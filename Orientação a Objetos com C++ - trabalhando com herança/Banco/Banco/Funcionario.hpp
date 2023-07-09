#pragma once
#include <string>
#include "Cpf.hpp"
#include "Pessoa.hpp"

class Funcionario : public Pessoa{
private:
	float m_salario = 0;

public:
	Funcionario(std::string nome, Cpf cpf, float salario);

	std::string recuperaNome() const;
	float recuperaSalario() const;

	virtual float bonificacao() const = 0;

};

