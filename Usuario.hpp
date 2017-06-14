#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <vector>


class Usuario {

public:
	std::string id;
	std::string nome;
	std::string sobrenome;
	std::string nome_do_meio;
	// Vector de fotos;
	std::string tipo_de_usuario;
	Usuario(std::string id, std::string nome, std::string sobrenome, std::string nome_do_meio, std::string tipo_de_usuario);
	~Usuario();
	// Cadastrar usuário
	// Buscat usuário
	// Tem permissão?
	// Novos fotos
	// Edital Cadastro
};

#endif