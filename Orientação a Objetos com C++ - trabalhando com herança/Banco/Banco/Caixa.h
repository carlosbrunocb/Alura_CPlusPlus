#pragma once
#include"Funcionario.hpp"

class Caixa final : public Funcionario {

public:
	Caixa(std::string nome, Cpf cpf, float salario);

	float bonificacao() const override;
};

