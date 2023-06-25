#pragma once
#include <string>

class Cpf {
private:
	std::string n_cpf;

	void verificaCpf();

public:
	explicit Cpf(std::string n_cpf);

	std::string recuperaNumeroDoCpf();

};

