#include<iostream>
#include<string>
#include"Conta.hpp"
#include"Titular.hpp"  
#include"Funcionario.hpp"
#include"Poupanca.hpp"
#include"Corrente.hpp"
#include"Autenticador.h"


using namespace std;

void realizarSaque(Conta& conta) {
	conta.sacar(10);
}

void FazLogin(Titular& alguem, string senha) {
	if (alguem.autentica(senha)) {
		cout << "Login realizado com SUCESSO!" << endl;
	}
	else {
		cout << "Senha INVALIDA!" << endl;
	}
}


int main() {

	Titular titular_01("Vinicius", Cpf("123.456.798-10"), "umasenha");
	Titular titular_02("Thiago", Cpf("243.456.708-10"), "outrasenha");

	Poupanca umaConta("123456", titular_01);

	FazLogin(titular_01, "umasenha");
	FazLogin(titular_01, "outrasenha");

	umaConta.depositar(100);
	umaConta.sacar(10);

	realizarSaque(umaConta);

	cout << "umaConta.saldo: " << umaConta.recuperaSaldo() << endl;
	
	Corrente umaOutraConta = Corrente("123457", titular_02);

	umaOutraConta.depositar(800);
	umaOutraConta.sacar(200);
	
	cout << "Numero de Contas[umaConta]: " << Conta::recuperaNumeroDeContas() <<
		"\nNumero de Contas[umaOutraConta]: " << Conta::recuperaNumeroDeContas() << endl;

	umaOutraConta.transferePara(umaConta, 300);

	cout << "[umaOutraConta.transferePara]umaConta.saldo: " << umaConta.recuperaSaldo() << endl;

}