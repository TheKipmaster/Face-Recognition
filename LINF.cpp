#include "LINF.hpp"

std::ostream& operator << (std::ostream& os, Usuario& u) {
  os << "Tipo: \t\t" << u.getTipoDeUsuario() << std::endl;
  if(u.getTipoDeUsuario() == "aluno" || u.getTipoDeUsuario() == "professor")
    os << "Matricula: \t";
  else
    os << "CPF: \t\t";
  os << u.getId() << std::endl;
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
int LINF::getUsuario(std::string id) {
  unsigned int i=0;
  // Usuario u;

  while( (i < cadastros_de_usuarios.size()) && (cadastros_de_usuarios.at(i).getId() != id) ) {
    i++;
  }
  if(i == cadastros_de_usuarios.size())
    return -1;
  else
    return i;
}

void LINF::buscaUsuario() {
  std::string input;
  int posicao_usuario;

  system("clear");
  std::cout << "Informe o número de identificação do usuário: ";
  std::cin >> input;
  posicao_usuario = getUsuario(input);
  if(posicao_usuario == -1)
    std::cout << "USUÁRIO NÃO ENCONTRADO" << std::endl;
  else
    std::cout << cadastros_de_usuarios.at(posicao_usuario);
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

void LINF::editaUsuario() {
  std::string atributo, parametro, id;
  int posicao_usuario;

  system("clear");
  std::cout << "Informe o número de identificação do usuário: ";
  std::cin >> id;
  posicao_usuario = getUsuario(id);
  if(posicao_usuario == -1)
    std::cout << "USUÁRIO NÃO ENCONTRADO" << std::endl;
  else {
    std::cout << cadastros_de_usuarios.at(posicao_usuario);
    std::cout << "Informe o parâmetro a ser modificado: ";
    std::cin >> atributo;
    std::cout << "Informe o novo valor de " << atributo << ": ";
    std::cin >> parametro;
    cadastros_de_usuarios.at(posicao_usuario).alteraParametro(atributo, parametro);
    std::cout << cadastros_de_usuarios.at(posicao_usuario);
  }
  getchar();
  getchar();

}
