#pragma once
#include<string>
#include "Cpf.hpp"

class Titular {

private:
	std::string nome;
	Cpf cpf;

	void verificaTamanhoDoNome();

public:
	Titular(std::string nome, Cpf cpf);

	void renomear(std::string nome);

	Cpf recuperaCpf();
	std::string recuperaNome();
};

