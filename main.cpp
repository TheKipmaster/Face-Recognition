#include <iostream>

int drawMenu (int *n) {

  system("clear");
  std::cout << "\tOpa, tudo bom? Bem vindo ao LINF" << std::endl << std::endl;
  std::cout << "1 - Novo Cadastro" << std::endl;
  std::cout << "2 - Nova Reserva" << std::endl;
  std::cout << "3 - Check DB" << std::endl;
  std::cout << "4 - A porta é ali, senhor" << std::endl;
	do {
		std::cin >> *n;
		if ( (*n > 4) || (*n < 1) )
			std::cout << "Tu é burro cara?" << std::endl;
	} while ( (*n > 5) || (*n < 1) );

	return *n;
}

int main() {
  int n;

  drawMenu(&n);
  while(n != 4) {
    if(n == 1) {
      drawMenu(&n);
    }
    else if(n == 2) {
      drawMenu(&n);
    }
    else if(n == 3) {
      drawMenu(&n);
    }
    else if(n == 4) {
      drawMenu(&n);
    }
  }

  return 0;
}
