#ifndef _LINF_HPP_
#define _LINF_HPP_

#include <vector>
#include <string>
#include "Usuario.hpp"
#include "Reserva.hpp"

class LINF {

private:
  std::vector<Usuario> cadastros_de_usuarios;
  std::vector<Reserva> cadastros_de_reserva;

public:
  LINF();
  ~LINF();
  // insere um novo usuário no vector de usuários
  void salvarUsuario(Usuario usuario);
  // busca no banco baseado no número de identificação dele
  int buscaUsuario();
  // lista todo usuário salvo
  void indexUsuario();
  // retorna o usuário com o id indicado, se houver
  int getUsuario(std::string id);
  // edita um ítem do cadastro do usuário com o id indicado
  void editaUsuario();

  // insere uma nova reserva no vector de reservas
  void salvarReserva(Reserva reserva);
  // void buscarReserva();
  // void indexReserva();
};

#endif
