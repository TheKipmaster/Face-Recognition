#include "Reserva.hpp"

Reserva::Reserva() {}

Reserva::~Reserva() {}

void Reserva::setCriador(std::string Criador) {
  criador = Criador;
}

void Reserva::getCriador() {
  return criador;
}

void Reserva::setProposito(std::string Proposito) {
  proposito = Proposito;
}

void Reserva::getProposito() {
  return proposito;
}

void Reserva::setHorarioInicio(std::string Horario_inicio) {
  horario_inicio = Horario_inicio;
}

void Reserva::getHorarioInicio() {
  return horario_inicio;
}

void Reserva::setHorarioFim(std::string Horario_fim) {
  horario_fim = Horario_fim;
}

void Reserva::getHorarioFim() {
  return horario_fim;
}

void Reserva::setDataInicio(std::string Data_inicio) {
  data_inicio = Data_inicio;
}

void Reserva::getDataInicio() {
  return data_inicio;
}

void Reserva::setDataFim(std::string Data_fim) {
  data_fim = Data_fim;
}

void Reserva::getDataFim() {
  return data_fim;
}
