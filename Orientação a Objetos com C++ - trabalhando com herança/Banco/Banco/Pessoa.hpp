#pragma once
#include <string>
#include "Cpf.hpp"

class Pessoa {
protected:
	std::string m_nome;
	Cpf			m_cpf;

private:
	void verificaTamanhoDoNome();

public:
	Pessoa(const std::string& nome, const Cpf& cpf);

	Cpf informaCpf();

};

