#include "Cpf.hpp"
#include <iostream>


Cpf::Cpf(std::string n_cpf) : n_cpf(n_cpf){

	//"243.456.780-10"
	verificaCpf();

}

std::string Cpf::recuperaNumeroDoCpf() {
	return n_cpf;
}

void Cpf::verificaCpf() {

	bool tam_cpf = false, simbolos_cpf = false, digito_cpf = false;

	tam_cpf = n_cpf.size() == 14;
	simbolos_cpf = (n_cpf[3] == '.') && (n_cpf[7] == '.') && (n_cpf[11] == '-');

	for (int i = 0; i < n_cpf.size(); i++) {

		if (i == 3 || i == 7 || i == 11) {
			continue;
		}

		switch (n_cpf[i]) {
		case '0':
			digito_cpf = true;
			break;
		case '1':
			digito_cpf = true;
			break;
		case '2':
			digito_cpf = true;
			break;
		case '3':
			digito_cpf = true;
			break;
		case '4':
			digito_cpf = true;
			break;
		case '5':
			digito_cpf = true;
			break;
		case '6':
			digito_cpf = true;
			break;
		case '7':
			digito_cpf = true;
			break;
		case '8':
			digito_cpf = true;
			break;
		case '9':
			digito_cpf = true;
			break;
		default:
			digito_cpf = false;
			break;
		}

		if (!digito_cpf) {
			break;
		}
	}

	if (!(tam_cpf && simbolos_cpf && digito_cpf)) {
 		std::cout << "CPF Invalido" << std::endl;
		exit(1);
	}
}


