#pragma once
#include"Funcionario.hpp"
#include"Autenticador.h"
#include<string>

class Gerente final : public Funcionario, public Autenticador {

public:
	Gerente(std::string nome, Cpf cpf, float salario, std::string senha);

	float bonificacao() const override;
};

