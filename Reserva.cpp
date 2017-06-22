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
