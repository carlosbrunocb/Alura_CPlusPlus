#include "Autenticador.h"
#include <iostream>

Autenticador::Autenticador(std::string senha) : m_senha(senha) {
}

bool Autenticador::autentica(std::string senha) const {
	//std::cout << "senha: " << senha << std::endl;
	//std::cout << "m_senha: " << m_senha << std::endl;
	return senha == m_senha;
}


