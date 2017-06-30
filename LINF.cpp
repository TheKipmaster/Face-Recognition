/*! @file LINF.cpp
 *  @brief Implementação da classe LINF
 */

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

std::ostream& operator << (std::ostream& os, std::vector<Usuario> u) {
  unsigned int i;

  for(i=0; i<u.size(); i++) {
    os << u.at(i).getId() << " ";
  }
  return os;
}

std::ostream& operator << (std::ostream& os, Reserva& r) {
  os << "Reserva agendada por: " << r.getIdCriador() << std::endl;
  os << "Propósito da reserva: " << r.getProposito() << std::endl;
  os << "Salas ocupadas pela reserva: " << r.getNumeroSalas() << std::endl;
  if(r.getRecorrente()) {
    os << "Reserva ativa todo(a) " << r.getDiasRecorrentes() << ", das ";
    os << r.getHorarioInicio() << " ás " << r.getHorarioFim() << ", a partir do dia ";
    os << r.getDataInicio() << " e terminando no dia " << r.getDataFim() << std::endl;
  }
  else {
    os << "Reserva ativa das " << r.getHorarioInicio() << " ás " << r.getHorarioFim();
    os << " do dia " << r.getDataInicio() << std::endl;
  }
  os << "Números de identificação dos participantes: ";
  os << r.getParticipantes() << std::endl;
  return os;
}

LINF::LINF() {}
LINF::~LINF() {}

std::vector<Usuario>* LINF::getUsuarios() {
  return &cadastros_de_usuarios;
}

std::vector<Reserva> LINF::getReservas() {
  return cadastros_de_reservas;
}

void LINF::salvarUsuario(Usuario usuario) {
  cadastros_de_usuarios.push_back(usuario);
}

void LINF::cadastrarUsuario() {
  Usuario usuario;
  std::string input;

	system("clear");

	std::cout << "Informe o tipo do usuário: ";
  getchar();
  getline(std::cin, input);
  usuario.setTipoDeUsuario(input);

	std::cout << "Informe o nome do " << usuario.getTipoDeUsuario() << ": ";
	getline(std::cin, input);
  usuario.setNome(input);

	std::cout << "Informe o sobrenome do " << usuario.getTipoDeUsuario() << ": ";
	getline(std::cin, input);
  usuario.setSobrenome(input);

	std::cout << "Informe o nome do meio do " << usuario.getTipoDeUsuario() << ": ";
	getline(std::cin, input);
  usuario.setNomeDoMeio(input);

	std::cout << "Informe o id do " << usuario.getTipoDeUsuario() << ": ";
  getline(std::cin, input);
  usuario.setId(input);

  salvarUsuario(usuario);
}

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

int LINF::buscaUsuario() {
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
  return posicao_usuario;
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

void LINF::editaUsuario() {
  std::string atributo, parametro, id;
  int posicao_usuario;

  posicao_usuario = buscaUsuario();
  if(posicao_usuario != -1) {
    std::cout << "Informe o parâmetro a ser modificado: ";
    std::cin >> atributo;
    std::cout << "Informe o novo valor de " << atributo << ": ";
    std::cin >> parametro;
    cadastros_de_usuarios.at(posicao_usuario).alteraParametro(atributo, parametro);
    std::cout << cadastros_de_usuarios.at(posicao_usuario);
    getchar();
    getchar();
  }
}

void LINF::salvarReserva(Reserva reserva) {
  cadastros_de_reservas.push_back(reserva);
}

void LINF::indexReserva() {
  unsigned int i;

  system("clear");

  std::cout << "--- LISTA DE RESERVAS AGENDADAS ---" << std::endl << std::endl;
  for(i = 0; i < cadastros_de_reservas.size(); i++) {
    std::cout << cadastros_de_reservas.at(i) << std::endl;
  }
  getchar();
  getchar();
}

void LINF::indexReserva(std::vector<Reserva> arr) {
  unsigned int i;

  system("clear");

  std::cout << "--- LISTA DE RESERVAS AGENDADAS ---" << std::endl << std::endl;
  for(i = 0; i < arr.size(); i++) {
    std::cout << arr.at(i) << std::endl;
  }
  getchar();
  getchar();
}

Reserva LINF::indexReserva(int i) {
  return cadastros_de_reservas.at(i);
}

void LINF::manejarEntrada() {
  std::string input;
  int posicao_usuario, posicao_reserva;
  unsigned int i;

  do {
    posicao_usuario = buscaUsuario();
    if(posicao_usuario != -1) {
      std::cout << "Este é o usuário que estava procurando? (S/N) ";
      std::cin >> input;
    }
    else
      return;
  }while(input != "S" && input != "s");

  std::cout << "Este usuário está cadastrado como participante das seguintes reservas: " << std::endl << std::endl;
  for(i=0; i<cadastros_de_usuarios.at(posicao_usuario).getPosicoesReservas().size(); i++) {
    posicao_reserva = cadastros_de_usuarios.at(posicao_usuario).getPosicoesReservas().at(i);
    std::cout << cadastros_de_reservas.at(posicao_reserva) << std::endl;
  }
  getchar();
  getchar();

}
