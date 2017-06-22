#include "LINF.hpp"

std::ostream& operator << (std::ostream& os, Usuario& u) {
  os << "Tipo: \t\t" << u.getTipoDeUsuario() << std::endl;
  if(!u.getTipoDeUsuario().compare("aluno")) {
    os << "Matricula: \t" << u.getId() << std::endl;
  }
  os << "Nome: \t\t" << u.getNome() << std::endl;
  os << "Nome do Meio: \t" << u.getNomeDoMeio() << std::endl;
  os << "Sobrenome: \t" << u.getSobrenome() << std::endl;
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

Usuario LINF::getUsuario(int i) {
  return cadastros_de_usuarios.at(i);
}

int LINF::usuariosCadastrados(){
  return cadastros_de_usuarios.size(); 
}

void LINF::indexUsuario() {
  unsigned int i;

  system("clear");

  std::cout << "--- LISTA DE CADASTROS DE USÁRIOS ---" << std::endl << std::endl;
  for(i = 0; i < cadastros_de_usuarios.size(); i++) {
    std::cout << cadastros_de_usuarios.at(i) << std::endl;
  }
  getchar();
  getchar();
}
