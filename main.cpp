/*! @file main.hpp
 *  @brief Implementação do loop principal e de funções de integração
 */

#include <iostream>
#include "Usuario.hpp"
#include "Reserva.hpp"
#include "LINF.hpp"

void loadUsuarios(LINF *linf) {
  std::ifstream ifs("usuarios.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); // reader can also read strings
  const Json::Value& usuarios = obj["usuarios"]; // array of characters
  for (unsigned int i = 0; i < usuarios.size(); i++){
    Usuario usuario;
    usuario.setId(usuarios[i]["id"].asString());
    usuario.setNome(usuarios[i]["nome"].asString());
    usuario.setNomeDoMeio(usuarios[i]["nome_do_meio"].asString());
    usuario.setSobrenome(usuarios[i]["sobrenome"].asString());
    usuario.setTipoDeUsuario(usuarios[i]["tipo"].asString());
    linf->salvarUsuario(usuario);
  }
}

void loadReservas(LINF *linf) {
  std::ifstream ifs("reservas.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); // reader can also read strings
  const Json::Value& reservas = obj["reservas"];
  for (unsigned int i = 0; i < reservas.size(); i++){
    Reserva reserva;
    reserva.setIdCriador(reservas[i]["id_criador"].asString());
    reserva.setProposito(reservas[i]["proposito"].asString());
    reserva.setNumeroSalas(reservas[i]["numero_salas"].asString());
    reserva.setHorarioInicio(reservas[i]["horario_inicio"].asString());
    reserva.setHorarioFim(reservas[i]["horario_fim"].asString());
    reserva.setRecorrente(reservas[i]["recorrente"].asBool());
    reserva.setDiasRecorrentes(reservas[i]["dias_recorrentes"].asString());
    reserva.setDataInicio(reservas[i]["data_inicio"].asString());
    reserva.setDataFim(reservas[i]["data_fim"].asString());
    for (unsigned int j = 0; j < reservas[i]["participantes"].size(); j++){
      Usuario usuario;
      usuario.setId(reservas[i]["participantes"][j]["id"].asString());
      usuario.setNome(reservas[i]["participantes"][j]["nome"].asString());
      usuario.setNomeDoMeio(reservas[i]["participantes"][j]["nome_do_meio"].asString());
      usuario.setSobrenome(reservas[i]["participantes"][j]["sobrenome"].asString());
      usuario.setTipoDeUsuario(reservas[i]["participantes"][j]["tipo"].asString());
      reserva.addParticipante(usuario);
    }
    linf->salvarReserva(reserva);
  }

}

void saveUsuarios(LINF *linf) {
  int i;
  Json::Value usuarios;
  Json::Value usuario;
  Json::Value vec(Json::arrayValue);
  for(i=0;i < linf->usuariosCadastrados();i++){
    usuario["id"] = linf->getUsuario(i).getId();
    usuario["nome"] = linf->getUsuario(i).getNome();
    usuario["nome_do_meio"] = linf->getUsuario(i).getNomeDoMeio();
    usuario["sobrenome"] = linf->getUsuario(i).getSobrenome();
    usuario["tipo"] = linf->getUsuario(i).getTipoDeUsuario();
    vec.append(Json::Value(usuario));
    usuarios["usuarios"]=vec;
  }
  std::fstream fs;
  fs.open ("usuarios.json", std::fstream::in | std::fstream::out);

  fs << usuarios;

  fs.close();
}

void saveReservas(LINF *linf) {

  unsigned int i, j;
  Json::Value reservas;
  Json::Value reserva;
  Json::Value usuario;
  Json::Value vec(Json::arrayValue);

  for(i=0;i < linf->getReservas().size();i++){
    Json::Value vec1(Json::arrayValue);
    reserva["id_criador"] = linf->indexReserva(i).getIdCriador();
    reserva["proposito"] = linf->indexReserva(i).getProposito();
    reserva["numero_salas"] = linf->indexReserva(i).getNumeroSalas();
    reserva["horario_inicio"] = linf->indexReserva(i).getHorarioInicio();
    reserva["horario_fim"] = linf->indexReserva(i).getHorarioFim();
    reserva["recorrente"] = linf->indexReserva(i).getRecorrente();
    reserva["dias_recorrentes"] = linf->indexReserva(i).getDiasRecorrentes();
    reserva["data_inicio"] = linf->indexReserva(i).getDataInicio();
    reserva["data_fim"] = linf->indexReserva(i).getDataFim();

    for(j=0; j < linf->indexReserva(i).getParticipantes().size(); j++){
      usuario["id"] =  linf->indexReserva(i).getParticipante(j).getId();
      usuario["nome"] = linf->indexReserva(i).getParticipante(j).getNome();
      usuario["nome_do_meio"] = linf->indexReserva(i).getParticipante(j).getNomeDoMeio();
      usuario["sobrenome"] = linf->indexReserva(i).getParticipante(j).getSobrenome();
      usuario["tipo"] = linf->indexReserva(i).getParticipante(j).getTipoDeUsuario();
      vec1.append(Json::Value(usuario));
      reserva["participantes"] = vec1;
    }

    vec.append(Json::Value(reserva));
    reservas["reservas"]= vec;
  }

  std::fstream fs;
  fs.open ("reservas.json", std::fstream::in | std::fstream::out);

  fs << reservas;

  fs.close();
}

/// relaciona uma reserva com os usuários indicados e vice-versa
void addParticipantes(Reserva *reserva, LINF *linf) {
  std::string input;
  int posicao_usuario;

  std::cout << "(pressione <ENTER> após cada entrada | digite 'sair' para terminar)" << std::endl;
  do {
    std::cout << "Informe o número de identificação dos participantes da reserva: ";
    std::cin >> input;

    if(input != "sair" && input != "Sair") {
      posicao_usuario = linf->getUsuario(input);
      reserva->addParticipante(linf->getUsuarios()->at(posicao_usuario));
      linf->getUsuarios()->at(posicao_usuario).participarReserva(linf->getReservas().size());
    }
  }while(input != "sair" && input != "Sair");
}

/// desenha o menu principal na tela
int drawSubMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "\t3.1 - Index de Usuários" << std::endl;
  std::cout << "\t3.2 - Busca de Usuários" << std::endl;
  std::cout << "\t3.3 - Editar Usuários" << std::endl;
  std::cout << "\t3.4 - Index de Reservas" << std::endl;
  std::cout << "\t3.5 - Voltar" << std::endl << "\t";
	do {
		std::cin >> *n;
		if ( (*n > 5) || (*n < 1) )
			std::cout << "\tEntrada inválida" << std::endl << "\t";
	} while ( (*n > 5) || (*n < 1) );

	return *n;
}

/// desenha o menu secundário criado pela opção três do menu principal
int drawMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "4 - Solicitar Permissão" << std::endl;
  std::cout << "5 - Sair" << std::endl;
	do {
		std::cin >> *n;
		if ( (*n > 5) || (*n < 1) )
			std::cout << "Entrada inválida" << std::endl;
	} while ( (*n > 5) || (*n < 1) );

	return *n;
}

int main() {
  int n;
  LINF linf;
  loadUsuarios(&linf);
  loadReservas(&linf);

  drawMenu(&n);
  while(n != 5) {
    if(n == 1) {
      Usuario usuario;
      usuario.cadastrar();
      linf.salvarUsuario(usuario);
      saveUsuarios(&linf);
      drawMenu(&n);
    }
    else if(n == 2) {
      Reserva reserva;
      reserva.cadastrar();
      addParticipantes(&reserva, &linf);
      linf.salvarReserva(reserva);
      saveReservas(&linf);
      drawMenu(&n);
    }
    else if(n == 3) {
      drawSubMenu(&n);
      while(n != 5) {
        if(n == 1) {
          linf.indexUsuario();
          drawSubMenu(&n);
        }
        else if(n == 2) {
          linf.buscaUsuario();
          drawSubMenu(&n);
        }
        else if(n == 3) {
          linf.editaUsuario();
          drawSubMenu(&n);
        }
        else if(n == 4) {
          linf.indexReserva();
          drawSubMenu(&n);
        }
      }
      drawMenu(&n);
    }
    else if(n == 4) {
      linf.manejarEntrada();
      drawMenu(&n);
    }
  }

  return 0;
}
