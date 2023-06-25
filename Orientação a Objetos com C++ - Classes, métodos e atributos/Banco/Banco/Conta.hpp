#pragma once

#include<string>
#include"Titular.hpp"

class Conta {

private:
	std::string numero;
	Titular m_Titular;
	float saldo = 0;

	static int numeroDeContas;

	// # Sufixo m_ indica que o atributo é membro da
	//   da classe
	//std::string m_numero;
	//std::string m_cpfTitular;
	//std::string m_nomeTitular;
	//float		m_saldo = 0;

public:
	//Conta();

	Conta(std::string numero, Titular m_Titular, float saldo);
	Conta(std::string numero, Titular m_Titular);
	~Conta();

	
	void sacar(float valorASacar);
	void depositar(float valorADepositar);

	std::string recuperaNumero();

	float recuperaSaldo() const;
	static int recuperaNumeroDeContas();

};

// * struct: Everything is public by default
//struct Conta {
//
//	void sacar(float valorASacar);
//	void depositar(float valorADepositar);
//
//private:
//	std::string numero;
//	std::string cpfTitular;
//	std::string nomeTitular;
//	float saldo = 0;
//};

// * class: Everything is private by default
//class Conta {
//
//	std::string numero;
//	std::string cpfTitular;
//	std::string nomeTitular;
//	float saldo = 0;
//
//public:
//	void sacar(float valorASacar);
//	void depositar(float valorADepositar);
//};
