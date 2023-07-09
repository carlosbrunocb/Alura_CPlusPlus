#pragma once
#include <string>

class Autenticador {
private:
	std::string m_senha;

public:
	Autenticador(std::string senha);

	bool autentica(std::string senha) const;
};

