/*! @file Reserva.hpp
 *  @brief Definição da classe Reserva
 */

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
  std::string numero_salas; ///< número de cada sala reservada
  std::string horario_inicio;
  std::string horario_fim;
  bool recorrente; ///< diz se a reserva se repete ou não
  std::string dias_recorrentes; ///< diz em quais dias a reserva se repete
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

  void setRecorrente(bool Recorrente);
  bool getRecorrente();

  void setDiasRecorrentes(std::string Dias_recorrentes);
  std::string getDiasRecorrentes();

  void setDataInicio(std::string Data_inicio);
  std::string getDataInicio();

  void setDataFim(std::string Data_fim);
  std::string getDataFim();

  std::vector<Usuario> getParticipantes();
  /// método para adicionar ítens no vector participantes
  void addParticipante(Usuario usuario);
  Usuario removeParticipantes(std::string);

  int getParticipante(std::string id);
  Usuario getParticipante(int i);

  void cadastrar();

};

#endif
