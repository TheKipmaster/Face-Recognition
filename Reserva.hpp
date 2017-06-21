#ifndef _RESERVATION_HPP_
#define _RESERVATION_HPP_

#include <string>
#include <vector>
#include <iostream>
#include "Usuario.hpp"

class Reserva {

private:
  Usuario criador;
  std::string proposito;
  std::vector<int> numero_salas;
  std::string horario_inicio;
  std::string horario_fim;
  std::string data_inicio;
  std::string data_fim;
  std::vector<Usuario> participantes;

public:
  Reserva();
  ~Reserva();
  void setCriador(Usuario Criador);
  Usuario getCriador();

  void setProposito(std::string Proposito);
  std::string getProposito();

  void setHorarioInicio(std::string Horario_inicio);
  std::string getHorarioInicio();

  void setHorarioFim(std::string Horario_fim);
  std::string getHorarioFim();

  void setDataInicio(std::string Data_inicio);
  std::string getDataInicio();

  void setDataFim(std::string Data_fim);
  std::string getDataFim();
  // void cadastrar();

};

#endif
