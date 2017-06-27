/*! @file Reserva.cpp
 *  @brief Implementação da classe Reserva
 */

#include "Reserva.hpp"

Reserva::Reserva() {}

Reserva::~Reserva() {}

void Reserva::setIdCriador(std::string Id_criador) {
  id_criador = Id_criador;
}

std::string Reserva::getIdCriador() {
  return id_criador;
}

void Reserva::setProposito(std::string Proposito) {
  proposito = Proposito;
}

std::string Reserva::getProposito() {
  return proposito;
}

void Reserva::setNumeroSalas(std::string Numero_salas) {
  numero_salas = Numero_salas;
}

std::string Reserva::getNumeroSalas() {
  return numero_salas;
}

void Reserva::setHorarioInicio(std::string Horario_inicio) {
  horario_inicio = Horario_inicio;
}

std::string Reserva::getHorarioInicio() {
  return horario_inicio;
}

void Reserva::setHorarioFim(std::string Horario_fim) {
  horario_fim = Horario_fim;
}

std::string Reserva::getHorarioFim() {
  return horario_fim;
}

void Reserva::setRecorrente(bool Recorrente) {
  recorrente = Recorrente;
}

bool Reserva::getRecorrente() {
  return recorrente;
}

void Reserva::setDiasRecorrentes(std::string Dias_recorrentes) {
  dias_recorrentes = Dias_recorrentes;
}

std::string Reserva::getDiasRecorrentes() {
  return dias_recorrentes;
}

void Reserva::setDataInicio(std::string Data_inicio) {
  data_inicio = Data_inicio;
}

std::string Reserva::getDataInicio() {
  return data_inicio;
}

void Reserva::setDataFim(std::string Data_fim) {
  data_fim = Data_fim;
}

std::string Reserva::getDataFim() {
  return data_fim;
}

std::vector<Usuario> Reserva::getParticipantes() {
  return participantes;
}

void Reserva::cadastrar() {
  std::string input;

	system("clear");

	std::cout << "Informe o id do usuário criador da reserva: ";
	std::cin >> id_criador;

	std::cout << "Informe o propósito da reserva (se for uma disciplina, informe também seu código e sua turma): ";
  getchar();
	getline(std::cin, proposito);

	std::cout << "Informe os números das salas a serem usadas: ";
	getline(std::cin, numero_salas);

  std::cout << "Informe o horário de início da reserva (24h): ";
  std::cin >> horario_inicio;

  std::cout << "Informe o horário de término da reserva (24h): ";
  std::cin >> horario_fim;

  std::cout << "Informe se a reserva é recorrente (sim ou não): ";
  std::cin >> input;

  if(input == "sim" || input == "Sim") {
    recorrente = true;

    std::cout << "Informe os dias recorrentes da reserva: ";
    getchar();
    getline(std::cin, dias_recorrentes);

    std::cout << "Informe o dia de início da reserva (dd/mm/aa): ";
    std::cin >> data_inicio;

    std::cout << "Informe o dia de término da reserva (dd/mm/aa): ";
    std::cin >> data_fim;
  }
  else {
    recorrente = false;

    std::cout << "Informe o dia da reserva (dd/mm/aa): ";
    std::cin >> data_inicio;
    data_fim = data_inicio;
  }
}

void Reserva::addParticipante(Usuario usuario) {
  participantes.push_back(usuario);
}

int Reserva::getParticipante(std::string id) {
  unsigned int i=0;

  while( (i < participantes.size()) && (participantes.at(i).getId() != id) ) {
    i++;
  }
  if(i == participantes.size())
    return -1;
  else
    return i;
}

Usuario Reserva::getParticipante(int i) {
  return participantes[i];
}
