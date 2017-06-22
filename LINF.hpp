#ifndef _LINF_HPP_
#define _LINF_HPP_

#include <vector>
#include <string>
#include <fstream>
#include <jsoncpp/json/json.h>
#include "Usuario.hpp"

class LINF {

private:
  std::vector<Usuario> cadastros_de_usuarios;
  // std::vector<Reserva> cadastros_de_reserva;

public:
  LINF();
  ~LINF();
  void salvarUsuario(Usuario usuario);
  int usuariosCadastrados();
  // implementar busca direito
  void indexUsuario();
  // void indexReserva();
  Usuario getUsuario();
  Usuario getUsuario(int i);
  // salvarReserva();
  // buscarReserva();
};

#endif
