#ifndef _RESERVATION_HPP_
#define _RESERVATION_HPP_

#include <string>
#include <vector>
#include <iostream>
#include "Usuario.hpp"

class Reserva {

private:
  std::string id_criador;
  std::string proposito;
  std::string numero_salas;
  std::string horario_inicio;
  std::string horario_fim;
  std::string data_inicio;
  std::string data_fim;
  std::vector<Usuario> participantes;

public:
  Reserva();
  ~Reserva();
  void setIdCriador(std::string Id_criador);
  std::string getIdCriador();

  void setProposito(std::string Proposito);
  std::string getProposito();

  void setNumeroSalas(std::string Numero_salas);
  std::string getNumeroSalas();

  void setHorarioInicio(std::string Horario_inicio);
  std::string getHorarioInicio();

  void setHorarioFim(std::string Horario_fim);
  std::string getHorarioFim();

  void setDataInicio(std::string Data_inicio);
  std::string getDataInicio();

  void setDataFim(std::string Data_fim);
  std::string getDataFim();

  void cadastrar();

};

#endif
