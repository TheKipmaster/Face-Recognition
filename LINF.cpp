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
Usuario LINF::getUsuario(std::string id) {
  unsigned int i=0;
  Usuario u;

  while( (i < cadastros_de_usuarios.size()) && (cadastros_de_usuarios.at(i).getId().compare(id) != 0) ) {
    i++;
    if(cadastros_de_usuarios.at(i).getId().compare(id))
      return cadastros_de_usuarios.at(i);
  }
  return u;
}

void LINF::buscaUsuario() {
  std::string input;
  Usuario usuario;

  system("clear");
  std::cout << "Informe o número de identificação do usuário: ";
  std::cin >> input;
  usuario = getUsuario(input);
  if(usuario.getId().empty())
    std::cout << "USUÁRIO NÃO ENCONTRADO" << std::endl;
  else
    std::cout << usuario;
  getchar();
  getchar();
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
