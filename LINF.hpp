#ifndef _LINF_HPP_
#define _LINF_HPP_

#include <vector>
#include <string>
#include "Usuario.hpp"

class LINF {

private:
  std::vector<Usuario> cadastros_de_usuarios;
  // std::vector<Reserva> cadastros_de_reserva;

public:
  LINF();
  ~LINF();
  void salvarUsuario(Usuario usuario);
  // implementar busca direito
  void indexUsuario();
  // void indexReserva();
  // busca no banco baseado no número de identificação dele
  void buscaUsuario();
  Usuario getUsuario(std::string id);
  // salvarReserva();
  // buscarReserva();
};

#endif
