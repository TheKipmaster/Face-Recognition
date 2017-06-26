#ifndef _LINF_HPP_
#define _LINF_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "Usuario.hpp"
#include "Reserva.hpp"

class LINF {

private:
  std::vector<Usuario> cadastros_de_usuarios;
  std::vector<Reserva> cadastros_de_reservas;

public:
  LINF();
  ~LINF();
  std::vector<Usuario> getUsuarios();
  std::vector<Reserva> getReservas();

  // insere um novo usuário no vector de usuários
  void salvarUsuario(Usuario usuario);
  // busca no banco baseado no número de identificação dele
  int buscaUsuario();
  // Retorna o número de usuários cadastrados
  int usuariosCadastrados();
  // lista todo usuário salvo
  void indexUsuario();
  // retorna o usuário com o id indicado, se houver
  int getUsuario(std::string id);
  Usuario getUsuario(int i);
  // edita um ítem do cadastro do usuário com o id indicado
  void editaUsuario();

  // insere uma nova reserva no vector de reservas
  void salvarReserva(Reserva reserva);
  // void buscarReserva();
  void indexReserva();
  Reserva indexReserva(int i);
  void manejarEntrada();
};

#endif
