#include <iostream>
#include "Usuario.hpp"
#include "LINF.hpp"

void loadUsers(LINF *linf) {
  Usuario usuario;
  std::ifstream ifs("bd.json");
  Json::Reader reader;
  Json::Value obj;
  reader.parse(ifs, obj); // reader can also read strings
  const Json::Value& usuarios = obj["usuarios"]; // array of characters
  for (unsigned int i = 0; i < usuarios.size(); i++){
    usuario.setId(usuarios[i]["id"].asString());
    usuario.setNome(usuarios[i]["nome"].asString());
    usuario.setNomeDoMeio(usuarios[i]["nome_do_meio"].asString());
    usuario.setSobrenome(usuarios[i]["sobrenome"].asString());
    usuario.setTipoDeUsuario(usuarios[i]["tipo"].asString());
    linf->salvarUsuario(usuario);
  }
}

void saveRecords(LINF *linf) {
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
  fs.open ("bd.json", std::fstream::in | std::fstream::out);
  
  fs << usuarios;

  fs.close();
}

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

int drawMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "4 - Sair" << std::endl;
	do {
		std::cin >> *n;
		if ( (*n > 4) || (*n < 1) )
			std::cout << "Entrada inválida" << std::endl;
	} while ( (*n > 4) || (*n < 1) );

	return *n;
}

int main() {
  int n;
  LINF linf;
  loadUsers(&linf);
  drawMenu(&n);
  while(n != 4) {
    if(n == 1) {
      Usuario usuario;
      usuario.cadastrar();
      linf.salvarUsuario(usuario);
      drawMenu(&n);
    }
    else if(n == 2) {
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
          // indexReserva();
          drawSubMenu(&n);
        }
      }
      drawMenu(&n);
    }
    saveRecords(&linf);
  }

  return 0;
}
