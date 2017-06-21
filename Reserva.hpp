#ifndef _RESERVATION_HPP_
#define _RESERVATION_HPP_

#include <string>
#include <vector>
#include <iostream>
#include "Usuario.hpp"

class Reserva {

private:
  Usuario criador;
  std::string propósito;
  std::vector<int> numero_salas;
  std::string horario_inicio;
  std::string horario_fim;
  std::string data_inicio;
  std::string data_fim;
  std::vector<Usuario> participantes;

public:
  Reserva();
  ~Reserva();
  // void cadastrar();

};

#endif
