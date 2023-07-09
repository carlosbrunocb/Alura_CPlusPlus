#pragma once
#include<string>
#include"Cpf.hpp"
#include"Pessoa.hpp"
#include"Autenticador.h"

class Titular : public Pessoa, public Autenticador {

private:
	//std::string nome;
	//Cpf cpf;


public:
	Titular(std::string nome, Cpf cpf, std::string senha);

	//void renomear(std::string nome);

	//Cpf recuperaCpf();
	//std::string recuperaNome();
};

