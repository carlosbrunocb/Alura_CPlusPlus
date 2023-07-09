#include "Titular.hpp"
#include<iostream>

Titular::Titular(std::string nome, Cpf cpf, std::string senha) : 
	Pessoa(nome, cpf), Autenticador(senha) {
}

//void Titular::renomear(std::string nome) {
//	this->nome = nome;
//}
//
//std::string Titular::recuperaNome() {
//	return this->nome;
//}
//
//Cpf Titular::recuperaCpf() {
//	return this->cpf;
//}