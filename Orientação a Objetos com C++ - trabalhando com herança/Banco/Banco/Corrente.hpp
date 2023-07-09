#pragma once
#include "Conta.hpp"
#include<string>

class Corrente final : public Conta {

public:
	Corrente(std::string numero, Titular titular);
	~Corrente();

	float taxaDeSaque() const override;
	void transferePara(Conta& contaDestino, float valor);

};

