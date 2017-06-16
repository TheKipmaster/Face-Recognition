#include "Usuario.hpp"

Usuario::Usuario(){}

Usuario::Usuario(std::string Id, std::string Nome, std::string Sobrenome,
								 std::string Nome_do_meio, std::string Tipo_de_usuario):
id(Id), nome(Nome), sobrenome(Sobrenome), nome_do_meio(Nome_do_meio),
tipo_de_usuario(Tipo_de_usuario) {}

Usuario::~Usuario() {}

std::string Usuario::getId() {
	return id;
}

void Usuario::setNome(std::string Nome) {
	nome = Nome;
}

std::string Usuario::getNome() {
	return nome;
}

std::string Usuario::getSobrenome() {
	return sobrenome;
}

std::string Usuario::getNomeDoMeio() {
	return nome_do_meio;
}

std::string Usuario::getTipoDeUsuario() {
	return tipo_de_usuario;
}

void Usuario::cadastrar() {
	std::string input;

	system("clear");

	std::cout << "Informe o tipo do usuário: ";
	std::cin >> tipo_de_usuario;

	std::cout << "Informe o nome do " << tipo_de_usuario << ": ";
	std::cin >> nome;

	std::cout << "Informe o sobrenome do " << tipo_de_usuario << ": ";
	std::cin >> sobrenome;

	std::cout << "Informe o nome do meio do " << tipo_de_usuario << ": ";
	std::cin >> nome_do_meio;

	std::cout << "Informe o id do " << tipo_de_usuario << ": ";
	std::cin >> id;
}
