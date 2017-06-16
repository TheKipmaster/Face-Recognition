#include "LINF.hpp"

std::ostream& operator << (std::ostream& os, Usuario& u) {
  os << u.getNome() << std::endl;
  return os;
}

LINF::LINF() {}
LINF::~LINF() {}

void LINF::salvarUsuario(Usuario usuario) {
  cadastros_de_usuarios.push_back(usuario);
}

// implementar busca direito
Usuario LINF::getUsuario() {
  return cadastros_de_usuarios.at(0);
}

void LINF::indexUsuario() {
  unsigned int i;

  system("clear");

  for(i = 0; i < cadastros_de_usuarios.size(); i++) {
    std::cout << cadastros_de_usuarios.at(i) << std::endl;
  }
  getchar();
  getchar();
}
