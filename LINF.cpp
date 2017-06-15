#include "LINF.hpp"

LINF::LINF() {}
LINF::~LINF() {}

void LINF::salvarUsuario(Usuario usuario) {
  cadastros_de_usuarios.push_back(usuario);
}

Usuario LINF::getUsuario() {
  return cadastros_de_usuarios.at(0);
}
