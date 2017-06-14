#include "Usuario.hpp"

Usuario::Usuario(std::string Id, std::string Nome, std::string Sobrenome, 
								 std::string Nome_do_meio, std::string Tipo_de_usuario): 
id(Id), nome(Nome), sobrenome(Sobrenome), nome_do_meio(Nome_do_meio), 
tipo_de_usuario(Tipo_de_usuario) {}

Usuario::~Usuario() {}
