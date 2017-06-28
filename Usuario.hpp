/*! @file Usuario.hpp
 *  @brief Definição da classe Usuario
 */

#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <vector>
#include <iostream>

class Usuario {

private:
	std::string id; ///< matrícula, caso o usuário seja do tipo 'professor' ou 'aluno' e CPF caso contrário
	std::string nome;
	std::string sobrenome;
	std::string nome_do_meio;
	std::vector<int> posicoes_reservas; ///< cada número representa a posição de uma reserva no vector 'cadastros_de_reservas' da classe 'LINF'
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

	/// retorna o vector inteiro com as posições das reservas das quais o usuário participa
	std::vector<int> getPosicoesReservas();
	/// método para adicionar ítens no vector posicoes_reservas
	void participarReserva(int posicao_reserva);

	std::string getTipoDeUsuario();
	void setTipoDeUsuario(std::string Tipo_de_usuario);
	// getReserva
	// setReserva
	// getFoto
	// setFoto
  /// lida com escolha do parâmetro a ser atualizado em LINF::editaUsuario
	void alteraParametro(std::string atributo, std::string parametro);
	// Novas fotos
	// Editar Cadastro
};

#endif
