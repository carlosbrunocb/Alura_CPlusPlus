#pragma once
#include <string>
#include "Titular.hpp"
#include "Conta.hpp"

class Poupanca : public Conta {
private:

public:
	Poupanca(std::string numero, Titular titular);
	~Poupanca();

	void sacar(float valorASacar);
	float taxaDeSaque() const override;
};

