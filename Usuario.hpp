#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <vector>
#include <iostream>

class Usuario {

private:
	std::string id;
	std::string nome;
	std::string sobrenome;
	std::string nome_do_meio;
	// Vector de reservas
	// Vector de fotos;
	std::string tipo_de_usuario;

public:
	Usuario();
	Usuario(std::string id, std::string nome, std::string sobrenome, std::string nome_do_meio, std::string tipo_de_usuario);
	~Usuario();
	std::string getId();
	void setId(std::string Id);
	std::string getNome();
	void setNome(std::string Nome);
	std::string getSobrenome();
	void setSobrenome(std::string Sobrenome);
	std::string getNomeDoMeio();
	void setNomeDoMeio(std::string Nome_do_meio);
	std::string getTipoDeUsuario();
	void setTipoDeUsuario(std::string Tipo_de_usuario);
	// getReserva
	// setReserva
	// getFoto
	// setFoto
	void cadastrar();
  // lida com escolha do parâmetro a ser atualizado em LINF::editaUsuario
	void alteraParametro(std::string atributo, std::string parametro);
	// Tem permissão?
	// Novas fotos
	// Editar Cadastro
};

#endif
