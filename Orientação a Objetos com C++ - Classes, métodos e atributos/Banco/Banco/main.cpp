#include<iostream>
#include<string>
#include"Conta.hpp"
#include"Titular.hpp"  
using namespace std;

//struct Conta {
//	string numero;
//	string cpfTitular;
//	string nomeTitular;
//	float saldo;	
//};


void ExibeSaldo(const Conta& conta) {
	Titular titular_03("Vincius", Cpf("123.456.789-10"));
	Titular titular_04("Vincius 01", Cpf("123.456.009-10"));

	Conta umaContaDesn_00("123457", titular_03);
	Conta umaContaDesn_01("123458", titular_04);

	cout << "O saldo da conta eh: " << conta.recuperaSaldo() << endl;
}

int main() {

	// Conversão implicita de objetos
	//Cpf mCpf = string("123.456.798-10");
	//Titular titular_01("Vinicius", string("123.456.798-10"));
	Titular titular_01("Vinicius", Cpf("123.456.798-10"));
	Titular titular_02("Thiago", Cpf("243.456.708-10"));

	Conta umaConta("123456", titular_01);

	umaConta.depositar(100);

	ExibeSaldo(umaConta);
		
	Conta umaOutraConta = Conta("123457", titular_02, 200);

	umaOutraConta.depositar(500);
	umaOutraConta.sacar(200);

	cout << "umaConta.saldo: " << umaConta.recuperaSaldo() << 
		    "\numaOutraConta.saldo: " << umaOutraConta.recuperaSaldo() << endl;

	cout << "Numero de Contas[umaConta]: " << Conta::recuperaNumeroDeContas() <<
		"\nNumero de Contas[umaOutraConta]: " << Conta::recuperaNumeroDeContas() << endl;

	//Titular titular_03("Paulinho", Cpf("123.406.009-04"));
	Titular titular_04("Paulo", Cpf("123.506.009-04"));
	Titular titular_05("Paulo", Cpf("12..206.009-04"));

	//Conta umaContaDesn_02("123458", titular_03);
}