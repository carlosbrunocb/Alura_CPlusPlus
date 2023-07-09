#pragma once

#include<string>
#include"Titular.hpp"

class Conta {

private:
	std::string m_numero;
	Titular		m_Titular;

	static int	m_numeroDeContas;

protected:
	float		m_saldo = 0;

public:
	Conta(std::string numero, Titular titular);
	virtual ~Conta();

	
	void sacar(float valorASacar);
	void depositar(float valorADepositar);

	std::string recuperaNumero();
	float recuperaSaldo() const;
	static int recuperaNumeroDeContas();

	virtual float taxaDeSaque() const = 0;

};