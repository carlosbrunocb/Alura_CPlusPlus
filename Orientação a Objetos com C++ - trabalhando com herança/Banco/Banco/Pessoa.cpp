#include "Pessoa.hpp"
#include <iostream>

Pessoa::Pessoa(const std::string& nome, const Cpf& cpf)
	: m_nome(nome), m_cpf(cpf) {
}

void Pessoa::verificaTamanhoDoNome() {
	if (m_nome.size() < 5) {
		std::cout << "Nome curto" << std::endl;
		exit(1);
	}
}

Cpf Pessoa::informaCpf() {
	return m_cpf;
}
