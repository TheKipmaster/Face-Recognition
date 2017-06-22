#include <iostream>
#include "Usuario.hpp"
#include "Reserva.hpp"
#include "LINF.hpp"

void addParticipantes(Reserva *reserva, LINF linf) {
  std::string input;
  int posicao_usuario;

  std::cout << "(pressione <ENTER> após cada entrada | digite 'sair' para terminar)" << std::endl;
  do {
    std::cout << "Informe o número de identificação dos participantes da reserva: ";
    std::cin >> input;

    if(input != "sair" && input != "Sair") {
      posicao_usuario = linf.getUsuario(input);
      reserva->addParticipante(linf.getUsuarios().at(posicao_usuario));
    }
  }while(input != "sair" && input != "Sair");
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

  drawMenu(&n);
  while(n != 5) {
    if(n == 1) {
      Usuario usuario;
      usuario.cadastrar();
      linf.salvarUsuario(usuario);
      drawMenu(&n);
    }
    else if(n == 2) {
      Reserva reserva;
      reserva.cadastrar();
      addParticipantes(&reserva, linf);
      linf.salvarReserva(reserva);
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
      // linf.manejarEntrada();
      drawMenu(&n);
    }
  }

  return 0;
}
